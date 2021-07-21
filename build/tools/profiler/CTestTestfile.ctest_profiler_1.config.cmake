# Generated file

if (DEFINED ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT $ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
else()
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT )
endif()

if (NOT "" STREQUAL "")
  set(TEST_EXE_PATH /$<TARGET_FILE_NAME:cutlass_profiler>)
else()
  set(TEST_EXE_PATH $<TARGET_FILE_NAME:cutlass_profiler>)
endif()

add_test("ctest_profiler_1" ${_CUTLASS_TEST_EXECUTION_ENVIRONMENT} "${TEST_EXE_PATH}" --operation=Conv2d --providers=cutlass --verification-providers=cudnn,device --junit-output=test_cutlass_profiler_conv2d)

if (NOT "./bin" STREQUAL "")
  set_tests_properties("ctest_profiler_1" PROPERTIES WORKING_DIRECTORY "./bin")
endif()
