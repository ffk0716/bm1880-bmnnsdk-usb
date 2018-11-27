#ifndef CAFFE2_OPERATORS_EXPAND_SQUEEZE_DIMS_OP_H_
#define CAFFE2_OPERATORS_EXPAND_SQUEEZE_DIMS_OP_H_

#include "caffe2/core/context.h"
#include "caffe2/core/operator.h"

namespace caffe2 {

template <class Context>
class ExpandDimsOp : public Operator<Context> {
 public:
  USE_OPERATOR_CONTEXT_FUNCTIONS;
  ExpandDimsOp(const OperatorDef& operator_def, Workspace* ws)
      : Operator<Context>(operator_def, ws),
        dims_(this->template GetRepeatedArgument<int>("dims")) {
    auto originalSize = dims_.size();
    CAFFE_ENFORCE(originalSize > 0, "Parameter `dims` must be provided.");
    std::sort(dims_.begin(), dims_.end());
    dims_.erase(std::unique(dims_.begin(), dims_.end()), dims_.end());
    if (dims_.size() < originalSize) {
      LOG(WARNING) << "Parameter `dims` has repeated dimensions.";
    }
    CAFFE_ENFORCE(dims_.front() >= 0, "Dimension ids must be non-negative.");
  }

  bool RunOnDevice() override {
    auto& input = Input(0);
    auto* output = Output(0);
    output->CopyFrom(input, &context_);
    if (dims_.empty()) {
      return true;
    }

    auto newDims = input.dims();
    CAFFE_ENFORCE_GE(
        input.dims().size() + dims_.size(),
        dims_.back() + 1,
        "Input needs at least ",
        (1 + dims_.back() - dims_.size()),
        " dimensions given `dims`.");
    for (const auto dim : dims_) {
      newDims.insert(newDims.begin() + dim, 1);
    }
    output->Reshape(newDims);
    return true;
  }

 private:
  vector<int> dims_;
};

template <class Context>
class SqueezeOp : public Operator<Context> {
 public:
  USE_OPERATOR_CONTEXT_FUNCTIONS;
  SqueezeOp(const OperatorDef& operator_def, Workspace* ws)
      : Operator<Context>(operator_def, ws),
        dims_(this->template GetRepeatedArgument<int>("dims")) {
    auto originalSize = dims_.size();
    CAFFE_ENFORCE(originalSize > 0, "Parameter `dims` must be provided.");

    std::sort(dims_.begin(), dims_.end());
    dims_.erase(std::unique(dims_.begin(), dims_.end()), dims_.end());
    if (dims_.size() < originalSize) {
      LOG(WARNING) << "Parameter `dims` has repeated dimensions.";
    }
    CAFFE_ENFORCE(dims_.front() >= 0, "Dimension ids must be non-negative.");
  }

  bool RunOnDevice() override {
    auto& input = Input(0);
    auto* output = Output(0);
    output->CopyFrom(input, &context_);

    CAFFE_ENFORCE_GT(
        input.ndim(),
        dims_.back(),
        "Input needs at least ",
        (dims_.back() + 1),
        " dimensions.");

    std::vector<int> newDims = ComputeDims(input.dims(), dims_);
    output->Reshape(newDims);
    return true;
  }

  static std::vector<int> ComputeDims(
      std::vector<TIndex> inputDims,
      std::vector<int> dims) {
    int j = 0;
    std::vector<int> newDims;
    for (int i = 0; i < inputDims.size(); ++i) {
      if (j < dims.size() && dims[j] == i) {
        CAFFE_ENFORCE_EQ(
            inputDims[i],
            1,
            "Dimension ",
            i,
            " of input must be 1",
            " instead of ",
            inputDims[i],
            ".");
        ++j;
        continue;
      }
      newDims.push_back(inputDims.at(i));
    }
    return newDims;
  }

 private:
  vector<int> dims_;

 public:
  AT_DISABLE_COPY_AND_ASSIGN(SqueezeOp);
};
} // namespace caffe2
#endif // CAFFE2_OPERATORS_EXPAND_SQUEEZE_DIMS_OP_H_