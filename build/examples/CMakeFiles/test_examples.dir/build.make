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
CMAKE_SOURCE_DIR = /home/javifdez/git_repository/Cutlass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javifdez/git_repository/Cutlass/build

# Utility rule file for test_examples.

# Include any custom commands dependencies for this target.
include examples/CMakeFiles/test_examples.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/test_examples.dir/progress.make

test_examples: examples/CMakeFiles/test_examples.dir/build.make
.PHONY : test_examples

# Rule to build all files generated by this target.
examples/CMakeFiles/test_examples.dir/build: test_examples
.PHONY : examples/CMakeFiles/test_examples.dir/build

examples/CMakeFiles/test_examples.dir/clean:
	cd /home/javifdez/git_repository/Cutlass/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/test_examples.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/test_examples.dir/clean

examples/CMakeFiles/test_examples.dir/depend:
	cd /home/javifdez/git_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repository/Cutlass /home/javifdez/git_repository/Cutlass/examples /home/javifdez/git_repository/Cutlass/build /home/javifdez/git_repository/Cutlass/build/examples /home/javifdez/git_repository/Cutlass/build/examples/CMakeFiles/test_examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/test_examples.dir/depend

