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

# Utility rule file for test_unit_epilogue_thread.

# Include any custom commands dependencies for this target.
include test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/progress.make

test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread: test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && ./cutlass_test_unit_epilogue_thread --gtest_output=xml:test_unit_epilogue_thread.gtest.xml

test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread
test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/build.make
.PHONY : test_unit_epilogue_thread

# Rule to build all files generated by this target.
test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/build: test_unit_epilogue_thread
.PHONY : test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/build

test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/clean:
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && $(CMAKE_COMMAND) -P CMakeFiles/test_unit_epilogue_thread.dir/cmake_clean.cmake
.PHONY : test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/clean

test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/test/unit/epilogue/thread /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/epilogue/thread/CMakeFiles/test_unit_epilogue_thread.dir/depend

