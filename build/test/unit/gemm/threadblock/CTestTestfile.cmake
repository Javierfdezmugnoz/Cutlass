# CMake generated Testfile for 
# Source directory: /home/javifdez/git_repositories/Cutlass/test/unit/gemm/threadblock
# Build directory: /home/javifdez/git_repositories/Cutlass/build/test/unit/gemm/threadblock
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_gemm_threadblock "/home/javifdez/git_repositories/Cutlass/build/test/unit/gemm/threadblock/cutlass_test_unit_gemm_threadblock" "--gtest_output=xml:test_unit_gemm_threadblock.gtest.xml")
set_tests_properties(ctest_unit_gemm_threadblock PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repositories/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repositories/Cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/javifdez/git_repositories/Cutlass/test/unit/gemm/threadblock/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/javifdez/git_repositories/Cutlass/test/unit/gemm/threadblock/CMakeLists.txt;0;")
