# CMake generated Testfile for 
# Source directory: /home/ubuntu/github/cutlass/examples/13_two_tensor_op_fusion
# Build directory: /home/ubuntu/github/cutlass/build/examples/13_two_tensor_op_fusion
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_examples_13_fused_two_gemms "/home/ubuntu/github/cutlass/build/examples/13_two_tensor_op_fusion/13_fused_two_gemms")
set_tests_properties(ctest_examples_13_fused_two_gemms PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;23;cutlass_example_add_executable;/home/ubuntu/github/cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;0;")
add_test(ctest_examples_13_fused_two_convs "/home/ubuntu/github/cutlass/build/examples/13_two_tensor_op_fusion/13_fused_two_convs")
set_tests_properties(ctest_examples_13_fused_two_convs PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/examples/CMakeLists.txt;57;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;28;cutlass_example_add_executable;/home/ubuntu/github/cutlass/examples/13_two_tensor_op_fusion/CMakeLists.txt;0;")
