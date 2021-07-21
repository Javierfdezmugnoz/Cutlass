
/*
  Generated by gemm_operation.py - Do not edit.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
#include "cutlass/arch/wmma.h"
#include "cutlass/cutlass.h"
#include "cutlass/library/library.h"
#include "cutlass/library/manifest.h"

#include "library_internal.h"
#include "gemm_operation.h"

///////////////////////////////////////////////////////////////////////////////////////////////////


// Gemm operator cutlass_simt_dgemm_128x128_8x2_nn_align1
using cutlass_simt_dgemm_128x128_8x2_nn_align1_base = 
  typename cutlass::gemm::kernel::DefaultGemmUniversal<
    double, cutlass::layout::RowMajor, cutlass::ComplexTransform::kNone, 1,    // transposed B operand
    double, cutlass::layout::RowMajor, cutlass::ComplexTransform::kNone, 1,    // transposed A operand
    double, cutlass::layout::RowMajor,
    double,
    cutlass::arch::OpClassSimt,
    cutlass::arch::Sm50,
    cutlass::gemm::GemmShape<128, 128, 8>,
    cutlass::gemm::GemmShape<32, 64, 8>,
    cutlass::gemm::GemmShape<1, 1, 1>,
    cutlass::epilogue::thread::LinearCombination<
      double,
      1,
      double,
      double
    >,
    cutlass::gemm::threadblock::GemmIdentityThreadblockSwizzle<8>,
    2,
    cutlass::arch::OpMultiplyAdd
>::GemmKernel;

// Define named type
struct cutlass_simt_dgemm_128x128_8x2_nn_align1 : 
  public cutlass_simt_dgemm_128x128_8x2_nn_align1_base { };


///////////////////////////////////////////////////////////////////////////////////////////////////

namespace cutlass {
namespace library {

///////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_cutlass_simt_dgemm_128x128_8x2_nn_align1(Manifest &manifest) {



  manifest.append(new GemmUniversalOperation<
      cutlass::gemm::device::GemmUniversalAdapter<cutlass_simt_dgemm_128x128_8x2_nn_align1>
    >("cutlass_simt_dgemm_128x128_8x2_nn_align1"));



}

///////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace library
} // namespace cutlass

///////////////////////////////////////////////////////////////////////////////////////////////////

