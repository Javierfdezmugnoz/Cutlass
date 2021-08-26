# CMake generated Testfile for 
# Source directory: /home/javierfdez/github_repository/Cutlass/test/unit/gemm/threadblock
# Build directory: /home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/threadblock
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_gemm_threadblock "/home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/threadblock/cutlass_test_unit_gemm_threadblock" "--gtest_output=xml:test_unit_gemm_threadblock.gtest.xml")
set_tests_properties(ctest_unit_gemm_threadblock PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/test/unit/gemm/threadblock/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/javierfdez/github_repository/Cutlass/test/unit/gemm/threadblock/CMakeLists.txt;0;")
