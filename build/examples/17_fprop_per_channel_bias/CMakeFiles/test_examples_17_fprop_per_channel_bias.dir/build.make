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

# Utility rule file for test_examples_17_fprop_per_channel_bias.

# Include any custom commands dependencies for this target.
include examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/progress.make

examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias
	cd /home/ubuntu/github/cutlass/build/examples/17_fprop_per_channel_bias && ./17_fprop_per_channel_bias

test_examples_17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias
test_examples_17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/build.make
.PHONY : test_examples_17_fprop_per_channel_bias

# Rule to build all files generated by this target.
examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/build: test_examples_17_fprop_per_channel_bias
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/build

examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/clean:
	cd /home/ubuntu/github/cutlass/build/examples/17_fprop_per_channel_bias && $(CMAKE_COMMAND) -P CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/cmake_clean.cmake
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/clean

examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/examples/17_fprop_per_channel_bias /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/examples/17_fprop_per_channel_bias /home/ubuntu/github/cutlass/build/examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/test_examples_17_fprop_per_channel_bias.dir/depend

