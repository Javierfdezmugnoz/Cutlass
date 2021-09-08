# CMake generated Testfile for 
# Source directory: /home/javifdez/git_repositories/Cutlass/examples/13_two_tensor_op_fusion
# Build directory: /home/javifdez/git_repositories/Cutlass/build/examples/13_two_tensor_op_fusion
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_examples_13_fused_two_gemms "/home/javifdez/git_repositories/Cutlass/build/examples/13_two_tensor_op_fusion/13_fused_two_gemms")
set_tests_properties(ctest_examples_13_fused_two_gemms PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repositories/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repositories/Cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/javifdez/git_repositories/Cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;23;cutlass_example_add_executable;/home/javifdez/git_repositories/Cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;0;")
add_test(ctest_examples_13_fused_two_convs "/home/javifdez/git_repositories/Cutlass/build/examples/13_two_tensor_op_fusion/13_fused_two_convs")
set_tests_properties(ctest_examples_13_fused_two_convs PROPERTIES  _BACKTRACE_TRIPLES "/home/javifdez/git_repositories/Cutlass/CMakeLists.txt;641;add_test;/home/javifdez/git_repositories/Cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/javifdez/git_repositories/Cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;28;cutlass_example_add_executable;/home/javifdez/git_repositories/Cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;0;")
