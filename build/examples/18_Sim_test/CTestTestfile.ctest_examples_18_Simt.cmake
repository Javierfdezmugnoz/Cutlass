# Generated file

if (DEFINED ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT $ENV{CUTLASS_TEST_EXECUTION_ENVIRONMENT})
else()
  set(_CUTLASS_TEST_EXECUTION_ENVIRONMENT )
endif()

if (NOT "" STREQUAL "")
  set(TEST_EXE_PATH /18_Simt)
else()
  set(TEST_EXE_PATH 18_Simt)
endif()

add_test("ctest_examples_18_Simt" ${_CUTLASS_TEST_EXECUTION_ENVIRONMENT} "${TEST_EXE_PATH}" )

if (NOT "./bin" STREQUAL "")
  set_tests_properties("ctest_examples_18_Simt" PROPERTIES WORKING_DIRECTORY "./bin")
endif()
