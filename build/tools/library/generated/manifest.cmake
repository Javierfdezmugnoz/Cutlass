cutlass_target_sources(
  cutlass_library_objs
  BATCH_SOURCES ON
  PRIVATE
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/initialize_all.cpp
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/all_gemm_operations.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_sgemm_128x128_8x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_sgemm_128x128_8x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_sgemm_128x128_8x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_sgemm_128x128_8x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_dgemm_128x128_8x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_dgemm_128x128_8x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_dgemm_128x128_8x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_dgemm_128x128_8x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_cgemm_128x128_8x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_cgemm_128x128_8x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_cgemm_128x128_8x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_cgemm_128x128_8x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_hgemm_256x128_8x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_hgemm_256x128_8x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_hgemm_256x128_8x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_hgemm_256x128_8x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_igemm_s8_128x128_32x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_igemm_s8_128x128_32x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_igemm_s8_128x128_32x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_igemm_s8_128x128_32x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_s8_igemm_s8_128x128_32x2_nn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_s8_igemm_s8_128x128_32x2_nt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_s8_igemm_s8_128x128_32x2_tn_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_simt_s8_igemm_s8_128x128_32x2_tt_align1.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_s884gemm_f16_256x128_32x2_nn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_s884gemm_f16_256x128_32x2_nt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_s884gemm_f16_256x128_32x2_tn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_s884gemm_f16_256x128_32x2_tt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_f16_s884gemm_f16_256x128_32x2_nn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_f16_s884gemm_f16_256x128_32x2_nt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_f16_s884gemm_f16_256x128_32x2_tn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_f16_s884gemm_f16_256x128_32x2_tt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_h884gemm_256x128_32x2_nn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_h884gemm_256x128_32x2_nt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_h884gemm_256x128_32x2_tn_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/gemm/cutlass_tensorop_h884gemm_256x128_32x2_tt_align8.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/all_conv2d_operations.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_sfprop_analytic_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_sfprop_optimized_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_sdgrad_analytic_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_sdgrad_optimized_128x128_8x2_nhwc_unity_stride.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_swgrad_analytic_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_swgrad_optimized_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cfprop_analytic_cf32_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cfprop_optimized_cf32_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cdgrad_analytic_cf32_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cdgrad_optimized_cf32_128x128_8x2_nhwc_unity_stride.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cwgrad_analytic_cf32_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_simt_cf32_cwgrad_optimized_cf32_128x128_8x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884fprop_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884fprop_optimized_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884dgrad_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884dgrad_optimized_f16_256x128_32x2_nhwc_unity_stride.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884wgrad_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_s884wgrad_optimized_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884fprop_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884fprop_optimized_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884dgrad_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884dgrad_optimized_f16_256x128_32x2_nhwc_unity_stride.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884wgrad_analytic_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_f16_s884wgrad_optimized_f16_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884fprop_analytic_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884fprop_optimized_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884dgrad_analytic_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884dgrad_optimized_256x128_32x2_nhwc_unity_stride.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884wgrad_analytic_256x128_32x2_nhwc.cu
    /home/javifdez/git_repositories/Cutlass/build/tools/library/generated/conv2d/cutlass_tensorop_h884wgrad_optimized_256x128_32x2_nhwc.cu
)