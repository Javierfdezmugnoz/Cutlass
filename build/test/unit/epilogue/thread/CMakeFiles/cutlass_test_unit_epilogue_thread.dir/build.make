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

# Include any dependencies generated for this target.
include test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/flags.make

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/flags.make
test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o: ../test/unit/epilogue/thread/linear_combination.cu
test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination.cu

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination.cu > CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.i

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination.cu -o CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.s

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/flags.make
test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o: ../test/unit/epilogue/thread/linear_combination_planar_complex.cu
test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination_planar_complex.cu

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination_planar_complex.cu > CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.i

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/thread/linear_combination_planar_complex.cu -o CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.s

# Object files for target cutlass_test_unit_epilogue_thread
cutlass_test_unit_epilogue_thread_OBJECTS = \
"CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o"

# External object files for target cutlass_test_unit_epilogue_thread
cutlass_test_unit_epilogue_thread_EXTERNAL_OBJECTS = \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination.cu.o
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/linear_combination_planar_complex.cu.o
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/build.make
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: /usr/local/cuda-10.2/lib64/libcudart.so
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread: test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cutlass_test_unit_epilogue_thread"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_epilogue_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/build: test/unit/epilogue/thread/cutlass_test_unit_epilogue_thread
.PHONY : test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/build

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/clean:
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_epilogue_thread.dir/cmake_clean.cmake
.PHONY : test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/clean

test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/test/unit/epilogue/thread /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread /home/ubuntu/github/cutlass/build/test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/epilogue/thread/CMakeFiles/cutlass_test_unit_epilogue_thread.dir/depend

