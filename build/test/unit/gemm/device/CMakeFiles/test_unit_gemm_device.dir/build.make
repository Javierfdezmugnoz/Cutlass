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
CMAKE_SOURCE_DIR = /home/javierfdez/github_repository/Cutlass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javierfdez/github_repository/Cutlass/build

# Utility rule file for test_unit_gemm_device.

# Include any custom commands dependencies for this target.
include test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/progress.make

test/unit/gemm/device/CMakeFiles/test_unit_gemm_device:

test_unit_gemm_device: test/unit/gemm/device/CMakeFiles/test_unit_gemm_device
test_unit_gemm_device: test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/build.make
.PHONY : test_unit_gemm_device

# Rule to build all files generated by this target.
test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/build: test_unit_gemm_device
.PHONY : test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/build

test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/clean:
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/device && $(CMAKE_COMMAND) -P CMakeFiles/test_unit_gemm_device.dir/cmake_clean.cmake
.PHONY : test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/clean

test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/depend:
	cd /home/javierfdez/github_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierfdez/github_repository/Cutlass /home/javierfdez/github_repository/Cutlass/test/unit/gemm/device /home/javierfdez/github_repository/Cutlass/build /home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/device /home/javierfdez/github_repository/Cutlass/build/test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/gemm/device/CMakeFiles/test_unit_gemm_device.dir/depend

