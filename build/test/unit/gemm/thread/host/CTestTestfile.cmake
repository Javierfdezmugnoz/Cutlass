# CMake generated Testfile for 
# Source directory: /home/javierfdez/github_repository/Cutlass/test/unit/gemm/thread/host
# Build directory: /home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/thread/host
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_gemm_thread_host "/home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/thread/host/cutlass_test_unit_gemm_thread_host" "--gtest_output=xml:test_unit_gemm_thread_host.gtest.xml")
set_tests_properties(ctest_unit_gemm_thread_host PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/test/unit/gemm/thread/host/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/javierfdez/github_repository/Cutlass/test/unit/gemm/thread/host/CMakeLists.txt;0;")
