# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/github/cutlass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/github/cutlass/build

# Utility rule file for test_examples_00_basic_gemm.

# Include any custom commands dependencies for this target.
include examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/progress.make

examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm: examples/00_basic_gemm/00_basic_gemm
	cd /home/ubuntu/github/cutlass/build/examples/00_basic_gemm && ./00_basic_gemm

test_examples_00_basic_gemm: examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm
test_examples_00_basic_gemm: examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/build.make
.PHONY : test_examples_00_basic_gemm

# Rule to build all files generated by this target.
examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/build: test_examples_00_basic_gemm
.PHONY : examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/build

examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/clean:
	cd /home/ubuntu/github/cutlass/build/examples/00_basic_gemm && $(CMAKE_COMMAND) -P CMakeFiles/test_examples_00_basic_gemm.dir/cmake_clean.cmake
.PHONY : examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/clean

examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/examples/00_basic_gemm /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/examples/00_basic_gemm /home/ubuntu/github/cutlass/build/examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/00_basic_gemm/CMakeFiles/test_examples_00_basic_gemm.dir/depend

