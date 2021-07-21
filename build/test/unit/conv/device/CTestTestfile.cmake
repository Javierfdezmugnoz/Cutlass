# CMake generated Testfile for 
# Source directory: /home/ubuntu/github/cutlass/test/unit/conv/device
# Build directory: /home/ubuntu/github/cutlass/build/test/unit/conv/device
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_unit_conv_device_simt "/home/ubuntu/github/cutlass/build/test/unit/conv/device/cutlass_test_unit_conv_device_simt" "--gtest_output=xml:test_unit_conv_device_simt.gtest.xml")
set_tests_properties(ctest_unit_conv_device_simt PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;94;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;0;")
add_test(ctest_unit_conv_device_tensorop_f32_sm70 "/home/ubuntu/github/cutlass/build/test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70" "--gtest_output=xml:test_unit_conv_device_tensorop_f32_sm70.gtest.xml")
set_tests_properties(ctest_unit_conv_device_tensorop_f32_sm70 PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;129;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;0;")
add_test(ctest_unit_conv_device_tensorop_f32_sm75 "/home/ubuntu/github/cutlass/build/test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm75" "--gtest_output=xml:test_unit_conv_device_tensorop_f32_sm75.gtest.xml")
set_tests_properties(ctest_unit_conv_device_tensorop_f32_sm75 PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/github/cutlass/CMakeLists.txt;608;add_test;/home/ubuntu/github/cutlass/test/unit/CMakeLists.txt;72;cutlass_add_executable_tests;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;138;cutlass_test_unit_add_executable;/home/ubuntu/github/cutlass/test/unit/conv/device/CMakeLists.txt;0;")
