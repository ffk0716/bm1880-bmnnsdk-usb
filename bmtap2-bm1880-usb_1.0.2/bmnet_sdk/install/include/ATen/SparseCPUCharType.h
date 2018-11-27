#pragma once

// @generated by aten/src/ATen/gen.py

#include "ATen/Type.h"
#include "ATen/Context.h"
#include "ATen/TensorMethods.h"
#include "ATen/CheckGenerator.h"

#ifdef _MSC_VER
#ifdef Type
#undef Type
#endif
#endif

namespace at {

struct SparseCPUCharType final : public Type {
  explicit SparseCPUCharType(Context* context);
  virtual ScalarType scalarType() const override;
  virtual Backend backend() const override;
  virtual bool is_cuda() const override;
  virtual bool is_sparse() const override;
  virtual bool is_distributed() const override;
  virtual Storage storage(bool resizable = false) const override;
  virtual Storage storage(size_t size, bool resizable = false) const override;
  virtual Storage storageFromBlob(void * data, int64_t size, const std::function<void(void*)> & deleter) const override;
  virtual Storage storageWithAllocator(int64_t size, Allocator* allocator) const override;
  virtual std::unique_ptr<Generator> generator() const override;
  virtual const char * toString() const override;
  virtual size_t elementSizeInBytes() const override;
  virtual TypeID ID() const override;
  static const char * typeString();
  virtual Storage unsafeStorageFromTH(void * th_pointer, bool retain) const override;
  virtual Tensor unsafeTensorFromTH(void * th_pointer, bool retain) const override;

  // example
  // virtual Tensor * add(Tensor & a, Tensor & b) override;

  virtual Tensor & s_copy_(Tensor & self, const Tensor & src, bool non_blocking) const override;
  virtual Tensor & _s_copy_from(const Tensor & self, Tensor & dst, bool non_blocking) const override;
  virtual Tensor & log1p_(Tensor & self) const override;
  virtual Tensor & log1p_out(Tensor & result, const Tensor & self) const override;
  virtual Tensor & _sparse_add_out(Tensor & result, const Tensor & self, const Tensor & other, Scalar alpha) const override;
  virtual Tensor & _sparse_div_zerodim_out(Tensor & result, const Tensor & self, const Tensor & other) const override;
  virtual Tensor & _sparse_div_scalar_out(Tensor & result, const Tensor & self, Scalar other) const override;
  virtual Tensor & _sparse_mul_out(Tensor & result, const Tensor & self, const Tensor & other) const override;
  virtual Tensor & _sparse_mul_zerodim_out(Tensor & result, const Tensor & self, const Tensor & other) const override;
  virtual Tensor & _sparse_mul_scalar_out(Tensor & result, const Tensor & self, Scalar other) const override;
  virtual Tensor & sspaddmm_out(Tensor & result, const Tensor & self, const Tensor & mat1, const Tensor & mat2, Scalar beta, Scalar alpha) const override;
  virtual Tensor native_norm(const Tensor & self, Scalar p) const override;
  virtual Tensor native_clone(const Tensor & self) const override;
  virtual Tensor & native_resize_as_(Tensor & self, const Tensor & the_template) const override;
  virtual Tensor & native_pow_out(Tensor & result, const Tensor & self, Scalar exponent) const override;
  virtual Tensor native_pow(const Tensor & self, Scalar exponent) const override;
  virtual Tensor & native_zero_(Tensor & self) const override;
  virtual Tensor native_tensor() const override;
  virtual Tensor native_tensor(IntList size) const override;
  virtual Tensor native_sparse_coo_tensor(IntList size) const override;
  virtual Tensor native_sparse_coo_tensor(const Tensor & indices, const Tensor & values) const override;
  virtual Tensor native_sparse_coo_tensor(const Tensor & indices, const Tensor & values, IntList size) const override;
  virtual Tensor _native_sparse_coo_tensor_unsafe(const Tensor & indices, const Tensor & values, IntList size) const override;
  virtual Tensor & sparse_resize_(Tensor & self, IntList size, int64_t sparseDims, int64_t denseDims) const override;
  virtual Tensor & sparse_resize_and_clear_(Tensor & self, IntList size, int64_t sparseDims, int64_t denseDims) const override;
  virtual Tensor to_dense(const Tensor & self) const override;
  virtual int64_t _sparseDims(const Tensor & self) const override;
  virtual int64_t _denseDims(const Tensor & self) const override;
  virtual int64_t _nnz(const Tensor & self) const override;
  virtual Tensor coalesce(const Tensor & self) const override;
  virtual bool is_coalesced(const Tensor & self) const override;
  virtual Tensor _indices(const Tensor & self) const override;
  virtual Tensor _values(const Tensor & self) const override;
  virtual Tensor & hspmm_out(Tensor & result, const Tensor & mat1, const Tensor & mat2) const override;
  virtual Tensor hspmm(const Tensor & mat1, const Tensor & mat2) const override;
  virtual Tensor & raw_copy_sparse_(Tensor & self, const Tensor & src) const override;
  virtual int64_t native_get_device(const Tensor & self) const override;
};

} // namespace at
