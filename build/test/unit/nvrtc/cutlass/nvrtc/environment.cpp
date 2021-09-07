#include <cutlass/nvrtc/environment.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/aligned_buffer.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/arch.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/cache_operation.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/memory.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/memory_sm75.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/memory_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm50.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm60.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm61.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm75.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/mma_sparse_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/simd.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/simd_sm60.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/simd_sm61.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/wmma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/wmma_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/wmma_sm72.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/arch/wmma_sm75.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/array.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/array_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/array_subbyte.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/bfloat16.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/constants.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/conv2d_problem_size.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/conv3d_problem_size.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/convolution.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/device/implicit_gemm_convolution.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv2d.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv2d_dgrad.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv2d_fprop.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv2d_wgrad.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv3d_dgrad.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv3d_fprop.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/default_conv3d_wgrad.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/kernel/implicit_gemm_convolution.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_dgrad_filter_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_dgrad_filter_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_dgrad_output_gradient_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_dgrad_output_gradient_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_fprop_activation_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_fprop_activation_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_fprop_filter_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_fprop_filter_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_params.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_wgrad_activation_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_wgrad_activation_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_wgrad_output_gradient_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv2d_wgrad_output_gradient_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_dgrad_filter_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_dgrad_filter_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_dgrad_output_gradient_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_dgrad_output_gradient_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_fprop_activation_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_fprop_activation_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_fprop_filter_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_fprop_filter_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_params.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_wgrad_activation_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_wgrad_activation_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_wgrad_output_gradient_tile_access_iterator_analytic.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/conv3d_wgrad_output_gradient_tile_access_iterator_optimized.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/implicit_gemm_multistage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/conv/threadblock/implicit_gemm_pipelined.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/coord.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/core_io.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/cutlass.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/device_kernel.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/activation.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/conversion_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_bias_relu.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_clamp.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_gelu.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_relu.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/linear_combination_sigmoid.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/reduction_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/thread/scale_type.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_volta_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_epilogue_wmma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_thread_map_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_thread_map_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_thread_map_volta_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/default_thread_map_wmma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/direct_epilogue_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/epilogue.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/epilogue_base.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/epilogue_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/epilogue_workspace.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/interleaved_epilogue.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/output_iterator_parameter.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/output_tile_thread_map.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/predicated_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/predicated_tile_iterator_params.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/shared_load_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/threadblock/shared_load_iterator_mixed.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_gaussian_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_volta_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/fragment_iterator_wmma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/simt_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tensor_op_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tile_iterator_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tile_iterator_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tile_iterator_tensor_op_mixed.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tile_iterator_volta_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/tile_iterator_wmma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/volta_tensor_op_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/epilogue/warp/wmma_tensor_op_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/fast_math.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/functional.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/default_gemm_configuration.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_array.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_batched.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_sparse.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_splitk_parallel.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_universal.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_universal_adapter.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/device/gemm_universal_base.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/gemm.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_planar_complex_universal.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_sparse.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_splitk_parallel.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_universal.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemm_with_reduction.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/default_gemv.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_array.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_batched.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_pipelined.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_planar_complex_array.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_splitk_parallel.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemm_universal.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/gemv_batched_strided.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/kernel/sparse_gemm.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/thread/mma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/thread/mma_sm50.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/thread/mma_sm60.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/thread/mma_sm61.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_gemv_core.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_sm75.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_sparse_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_core_wmma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_planar_complex_multistage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_mma_planar_complex_pipelined.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_multistage_mma_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_multistage_mma_complex_core.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_multistage_mma_complex_core_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/default_sparse_mma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/gemv.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_base.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_multistage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_pipelined.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_planar_complex_base.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_planar_complex_multistage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_planar_complex_pipelined.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_singlestage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_sparse_base.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/mma_sparse_multistage.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/threadblock/threadblock_swizzle.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/default_mma_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/default_mma_sparse_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/default_mma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/default_mma_tensor_op_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/default_mma_wmma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_complex_tensor_op_tile_iterator_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_gaussian_complex_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_gaussian_complex_tensor_op_tile_iterator_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_simt.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_simt_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_simt_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_sparse_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_fragment_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_policy.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_tile_iterator_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_tile_iterator_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_tile_iterator_sparse.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_tile_iterator_wmma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/mma_tensor_op_wmma.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/gemm/warp/tile_iterator_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/half.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/integer_subbyte.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/kernel_launch.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/layout.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/matrix.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/pitch_linear.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/tensor.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/tensor_op_multiplicand_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/tensor_op_multiplicand_sm75.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/tensor_op_multiplicand_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/layout/vector.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/matrix.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/matrix_coord.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/matrix_shape.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/numeric_conversion.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/numeric_types.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/platform/platform.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/predicate_vector.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/quaternion.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/real.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/device/reduce_split_k.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/device/tensor_reduce.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/device/tensor_reduce_affine_contiguous.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/device/tensor_reduce_affine_strided.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/kernel/reduce_split_k.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/kernel/tensor_reduce_affine_contiguous.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/kernel/tensor_reduce_affine_strided.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/thread/reduce.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/thread/reduction_operators.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/reduction/threadblock_swizzle.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/relatively_equal.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/semaphore.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/subbyte_reference.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tensor_coord.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tensor_ref.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tensor_ref_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tensor_view.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tensor_view_planar_complex.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/tfloat32.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/thread/matrix.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/trace.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/pitch_linear_thread_map.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/thread/transpose.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/thread/unaryOp.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/predicated_tile_access_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/predicated_tile_access_iterator_2dthreadtile.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/predicated_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/predicated_tile_iterator_2dthreadtile.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_access_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_access_iterator_pitch_linear.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_access_iterator_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_access_iterator_tensor_op_sm80.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_iterator.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_iterator_pitch_linear.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_iterator_pitch_linear_2dthreadtile.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_iterator_tensor_op.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/transform/threadblock/regular_tile_iterator_tensor_op_sm70.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/uint128.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/cutlass/wmma_array.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/unit/nvrtc/kernel/thread/testbed_kernel.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/assert.h>
#include </home/ubuntu/github/cutlass/build/test/unit/nvrtc/nvrtc/stdint.h>

namespace cutlass {
namespace nvrtc {

char const *kCutlassHeaders[] = {
  cutlass_aligned_buffer_h,
  cutlass_arch_arch_h,
  cutlass_arch_cache_operation_h,
  cutlass_arch_memory_h,
  cutlass_arch_memory_sm75_h,
  cutlass_arch_memory_sm80_h,
  cutlass_arch_mma_h,
  cutlass_arch_mma_sm50_h,
  cutlass_arch_mma_sm60_h,
  cutlass_arch_mma_sm61_h,
  cutlass_arch_mma_sm70_h,
  cutlass_arch_mma_sm75_h,
  cutlass_arch_mma_sm80_h,
  cutlass_arch_mma_sparse_sm80_h,
  cutlass_arch_simd_h,
  cutlass_arch_simd_sm60_h,
  cutlass_arch_simd_sm61_h,
  cutlass_arch_wmma_h,
  cutlass_arch_wmma_sm70_h,
  cutlass_arch_wmma_sm72_h,
  cutlass_arch_wmma_sm75_h,
  cutlass_array_h,
  cutlass_array_planar_complex_h,
  cutlass_array_subbyte_h,
  cutlass_bfloat16_h,
  cutlass_complex_h,
  cutlass_constants_h,
  cutlass_conv_conv2d_problem_size_h,
  cutlass_conv_conv3d_problem_size_h,
  cutlass_conv_convolution_h,
  cutlass_conv_device_implicit_gemm_convolution_h,
  cutlass_conv_kernel_default_conv2d_h,
  cutlass_conv_kernel_default_conv2d_dgrad_h,
  cutlass_conv_kernel_default_conv2d_fprop_h,
  cutlass_conv_kernel_default_conv2d_wgrad_h,
  cutlass_conv_kernel_default_conv3d_dgrad_h,
  cutlass_conv_kernel_default_conv3d_fprop_h,
  cutlass_conv_kernel_default_conv3d_wgrad_h,
  cutlass_conv_kernel_implicit_gemm_convolution_h,
  cutlass_conv_threadblock_conv2d_dgrad_filter_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_dgrad_filter_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv2d_dgrad_output_gradient_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_dgrad_output_gradient_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv2d_fprop_activation_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_fprop_activation_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv2d_fprop_filter_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_fprop_filter_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv2d_params_h,
  cutlass_conv_threadblock_conv2d_tile_iterator_h,
  cutlass_conv_threadblock_conv2d_wgrad_activation_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_wgrad_activation_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv2d_wgrad_output_gradient_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv2d_wgrad_output_gradient_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_dgrad_filter_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_dgrad_filter_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_dgrad_output_gradient_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_dgrad_output_gradient_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_fprop_activation_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_fprop_activation_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_fprop_filter_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_fprop_filter_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_params_h,
  cutlass_conv_threadblock_conv3d_wgrad_activation_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_wgrad_activation_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_conv3d_wgrad_output_gradient_tile_access_iterator_analytic_h,
  cutlass_conv_threadblock_conv3d_wgrad_output_gradient_tile_access_iterator_optimized_h,
  cutlass_conv_threadblock_implicit_gemm_multistage_h,
  cutlass_conv_threadblock_implicit_gemm_pipelined_h,
  cutlass_coord_h,
  cutlass_core_io_h,
  cutlass_cutlass_h,
  cutlass_device_kernel_h,
  cutlass_epilogue_thread_activation_h,
  cutlass_epilogue_thread_conversion_op_h,
  cutlass_epilogue_thread_linear_combination_h,
  cutlass_epilogue_thread_linear_combination_bias_relu_h,
  cutlass_epilogue_thread_linear_combination_clamp_h,
  cutlass_epilogue_thread_linear_combination_gelu_h,
  cutlass_epilogue_thread_linear_combination_planar_complex_h,
  cutlass_epilogue_thread_linear_combination_relu_h,
  cutlass_epilogue_thread_linear_combination_sigmoid_h,
  cutlass_epilogue_thread_reduction_op_h,
  cutlass_epilogue_thread_scale_type_h,
  cutlass_epilogue_threadblock_default_epilogue_complex_tensor_op_h,
  cutlass_epilogue_threadblock_default_epilogue_planar_complex_h,
  cutlass_epilogue_threadblock_default_epilogue_simt_h,
  cutlass_epilogue_threadblock_default_epilogue_tensor_op_h,
  cutlass_epilogue_threadblock_default_epilogue_volta_tensor_op_h,
  cutlass_epilogue_threadblock_default_epilogue_wmma_tensor_op_h,
  cutlass_epilogue_threadblock_default_thread_map_simt_h,
  cutlass_epilogue_threadblock_default_thread_map_tensor_op_h,
  cutlass_epilogue_threadblock_default_thread_map_volta_tensor_op_h,
  cutlass_epilogue_threadblock_default_thread_map_wmma_tensor_op_h,
  cutlass_epilogue_threadblock_direct_epilogue_tensor_op_h,
  cutlass_epilogue_threadblock_epilogue_h,
  cutlass_epilogue_threadblock_epilogue_base_h,
  cutlass_epilogue_threadblock_epilogue_planar_complex_h,
  cutlass_epilogue_threadblock_epilogue_workspace_h,
  cutlass_epilogue_threadblock_interleaved_epilogue_h,
  cutlass_epilogue_threadblock_output_iterator_parameter_h,
  cutlass_epilogue_threadblock_output_tile_thread_map_h,
  cutlass_epilogue_threadblock_predicated_tile_iterator_h,
  cutlass_epilogue_threadblock_predicated_tile_iterator_params_h,
  cutlass_epilogue_threadblock_shared_load_iterator_h,
  cutlass_epilogue_threadblock_shared_load_iterator_mixed_h,
  cutlass_epilogue_warp_fragment_iterator_complex_tensor_op_h,
  cutlass_epilogue_warp_fragment_iterator_gaussian_complex_tensor_op_h,
  cutlass_epilogue_warp_fragment_iterator_simt_h,
  cutlass_epilogue_warp_fragment_iterator_tensor_op_h,
  cutlass_epilogue_warp_fragment_iterator_volta_tensor_op_h,
  cutlass_epilogue_warp_fragment_iterator_wmma_tensor_op_h,
  cutlass_epilogue_warp_simt_policy_h,
  cutlass_epilogue_warp_tensor_op_policy_h,
  cutlass_epilogue_warp_tile_iterator_simt_h,
  cutlass_epilogue_warp_tile_iterator_tensor_op_h,
  cutlass_epilogue_warp_tile_iterator_tensor_op_mixed_h,
  cutlass_epilogue_warp_tile_iterator_volta_tensor_op_h,
  cutlass_epilogue_warp_tile_iterator_wmma_tensor_op_h,
  cutlass_epilogue_warp_volta_tensor_op_policy_h,
  cutlass_epilogue_warp_wmma_tensor_op_policy_h,
  cutlass_fast_math_h,
  cutlass_functional_h,
  cutlass_gemm_device_default_gemm_configuration_h,
  cutlass_gemm_device_gemm_h,
  cutlass_gemm_device_gemm_array_h,
  cutlass_gemm_device_gemm_batched_h,
  cutlass_gemm_device_gemm_complex_h,
  cutlass_gemm_device_gemm_sparse_h,
  cutlass_gemm_device_gemm_splitk_parallel_h,
  cutlass_gemm_device_gemm_universal_h,
  cutlass_gemm_device_gemm_universal_adapter_h,
  cutlass_gemm_device_gemm_universal_base_h,
  cutlass_gemm_gemm_h,
  cutlass_gemm_kernel_default_gemm_h,
  cutlass_gemm_kernel_default_gemm_complex_h,
  cutlass_gemm_kernel_default_gemm_planar_complex_universal_h,
  cutlass_gemm_kernel_default_gemm_sparse_h,
  cutlass_gemm_kernel_default_gemm_splitk_parallel_h,
  cutlass_gemm_kernel_default_gemm_universal_h,
  cutlass_gemm_kernel_default_gemm_with_reduction_h,
  cutlass_gemm_kernel_default_gemv_h,
  cutlass_gemm_kernel_gemm_h,
  cutlass_gemm_kernel_gemm_array_h,
  cutlass_gemm_kernel_gemm_batched_h,
  cutlass_gemm_kernel_gemm_pipelined_h,
  cutlass_gemm_kernel_gemm_planar_complex_h,
  cutlass_gemm_kernel_gemm_planar_complex_array_h,
  cutlass_gemm_kernel_gemm_splitk_parallel_h,
  cutlass_gemm_kernel_gemm_universal_h,
  cutlass_gemm_kernel_gemv_batched_strided_h,
  cutlass_gemm_kernel_sparse_gemm_h,
  cutlass_gemm_thread_mma_h,
  cutlass_gemm_thread_mma_sm50_h,
  cutlass_gemm_thread_mma_sm60_h,
  cutlass_gemm_thread_mma_sm61_h,
  cutlass_gemm_threadblock_default_gemv_core_h,
  cutlass_gemm_threadblock_default_mma_h,
  cutlass_gemm_threadblock_default_mma_core_h,
  cutlass_gemm_threadblock_default_mma_core_simt_h,
  cutlass_gemm_threadblock_default_mma_core_sm70_h,
  cutlass_gemm_threadblock_default_mma_core_sm75_h,
  cutlass_gemm_threadblock_default_mma_core_sm80_h,
  cutlass_gemm_threadblock_default_mma_core_sparse_sm80_h,
  cutlass_gemm_threadblock_default_mma_core_wmma_h,
  cutlass_gemm_threadblock_default_mma_planar_complex_multistage_h,
  cutlass_gemm_threadblock_default_mma_planar_complex_pipelined_h,
  cutlass_gemm_threadblock_default_multistage_mma_complex_h,
  cutlass_gemm_threadblock_default_multistage_mma_complex_core_h,
  cutlass_gemm_threadblock_default_multistage_mma_complex_core_sm80_h,
  cutlass_gemm_threadblock_default_sparse_mma_h,
  cutlass_gemm_threadblock_gemv_h,
  cutlass_gemm_threadblock_mma_base_h,
  cutlass_gemm_threadblock_mma_multistage_h,
  cutlass_gemm_threadblock_mma_pipelined_h,
  cutlass_gemm_threadblock_mma_planar_complex_base_h,
  cutlass_gemm_threadblock_mma_planar_complex_multistage_h,
  cutlass_gemm_threadblock_mma_planar_complex_pipelined_h,
  cutlass_gemm_threadblock_mma_singlestage_h,
  cutlass_gemm_threadblock_mma_sparse_base_h,
  cutlass_gemm_threadblock_mma_sparse_multistage_h,
  cutlass_gemm_threadblock_threadblock_swizzle_h,
  cutlass_gemm_warp_default_mma_complex_tensor_op_h,
  cutlass_gemm_warp_default_mma_sparse_tensor_op_h,
  cutlass_gemm_warp_default_mma_tensor_op_h,
  cutlass_gemm_warp_default_mma_tensor_op_sm80_h,
  cutlass_gemm_warp_default_mma_wmma_tensor_op_h,
  cutlass_gemm_warp_mma_h,
  cutlass_gemm_warp_mma_complex_tensor_op_h,
  cutlass_gemm_warp_mma_complex_tensor_op_tile_iterator_sm80_h,
  cutlass_gemm_warp_mma_gaussian_complex_tensor_op_h,
  cutlass_gemm_warp_mma_gaussian_complex_tensor_op_tile_iterator_sm80_h,
  cutlass_gemm_warp_mma_planar_complex_h,
  cutlass_gemm_warp_mma_simt_h,
  cutlass_gemm_warp_mma_simt_policy_h,
  cutlass_gemm_warp_mma_simt_tile_iterator_h,
  cutlass_gemm_warp_mma_sparse_tensor_op_h,
  cutlass_gemm_warp_mma_tensor_op_h,
  cutlass_gemm_warp_mma_tensor_op_fragment_iterator_h,
  cutlass_gemm_warp_mma_tensor_op_policy_h,
  cutlass_gemm_warp_mma_tensor_op_sm70_h,
  cutlass_gemm_warp_mma_tensor_op_tile_iterator_h,
  cutlass_gemm_warp_mma_tensor_op_tile_iterator_sm70_h,
  cutlass_gemm_warp_mma_tensor_op_tile_iterator_sm80_h,
  cutlass_gemm_warp_mma_tensor_op_tile_iterator_sparse_h,
  cutlass_gemm_warp_mma_tensor_op_tile_iterator_wmma_h,
  cutlass_gemm_warp_mma_tensor_op_wmma_h,
  cutlass_gemm_warp_tile_iterator_planar_complex_h,
  cutlass_half_h,
  cutlass_integer_subbyte_h,
  cutlass_kernel_launch_h,
  cutlass_layout_layout_h,
  cutlass_layout_matrix_h,
  cutlass_layout_pitch_linear_h,
  cutlass_layout_tensor_h,
  cutlass_layout_tensor_op_multiplicand_sm70_h,
  cutlass_layout_tensor_op_multiplicand_sm75_h,
  cutlass_layout_tensor_op_multiplicand_sm80_h,
  cutlass_layout_vector_h,
  cutlass_matrix_h,
  cutlass_matrix_coord_h,
  cutlass_matrix_shape_h,
  cutlass_numeric_conversion_h,
  cutlass_numeric_types_h,
  cutlass_platform_platform_h,
  cutlass_predicate_vector_h,
  cutlass_quaternion_h,
  cutlass_real_h,
  cutlass_reduction_device_reduce_split_k_h,
  cutlass_reduction_device_tensor_reduce_h,
  cutlass_reduction_device_tensor_reduce_affine_contiguous_h,
  cutlass_reduction_device_tensor_reduce_affine_strided_h,
  cutlass_reduction_kernel_reduce_split_k_h,
  cutlass_reduction_kernel_tensor_reduce_affine_contiguous_h,
  cutlass_reduction_kernel_tensor_reduce_affine_strided_h,
  cutlass_reduction_thread_reduce_h,
  cutlass_reduction_thread_reduction_operators_h,
  cutlass_reduction_threadblock_swizzle_h,
  cutlass_relatively_equal_h,
  cutlass_semaphore_h,
  cutlass_subbyte_reference_h,
  cutlass_tensor_coord_h,
  cutlass_tensor_ref_h,
  cutlass_tensor_ref_planar_complex_h,
  cutlass_tensor_view_h,
  cutlass_tensor_view_planar_complex_h,
  cutlass_tfloat32_h,
  cutlass_thread_matrix_h,
  cutlass_trace_h,
  cutlass_transform_pitch_linear_thread_map_h,
  cutlass_transform_thread_transpose_h,
  cutlass_transform_thread_unaryOp_h,
  cutlass_transform_threadblock_predicated_tile_access_iterator_h,
  cutlass_transform_threadblock_predicated_tile_access_iterator_2dthreadtile_h,
  cutlass_transform_threadblock_predicated_tile_iterator_h,
  cutlass_transform_threadblock_predicated_tile_iterator_2dthreadtile_h,
  cutlass_transform_threadblock_regular_tile_access_iterator_h,
  cutlass_transform_threadblock_regular_tile_access_iterator_pitch_linear_h,
  cutlass_transform_threadblock_regular_tile_access_iterator_tensor_op_h,
  cutlass_transform_threadblock_regular_tile_access_iterator_tensor_op_sm80_h,
  cutlass_transform_threadblock_regular_tile_iterator_h,
  cutlass_transform_threadblock_regular_tile_iterator_pitch_linear_h,
  cutlass_transform_threadblock_regular_tile_iterator_pitch_linear_2dthreadtile_h,
  cutlass_transform_threadblock_regular_tile_iterator_tensor_op_h,
  cutlass_transform_threadblock_regular_tile_iterator_tensor_op_sm70_h,
  cutlass_uint128_h,
  cutlass_wmma_array_h,
  unit_nvrtc_kernel_thread_testbed_kernel_h,
  assert_h,
  stdint_h,
};
const size_t kCutlassHeaderCount = sizeof(kCutlassHeaders) / sizeof(*kCutlassHeaders);

char const *kCutlassHeaderNames[] = {
  "cutlass/aligned_buffer.h",
  "cutlass/arch/arch.h",
  "cutlass/arch/cache_operation.h",
  "cutlass/arch/memory.h",
  "cutlass/arch/memory_sm75.h",
  "cutlass/arch/memory_sm80.h",
  "cutlass/arch/mma.h",
  "cutlass/arch/mma_sm50.h",
  "cutlass/arch/mma_sm60.h",
  "cutlass/arch/mma_sm61.h",
  "cutlass/arch/mma_sm70.h",
  "cutlass/arch/mma_sm75.h",
  "cutlass/arch/mma_sm80.h",
  "cutlass/arch/mma_sparse_sm80.h",
  "cutlass/arch/simd.h",
  "cutlass/arch/simd_sm60.h",
  "cutlass/arch/simd_sm61.h",
  "cutlass/arch/wmma.h",
  "cutlass/arch/wmma_sm70.h",
  "cutlass/arch/wmma_sm72.h",
  "cutlass/arch/wmma_sm75.h",
  "cutlass/array.h",
  "cutlass/array_planar_complex.h",
  "cutlass/array_subbyte.h",
  "cutlass/bfloat16.h",
  "cutlass/complex.h",
  "cutlass/constants.h",
  "cutlass/conv/conv2d_problem_size.h",
  "cutlass/conv/conv3d_problem_size.h",
  "cutlass/conv/convolution.h",
  "cutlass/conv/device/implicit_gemm_convolution.h",
  "cutlass/conv/kernel/default_conv2d.h",
  "cutlass/conv/kernel/default_conv2d_dgrad.h",
  "cutlass/conv/kernel/default_conv2d_fprop.h",
  "cutlass/conv/kernel/default_conv2d_wgrad.h",
  "cutlass/conv/kernel/default_conv3d_dgrad.h",
  "cutlass/conv/kernel/default_conv3d_fprop.h",
  "cutlass/conv/kernel/default_conv3d_wgrad.h",
  "cutlass/conv/kernel/implicit_gemm_convolution.h",
  "cutlass/conv/threadblock/conv2d_dgrad_filter_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_dgrad_filter_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv2d_dgrad_output_gradient_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_dgrad_output_gradient_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv2d_fprop_activation_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_fprop_activation_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv2d_fprop_filter_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_fprop_filter_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv2d_params.h",
  "cutlass/conv/threadblock/conv2d_tile_iterator.h",
  "cutlass/conv/threadblock/conv2d_wgrad_activation_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_wgrad_activation_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv2d_wgrad_output_gradient_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv2d_wgrad_output_gradient_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_dgrad_filter_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_dgrad_filter_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_dgrad_output_gradient_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_dgrad_output_gradient_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_fprop_activation_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_fprop_activation_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_fprop_filter_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_fprop_filter_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_params.h",
  "cutlass/conv/threadblock/conv3d_wgrad_activation_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_wgrad_activation_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/conv3d_wgrad_output_gradient_tile_access_iterator_analytic.h",
  "cutlass/conv/threadblock/conv3d_wgrad_output_gradient_tile_access_iterator_optimized.h",
  "cutlass/conv/threadblock/implicit_gemm_multistage.h",
  "cutlass/conv/threadblock/implicit_gemm_pipelined.h",
  "cutlass/coord.h",
  "cutlass/core_io.h",
  "cutlass/cutlass.h",
  "cutlass/device_kernel.h",
  "cutlass/epilogue/thread/activation.h",
  "cutlass/epilogue/thread/conversion_op.h",
  "cutlass/epilogue/thread/linear_combination.h",
  "cutlass/epilogue/thread/linear_combination_bias_relu.h",
  "cutlass/epilogue/thread/linear_combination_clamp.h",
  "cutlass/epilogue/thread/linear_combination_gelu.h",
  "cutlass/epilogue/thread/linear_combination_planar_complex.h",
  "cutlass/epilogue/thread/linear_combination_relu.h",
  "cutlass/epilogue/thread/linear_combination_sigmoid.h",
  "cutlass/epilogue/thread/reduction_op.h",
  "cutlass/epilogue/thread/scale_type.h",
  "cutlass/epilogue/threadblock/default_epilogue_complex_tensor_op.h",
  "cutlass/epilogue/threadblock/default_epilogue_planar_complex.h",
  "cutlass/epilogue/threadblock/default_epilogue_simt.h",
  "cutlass/epilogue/threadblock/default_epilogue_tensor_op.h",
  "cutlass/epilogue/threadblock/default_epilogue_volta_tensor_op.h",
  "cutlass/epilogue/threadblock/default_epilogue_wmma_tensor_op.h",
  "cutlass/epilogue/threadblock/default_thread_map_simt.h",
  "cutlass/epilogue/threadblock/default_thread_map_tensor_op.h",
  "cutlass/epilogue/threadblock/default_thread_map_volta_tensor_op.h",
  "cutlass/epilogue/threadblock/default_thread_map_wmma_tensor_op.h",
  "cutlass/epilogue/threadblock/direct_epilogue_tensor_op.h",
  "cutlass/epilogue/threadblock/epilogue.h",
  "cutlass/epilogue/threadblock/epilogue_base.h",
  "cutlass/epilogue/threadblock/epilogue_planar_complex.h",
  "cutlass/epilogue/threadblock/epilogue_workspace.h",
  "cutlass/epilogue/threadblock/interleaved_epilogue.h",
  "cutlass/epilogue/threadblock/output_iterator_parameter.h",
  "cutlass/epilogue/threadblock/output_tile_thread_map.h",
  "cutlass/epilogue/threadblock/predicated_tile_iterator.h",
  "cutlass/epilogue/threadblock/predicated_tile_iterator_params.h",
  "cutlass/epilogue/threadblock/shared_load_iterator.h",
  "cutlass/epilogue/threadblock/shared_load_iterator_mixed.h",
  "cutlass/epilogue/warp/fragment_iterator_complex_tensor_op.h",
  "cutlass/epilogue/warp/fragment_iterator_gaussian_complex_tensor_op.h",
  "cutlass/epilogue/warp/fragment_iterator_simt.h",
  "cutlass/epilogue/warp/fragment_iterator_tensor_op.h",
  "cutlass/epilogue/warp/fragment_iterator_volta_tensor_op.h",
  "cutlass/epilogue/warp/fragment_iterator_wmma_tensor_op.h",
  "cutlass/epilogue/warp/simt_policy.h",
  "cutlass/epilogue/warp/tensor_op_policy.h",
  "cutlass/epilogue/warp/tile_iterator_simt.h",
  "cutlass/epilogue/warp/tile_iterator_tensor_op.h",
  "cutlass/epilogue/warp/tile_iterator_tensor_op_mixed.h",
  "cutlass/epilogue/warp/tile_iterator_volta_tensor_op.h",
  "cutlass/epilogue/warp/tile_iterator_wmma_tensor_op.h",
  "cutlass/epilogue/warp/volta_tensor_op_policy.h",
  "cutlass/epilogue/warp/wmma_tensor_op_policy.h",
  "cutlass/fast_math.h",
  "cutlass/functional.h",
  "cutlass/gemm/device/default_gemm_configuration.h",
  "cutlass/gemm/device/gemm.h",
  "cutlass/gemm/device/gemm_array.h",
  "cutlass/gemm/device/gemm_batched.h",
  "cutlass/gemm/device/gemm_complex.h",
  "cutlass/gemm/device/gemm_sparse.h",
  "cutlass/gemm/device/gemm_splitk_parallel.h",
  "cutlass/gemm/device/gemm_universal.h",
  "cutlass/gemm/device/gemm_universal_adapter.h",
  "cutlass/gemm/device/gemm_universal_base.h",
  "cutlass/gemm/gemm.h",
  "cutlass/gemm/kernel/default_gemm.h",
  "cutlass/gemm/kernel/default_gemm_complex.h",
  "cutlass/gemm/kernel/default_gemm_planar_complex_universal.h",
  "cutlass/gemm/kernel/default_gemm_sparse.h",
  "cutlass/gemm/kernel/default_gemm_splitk_parallel.h",
  "cutlass/gemm/kernel/default_gemm_universal.h",
  "cutlass/gemm/kernel/default_gemm_with_reduction.h",
  "cutlass/gemm/kernel/default_gemv.h",
  "cutlass/gemm/kernel/gemm.h",
  "cutlass/gemm/kernel/gemm_array.h",
  "cutlass/gemm/kernel/gemm_batched.h",
  "cutlass/gemm/kernel/gemm_pipelined.h",
  "cutlass/gemm/kernel/gemm_planar_complex.h",
  "cutlass/gemm/kernel/gemm_planar_complex_array.h",
  "cutlass/gemm/kernel/gemm_splitk_parallel.h",
  "cutlass/gemm/kernel/gemm_universal.h",
  "cutlass/gemm/kernel/gemv_batched_strided.h",
  "cutlass/gemm/kernel/sparse_gemm.h",
  "cutlass/gemm/thread/mma.h",
  "cutlass/gemm/thread/mma_sm50.h",
  "cutlass/gemm/thread/mma_sm60.h",
  "cutlass/gemm/thread/mma_sm61.h",
  "cutlass/gemm/threadblock/default_gemv_core.h",
  "cutlass/gemm/threadblock/default_mma.h",
  "cutlass/gemm/threadblock/default_mma_core.h",
  "cutlass/gemm/threadblock/default_mma_core_simt.h",
  "cutlass/gemm/threadblock/default_mma_core_sm70.h",
  "cutlass/gemm/threadblock/default_mma_core_sm75.h",
  "cutlass/gemm/threadblock/default_mma_core_sm80.h",
  "cutlass/gemm/threadblock/default_mma_core_sparse_sm80.h",
  "cutlass/gemm/threadblock/default_mma_core_wmma.h",
  "cutlass/gemm/threadblock/default_mma_planar_complex_multistage.h",
  "cutlass/gemm/threadblock/default_mma_planar_complex_pipelined.h",
  "cutlass/gemm/threadblock/default_multistage_mma_complex.h",
  "cutlass/gemm/threadblock/default_multistage_mma_complex_core.h",
  "cutlass/gemm/threadblock/default_multistage_mma_complex_core_sm80.h",
  "cutlass/gemm/threadblock/default_sparse_mma.h",
  "cutlass/gemm/threadblock/gemv.h",
  "cutlass/gemm/threadblock/mma_base.h",
  "cutlass/gemm/threadblock/mma_multistage.h",
  "cutlass/gemm/threadblock/mma_pipelined.h",
  "cutlass/gemm/threadblock/mma_planar_complex_base.h",
  "cutlass/gemm/threadblock/mma_planar_complex_multistage.h",
  "cutlass/gemm/threadblock/mma_planar_complex_pipelined.h",
  "cutlass/gemm/threadblock/mma_singlestage.h",
  "cutlass/gemm/threadblock/mma_sparse_base.h",
  "cutlass/gemm/threadblock/mma_sparse_multistage.h",
  "cutlass/gemm/threadblock/threadblock_swizzle.h",
  "cutlass/gemm/warp/default_mma_complex_tensor_op.h",
  "cutlass/gemm/warp/default_mma_sparse_tensor_op.h",
  "cutlass/gemm/warp/default_mma_tensor_op.h",
  "cutlass/gemm/warp/default_mma_tensor_op_sm80.h",
  "cutlass/gemm/warp/default_mma_wmma_tensor_op.h",
  "cutlass/gemm/warp/mma.h",
  "cutlass/gemm/warp/mma_complex_tensor_op.h",
  "cutlass/gemm/warp/mma_complex_tensor_op_tile_iterator_sm80.h",
  "cutlass/gemm/warp/mma_gaussian_complex_tensor_op.h",
  "cutlass/gemm/warp/mma_gaussian_complex_tensor_op_tile_iterator_sm80.h",
  "cutlass/gemm/warp/mma_planar_complex.h",
  "cutlass/gemm/warp/mma_simt.h",
  "cutlass/gemm/warp/mma_simt_policy.h",
  "cutlass/gemm/warp/mma_simt_tile_iterator.h",
  "cutlass/gemm/warp/mma_sparse_tensor_op.h",
  "cutlass/gemm/warp/mma_tensor_op.h",
  "cutlass/gemm/warp/mma_tensor_op_fragment_iterator.h",
  "cutlass/gemm/warp/mma_tensor_op_policy.h",
  "cutlass/gemm/warp/mma_tensor_op_sm70.h",
  "cutlass/gemm/warp/mma_tensor_op_tile_iterator.h",
  "cutlass/gemm/warp/mma_tensor_op_tile_iterator_sm70.h",
  "cutlass/gemm/warp/mma_tensor_op_tile_iterator_sm80.h",
  "cutlass/gemm/warp/mma_tensor_op_tile_iterator_sparse.h",
  "cutlass/gemm/warp/mma_tensor_op_tile_iterator_wmma.h",
  "cutlass/gemm/warp/mma_tensor_op_wmma.h",
  "cutlass/gemm/warp/tile_iterator_planar_complex.h",
  "cutlass/half.h",
  "cutlass/integer_subbyte.h",
  "cutlass/kernel_launch.h",
  "cutlass/layout/layout.h",
  "cutlass/layout/matrix.h",
  "cutlass/layout/pitch_linear.h",
  "cutlass/layout/tensor.h",
  "cutlass/layout/tensor_op_multiplicand_sm70.h",
  "cutlass/layout/tensor_op_multiplicand_sm75.h",
  "cutlass/layout/tensor_op_multiplicand_sm80.h",
  "cutlass/layout/vector.h",
  "cutlass/matrix.h",
  "cutlass/matrix_coord.h",
  "cutlass/matrix_shape.h",
  "cutlass/numeric_conversion.h",
  "cutlass/numeric_types.h",
  "cutlass/platform/platform.h",
  "cutlass/predicate_vector.h",
  "cutlass/quaternion.h",
  "cutlass/real.h",
  "cutlass/reduction/device/reduce_split_k.h",
  "cutlass/reduction/device/tensor_reduce.h",
  "cutlass/reduction/device/tensor_reduce_affine_contiguous.h",
  "cutlass/reduction/device/tensor_reduce_affine_strided.h",
  "cutlass/reduction/kernel/reduce_split_k.h",
  "cutlass/reduction/kernel/tensor_reduce_affine_contiguous.h",
  "cutlass/reduction/kernel/tensor_reduce_affine_strided.h",
  "cutlass/reduction/thread/reduce.h",
  "cutlass/reduction/thread/reduction_operators.h",
  "cutlass/reduction/threadblock_swizzle.h",
  "cutlass/relatively_equal.h",
  "cutlass/semaphore.h",
  "cutlass/subbyte_reference.h",
  "cutlass/tensor_coord.h",
  "cutlass/tensor_ref.h",
  "cutlass/tensor_ref_planar_complex.h",
  "cutlass/tensor_view.h",
  "cutlass/tensor_view_planar_complex.h",
  "cutlass/tfloat32.h",
  "cutlass/thread/matrix.h",
  "cutlass/trace.h",
  "cutlass/transform/pitch_linear_thread_map.h",
  "cutlass/transform/thread/transpose.h",
  "cutlass/transform/thread/unaryOp.h",
  "cutlass/transform/threadblock/predicated_tile_access_iterator.h",
  "cutlass/transform/threadblock/predicated_tile_access_iterator_2dthreadtile.h",
  "cutlass/transform/threadblock/predicated_tile_iterator.h",
  "cutlass/transform/threadblock/predicated_tile_iterator_2dthreadtile.h",
  "cutlass/transform/threadblock/regular_tile_access_iterator.h",
  "cutlass/transform/threadblock/regular_tile_access_iterator_pitch_linear.h",
  "cutlass/transform/threadblock/regular_tile_access_iterator_tensor_op.h",
  "cutlass/transform/threadblock/regular_tile_access_iterator_tensor_op_sm80.h",
  "cutlass/transform/threadblock/regular_tile_iterator.h",
  "cutlass/transform/threadblock/regular_tile_iterator_pitch_linear.h",
  "cutlass/transform/threadblock/regular_tile_iterator_pitch_linear_2dthreadtile.h",
  "cutlass/transform/threadblock/regular_tile_iterator_tensor_op.h",
  "cutlass/transform/threadblock/regular_tile_iterator_tensor_op_sm70.h",
  "cutlass/uint128.h",
  "cutlass/wmma_array.h",
  "unit/nvrtc/kernel/thread/testbed_kernel.h",
  "assert.h",
  "stdint.h",
};

} // namespace nvrtc
} // namespace cutlass
