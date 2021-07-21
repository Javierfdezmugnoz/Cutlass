# Generated file

if (DEFINED ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT $ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
else()
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT )
endif()

if (NOT "" STREQUAL "")
  set(TEST_EXE_PATH /cutlass_profiler)
else()
  set(TEST_EXE_PATH cutlass_profiler)
endif()

add_test("ctest_profiler_2" ${_CUTLASS_TEST_EXECUTION_ENVIRONMENT} "${TEST_EXE_PATH}" --operation=Conv3d --providers=cutlass --verification-providers=cudnn,device,host --junit-output=test_cutlass_profiler_conv3d)

if (NOT "./bin" STREQUAL "")
  set_tests_properties("ctest_profiler_2" PROPERTIES WORKING_DIRECTORY "./bin")
endif()
