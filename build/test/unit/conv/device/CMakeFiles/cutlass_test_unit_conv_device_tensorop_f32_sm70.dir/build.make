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

# Include any dependencies generated for this target.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/flags.make

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: ../test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -c /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu > CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: ../test/unit/conv/device/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -c /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu > CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: ../test/unit/conv/device/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o -c /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu > CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu -o CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.s

# Object files for target cutlass_test_unit_conv_device_tensorop_f32_sm70
cutlass_test_unit_conv_device_tensorop_f32_sm70_OBJECTS = \
"CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o"

# External object files for target cutlass_test_unit_conv_device_tensorop_f32_sm70
cutlass_test_unit_conv_device_tensorop_f32_sm70_EXTERNAL_OBJECTS = \
"/home/javifdez/git_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/javifdez/git_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_dgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/conv2d_wgrad_implicit_gemm_f16nhwc_f16nhwc_f32nhwc_tensor_op_f32_sm70.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/build.make
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: /usr/local/cuda-10.2/lib64/libcudart.so
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javifdez/git_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cutlass_test_unit_conv_device_tensorop_f32_sm70"
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/build: test/unit/conv/device/cutlass_test_unit_conv_device_tensorop_f32_sm70
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/build

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/clean:
	cd /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/cmake_clean.cmake
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/clean

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/depend:
	cd /home/javifdez/git_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repository/Cutlass /home/javifdez/git_repository/Cutlass/test/unit/conv/device /home/javifdez/git_repository/Cutlass/build /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device /home/javifdez/git_repository/Cutlass/build/test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_tensorop_f32_sm70.dir/depend

