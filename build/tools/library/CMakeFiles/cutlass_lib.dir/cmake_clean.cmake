file(REMOVE_RECURSE
  "libcutlassd.pdb"
  "libcutlassd.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/cutlass_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
