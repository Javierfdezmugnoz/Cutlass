# CMake generated Testfile for 
# Source directory: /home/javifdez/git_repository/Cutlass/examples/03_visualize_layout
# Build directory: /home/javifdez/git_repository/Cutlass/build/examples/03_visualize_layout
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_examples_03_visualize_layout_0 "/home/javifdez/git_repository/Cutlass/build/examples/03_visualize_layout/03_visualize_layout" "RowMajor" "--extent=16,16")
set_tests_properties(ctest_examples_03_visualize_layout_0 PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repository/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repository/Cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/javifdez/git_repository/Cutlass/examples/03_visualize_layout/CMakeLists.txt;26;cutlass_example_add_executable;/home/javifdez/git_repository/Cutlass/examples/03_visualize_layout/CMakeLists.txt;0;")
add_test(ctest_examples_03_visualize_layout_1 "/home/javifdez/git_repository/Cutlass/build/examples/03_visualize_layout/03_visualize_layout" "ColumnMajorInterleaved<4>" "--extent=32,8" "--output-shape=16" "--vectorize=4")
set_tests_properties(ctest_examples_03_visualize_layout_1 PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repository/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repository/Cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/javifdez/git_repository/Cutlass/examples/03_visualize_layout/CMakeLists.txt;26;cutlass_example_add_executable;/home/javifdez/git_repository/Cutlass/examples/03_visualize_layout/CMakeLists.txt;0;")
