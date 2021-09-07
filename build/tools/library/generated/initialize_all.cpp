

#include "cutlass/library/library.h"
#include "cutlass/library/manifest.h"

namespace cutlass {
namespace library {

void initialize_all_gemm_operations(Manifest &manifest);
void initialize_all_conv2d_operations(Manifest &manifest);

void initialize_all(Manifest &manifest) {

  manifest.reserve(66);

  initialize_all_gemm_operations(manifest);
  initialize_all_conv2d_operations(manifest);

}

} // namespace library
} // namespace cutlass

