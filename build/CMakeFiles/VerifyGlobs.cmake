# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.20
cmake_policy(SET CMP0009 NEW)

# GENERATOR_PYTHON_SOURCES at tools/library/CMakeLists.txt:77 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/*.py")
set(OLD_GLOB
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/conv2d_operation.py"
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/conv3d_operation.py"
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/gemm_operation.py"
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/generator.py"
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/library.py"
  "/home/javierfdez/github_repository/Cutlass/tools/library/scripts/manifest.py"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/javierfdez/github_repository/Cutlass/build/CMakeFiles/cmake.verify_globs")
endif()
