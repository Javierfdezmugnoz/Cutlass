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
include test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/flags.make

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/flags.make
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o: ../test/unit/layout/matrix.cu
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o -MF CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o.d -o CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/layout/matrix.cu

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/layout/matrix.cu > CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.i

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/layout/matrix.cu -o CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.s

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/flags.make
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o: ../test/unit/layout/tensor.cu
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o -MF CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o.d -o CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor.cu

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor.cu > CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.i

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor.cu -o CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.s

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/flags.make
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o: ../test/unit/layout/tensor_nhwc.cu
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o -MF CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o.d -o CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor_nhwc.cu

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor_nhwc.cu > CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.i

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/layout/tensor_nhwc.cu -o CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.s

# Object files for target cutlass_test_unit_layout
cutlass_test_unit_layout_OBJECTS = \
"CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o" \
"CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o" \
"CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o"

# External object files for target cutlass_test_unit_layout
cutlass_test_unit_layout_EXTERNAL_OBJECTS = \
"/home/javierfdez/github_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/javierfdez/github_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/layout/cutlass_test_unit_layout: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/matrix.cu.o
test/unit/layout/cutlass_test_unit_layout: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor.cu.o
test/unit/layout/cutlass_test_unit_layout: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/tensor_nhwc.cu.o
test/unit/layout/cutlass_test_unit_layout: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/layout/cutlass_test_unit_layout: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/layout/cutlass_test_unit_layout: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/build.make
test/unit/layout/cutlass_test_unit_layout: /usr/local/cuda-10.0/lib64/libcudart.so
test/unit/layout/cutlass_test_unit_layout: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/layout/cutlass_test_unit_layout: test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cutlass_test_unit_layout"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_layout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/build: test/unit/layout/cutlass_test_unit_layout
.PHONY : test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/build

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/clean:
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/layout && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_layout.dir/cmake_clean.cmake
.PHONY : test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/clean

test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/depend:
	cd /home/javierfdez/github_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierfdez/github_repository/Cutlass /home/javierfdez/github_repository/Cutlass/test/unit/layout /home/javierfdez/github_repository/Cutlass/build /home/javierfdez/github_repository/Cutlass/build/test/unit/layout /home/javierfdez/github_repository/Cutlass/build/test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/layout/CMakeFiles/cutlass_test_unit_layout.dir/depend

