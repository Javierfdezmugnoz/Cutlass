# CMake generated Testfile for 
# Source directory: /home/ubuntu/github/cutlass/test/unit/layout
# Build directory: /home/ubuntu/github/cutlass/build/test/unit/layout
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_layout "/home/ubuntu/github/cutlass/build/test/unit/layout/cutlass_test_unit_layout" "--gtest_output=xml:test_unit_layout.gtest.xml")
set_tests_properties(ctest_unit_layout PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/layout/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/layout/CMakeLists.txt;0;")
