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
include test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o: ../test/unit/core/array.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/array.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/array.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/array.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/array.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/array.cu > CMakeFiles/cutlass_test_unit_core.dir/array.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/array.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/array.cu -o CMakeFiles/cutlass_test_unit_core.dir/array.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o: ../test/unit/core/half.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/half.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/half.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/half.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/half.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/half.cu > CMakeFiles/cutlass_test_unit_core.dir/half.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/half.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/half.cu -o CMakeFiles/cutlass_test_unit_core.dir/half.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o: ../test/unit/core/bfloat16.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/bfloat16.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/bfloat16.cu > CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/bfloat16.cu -o CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o: ../test/unit/core/tfloat32.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/tfloat32.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/tfloat32.cu > CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/tfloat32.cu -o CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o: ../test/unit/core/complex.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/complex.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/complex.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/complex.cu > CMakeFiles/cutlass_test_unit_core.dir/complex.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/complex.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/complex.cu -o CMakeFiles/cutlass_test_unit_core.dir/complex.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o: ../test/unit/core/quaternion.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/quaternion.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/quaternion.cu > CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/quaternion.cu -o CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o: ../test/unit/core/matrix.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/matrix.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/matrix.cu > CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/matrix.cu -o CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o: ../test/unit/core/predicate_vector.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/predicate_vector.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/predicate_vector.cu > CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/predicate_vector.cu -o CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o: ../test/unit/core/tensor_ref.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/tensor_ref.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/tensor_ref.cu > CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/tensor_ref.cu -o CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o: ../test/unit/core/tensor_view.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/tensor_view.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/tensor_view.cu > CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/tensor_view.cu -o CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o: ../test/unit/core/matrix_coord.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/matrix_coord.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/matrix_coord.cu > CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/matrix_coord.cu -o CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o: ../test/unit/core/numeric_conversion.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/numeric_conversion.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/numeric_conversion.cu > CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/numeric_conversion.cu -o CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.s

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/flags.make
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o: ../test/unit/core/functional.cu
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o -MF CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o.d -o CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o -c /home/ubuntu/github/cutlass/test/unit/core/functional.cu

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_core.dir/functional.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/core/functional.cu > CMakeFiles/cutlass_test_unit_core.dir/functional.cu.i

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_core.dir/functional.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/core/functional.cu -o CMakeFiles/cutlass_test_unit_core.dir/functional.cu.s

# Object files for target cutlass_test_unit_core
cutlass_test_unit_core_OBJECTS = \
"CMakeFiles/cutlass_test_unit_core.dir/array.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/half.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o" \
"CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o"

# External object files for target cutlass_test_unit_core
cutlass_test_unit_core_EXTERNAL_OBJECTS = \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/array.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/half.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/bfloat16.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tfloat32.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/complex.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/quaternion.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/predicate_vector.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_ref.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/tensor_view.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/matrix_coord.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/numeric_conversion.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/functional.cu.o
test/unit/core/cutlass_test_unit_core: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/core/cutlass_test_unit_core: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/build.make
test/unit/core/cutlass_test_unit_core: /usr/local/cuda-10.2/lib64/libcudart.so
test/unit/core/cutlass_test_unit_core: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/core/cutlass_test_unit_core: test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable cutlass_test_unit_core"
	cd /home/ubuntu/github/cutlass/build/test/unit/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/build: test/unit/core/cutlass_test_unit_core
.PHONY : test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/build

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/clean:
	cd /home/ubuntu/github/cutlass/build/test/unit/core && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_core.dir/cmake_clean.cmake
.PHONY : test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/clean

test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/test/unit/core /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/test/unit/core /home/ubuntu/github/cutlass/build/test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/core/CMakeFiles/cutlass_test_unit_core.dir/depend

