
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


// Gemm operator cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1
using cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1_base = 
  typename cutlass::gemm::kernel::DefaultGemmUniversal<
    int8_t, cutlass::layout::ColumnMajor, cutlass::ComplexTransform::kNone, 1,    // transposed B operand
    int8_t, cutlass::layout::ColumnMajor, cutlass::ComplexTransform::kNone, 1,    // transposed A operand
    int8_t, cutlass::layout::RowMajor,
    int32_t,
    cutlass::arch::OpClassSimt,
    cutlass::arch::Sm61,
    cutlass::gemm::GemmShape<128, 32, 32>,
    cutlass::gemm::GemmShape<64, 32, 32>,
    cutlass::gemm::GemmShape<1, 1, 4>,
    cutlass::epilogue::thread::LinearCombination<
      int8_t,
      1,
      int32_t,
      int32_t
    >,
    cutlass::gemm::threadblock::GemmIdentityThreadblockSwizzle<8>,
    2,
    cutlass::arch::OpMultiplyAdd
>::GemmKernel;

// Define named type
struct cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1 : 
  public cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1_base { };


///////////////////////////////////////////////////////////////////////////////////////////////////

namespace cutlass {
namespace library {

///////////////////////////////////////////////////////////////////////////////////////////////////

void initialize_cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1(Manifest &manifest) {



  manifest.append(new GemmUniversalOperation<
      cutlass::gemm::device::GemmUniversalAdapter<cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1>
    >("cutlass_simt_s8_igemm_s8_128x32_32x2_tt_align1"));



}

///////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace library
} // namespace cutlass

///////////////////////////////////////////////////////////////////////////////////////////////////

