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
CMAKE_SOURCE_DIR = /home/javifdez/git_repositories/Cutlass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/javifdez/git_repositories/Cutlass/build

# Utility rule file for test_examples_02_dump_reg_shmem.

# Include any custom commands dependencies for this target.
include examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/progress.make

examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem: examples/02_dump_reg_shmem/02_dump_reg_shmem
	cd /home/javifdez/git_repositories/Cutlass/build/examples/02_dump_reg_shmem && ./02_dump_reg_shmem

test_examples_02_dump_reg_shmem: examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem
test_examples_02_dump_reg_shmem: examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/build.make
.PHONY : test_examples_02_dump_reg_shmem

# Rule to build all files generated by this target.
examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/build: test_examples_02_dump_reg_shmem
.PHONY : examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/build

examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/clean:
	cd /home/javifdez/git_repositories/Cutlass/build/examples/02_dump_reg_shmem && $(CMAKE_COMMAND) -P CMakeFiles/test_examples_02_dump_reg_shmem.dir/cmake_clean.cmake
.PHONY : examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/clean

examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/depend:
	cd /home/javifdez/git_repositories/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repositories/Cutlass /home/javifdez/git_repositories/Cutlass/examples/02_dump_reg_shmem /home/javifdez/git_repositories/Cutlass/build /home/javifdez/git_repositories/Cutlass/build/examples/02_dump_reg_shmem /home/javifdez/git_repositories/Cutlass/build/examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/02_dump_reg_shmem/CMakeFiles/test_examples_02_dump_reg_shmem.dir/depend

