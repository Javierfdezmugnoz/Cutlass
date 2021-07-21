file(REMOVE_RECURSE
  "libcutlassd.a"
  "libcutlassd.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/cutlass_library_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
