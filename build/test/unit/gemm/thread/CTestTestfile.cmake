# CMake generated Testfile for 
# Source directory: /home/ubuntu/github/cutlass/test/unit/gemm/thread
# Build directory: /home/ubuntu/github/cutlass/build/test/unit/gemm/thread
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_gemm_thread "/home/ubuntu/github/cutlass/build/test/unit/gemm/thread/cutlass_test_unit_gemm_thread" "--gtest_output=xml:test_unit_gemm_thread.gtest.xml")
set_tests_properties(ctest_unit_gemm_thread PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/gemm/thread/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/gemm/thread/CMakeLists.txt;0;")
subdirs("host")
