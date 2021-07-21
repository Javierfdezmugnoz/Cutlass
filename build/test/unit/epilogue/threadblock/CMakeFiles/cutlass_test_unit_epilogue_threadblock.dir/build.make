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
include test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o: ../test/unit/epilogue/threadblock/predicated_tile_iterator.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/predicated_tile_iterator.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/predicated_tile_iterator.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/predicated_tile_iterator.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o: ../test/unit/epilogue/threadblock/output_tile_threadmap.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/output_tile_threadmap.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/output_tile_threadmap.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/output_tile_threadmap.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o: ../test/unit/epilogue/threadblock/epilogue_simt.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o: ../test/unit/epilogue/threadblock/epilogue_simt_sm60.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm60.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm60.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm60.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o: ../test/unit/epilogue/threadblock/epilogue_simt_sm61.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm61.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm61.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_simt_sm61.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o: ../test/unit/epilogue/threadblock/epilogue_tensor_op.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_tensor_op.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_tensor_op.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_tensor_op.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o: ../test/unit/epilogue/threadblock/epilogue_volta_tensor_op.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_volta_tensor_op.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_volta_tensor_op.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_volta_tensor_op.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o: ../test/unit/epilogue/threadblock/epilogue_wmma_tensor_op_sm70.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_wmma_tensor_op_sm70.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_wmma_tensor_op_sm70.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_wmma_tensor_op_sm70.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.s

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/flags.make
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o: ../test/unit/epilogue/threadblock/epilogue_planar_complex.cu
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o -MF CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o.d -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o -c /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_planar_complex.cu

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.i"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_planar_complex.cu > CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.i

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.s"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock/epilogue_planar_complex.cu -o CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.s

# Object files for target cutlass_test_unit_epilogue_threadblock
cutlass_test_unit_epilogue_threadblock_OBJECTS = \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o" \
"CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o"

# External object files for target cutlass_test_unit_epilogue_threadblock
cutlass_test_unit_epilogue_threadblock_EXTERNAL_OBJECTS = \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/ubuntu/github/cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/predicated_tile_iterator.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/output_tile_threadmap.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm60.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_simt_sm61.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_tensor_op.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_volta_tensor_op.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_wmma_tensor_op_sm70.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/epilogue_planar_complex.cu.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/build.make
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: /usr/local/cuda-10.2/lib64/libcudart.so
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock: test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/github/cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable cutlass_test_unit_epilogue_threadblock"
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/build: test/unit/epilogue/threadblock/cutlass_test_unit_epilogue_threadblock
.PHONY : test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/build

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/clean:
	cd /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/cmake_clean.cmake
.PHONY : test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/clean

test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/depend:
	cd /home/ubuntu/github/cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/github/cutlass /home/ubuntu/github/cutlass/test/unit/epilogue/threadblock /home/ubuntu/github/cutlass/build /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock /home/ubuntu/github/cutlass/build/test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/epilogue/threadblock/CMakeFiles/cutlass_test_unit_epilogue_threadblock.dir/depend

