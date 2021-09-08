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

# Include any dependencies generated for this target.
include test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/flags.make

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/flags.make
test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o: ../test/unit/transform/threadblock/regular_tile_iterator_tensor_op.cu
test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o -MF CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o.d -o CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o -c /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/regular_tile_iterator_tensor_op.cu

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.i"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/regular_tile_iterator_tensor_op.cu > CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.i

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.s"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/regular_tile_iterator_tensor_op.cu -o CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.s

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/flags.make
test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o: ../test/unit/transform/threadblock/predicated_tile_iterator.cu
test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o -MF CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o.d -o CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o -c /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/predicated_tile_iterator.cu

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.i"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/predicated_tile_iterator.cu > CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.i

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.s"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock/predicated_tile_iterator.cu -o CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.s

# Object files for target cutlass_test_unit_transform_threadblock
cutlass_test_unit_transform_threadblock_OBJECTS = \
"CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o" \
"CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o"

# External object files for target cutlass_test_unit_transform_threadblock
cutlass_test_unit_transform_threadblock_EXTERNAL_OBJECTS = \
"/home/javifdez/git_repositories/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/javifdez/git_repositories/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/regular_tile_iterator_tensor_op.cu.o
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/predicated_tile_iterator.cu.o
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/build.make
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: /usr/local/cuda-10.2/lib64/libcudart.so
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock: test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cutlass_test_unit_transform_threadblock"
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_transform_threadblock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/build: test/unit/transform/threadblock/cutlass_test_unit_transform_threadblock
.PHONY : test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/build

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/clean:
	cd /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_transform_threadblock.dir/cmake_clean.cmake
.PHONY : test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/clean

test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/depend:
	cd /home/javifdez/git_repositories/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repositories/Cutlass /home/javifdez/git_repositories/Cutlass/test/unit/transform/threadblock /home/javifdez/git_repositories/Cutlass/build /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock /home/javifdez/git_repositories/Cutlass/build/test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/transform/threadblock/CMakeFiles/cutlass_test_unit_transform_threadblock.dir/depend

