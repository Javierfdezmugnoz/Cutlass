# CMake generated Testfile for 
# Source directory: /home/javierfdez/github_repository/Cutlass/test/unit/reduction/kernel
# Build directory: /home/javierfdez/github_repository/Cutlass/build/test/unit/reduction/kernel
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_reduction_kernel "/home/javierfdez/github_repository/Cutlass/build/test/unit/reduction/kernel/cutlass_test_unit_reduction_kernel" "--gtest_output=xml:test_unit_reduction_kernel.gtest.xml")
set_tests_properties(ctest_unit_reduction_kernel PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/test/unit/reduction/kernel/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/javierfdez/github_repository/Cutlass/test/unit/reduction/kernel/CMakeLists.txt;0;")
