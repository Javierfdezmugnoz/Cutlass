# CMake generated Testfile for 
# Source directory: /home/javifdez/git_repositories/Cutlass/test/unit/layout
# Build directory: /home/javifdez/git_repositories/Cutlass/build/test/unit/layout
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_layout "/home/javifdez/git_repositories/Cutlass/build/test/unit/layout/cutlass_test_unit_layout" "--gtest_output=xml:test_unit_layout.gtest.xml")
set_tests_properties(ctest_unit_layout PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repositories/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repositories/Cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/javifdez/git_repositories/Cutlass/test/unit/layout/CMakeLists.txt;23;cutlass_test_unit_add_executable;/home/javifdez/git_repositories/Cutlass/test/unit/layout/CMakeLists.txt;0;")
