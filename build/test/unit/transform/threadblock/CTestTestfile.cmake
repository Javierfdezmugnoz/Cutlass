# CMake generated Testfile for 
# Source directory: /home/ubuntu/github/cutlass/test/unit/transform/threadblock
# Build directory: /home/ubuntu/github/cutlass/build/test/unit/transform/threadblock
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_transform_threadblock "/home/ubuntu/github/cutlass/build/test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock" "--gtest_output=xml:test_unit_transform_threadblock.gtest.xml")
set_tests_properties(ctest_unit_transform_threadblock PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;629;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/transform/threadblock/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/transform/threadblock/CMakeLists.txt;0;")
