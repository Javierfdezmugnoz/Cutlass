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

# Include any dependencies generated for this target.
include test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/flags.make

test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/flags.make
test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o: ../test/unit/test_unit.cpp
test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o -MF CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o.d -o CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o -c /home/javierfdez/github_repository/Cutlass/test/unit/test_unit.cpp

test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/test_unit.cpp > CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.i

test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/test_unit.cpp -o CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.s

cutlass_test_unit_infra_lib: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
cutlass_test_unit_infra_lib: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/build.make
.PHONY : cutlass_test_unit_infra_lib

# Rule to build all files generated by this target.
test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/build: cutlass_test_unit_infra_lib
.PHONY : test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/build

test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/clean:
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_infra_lib.dir/cmake_clean.cmake
.PHONY : test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/clean

test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/depend:
	cd /home/javierfdez/github_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierfdez/github_repository/Cutlass /home/javierfdez/github_repository/Cutlass/test/unit /home/javierfdez/github_repository/Cutlass/build /home/javierfdez/github_repository/Cutlass/build/test/unit /home/javierfdez/github_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/depend

