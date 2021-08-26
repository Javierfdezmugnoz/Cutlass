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
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o: ../test/unit/conv/device/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu > CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: ../test/unit/conv/device/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu > CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: ../test/unit/conv/device/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu > CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: ../test/unit/conv/device/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu > CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.s

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/flags.make
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o: ../test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o -MF CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o.d -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o -c /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu > CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.i

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/test/unit/conv/device/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu -o CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.s

# Object files for target cutlass_test_unit_conv_device_simt
cutlass_test_unit_conv_device_simt_OBJECTS = \
"CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o" \
"CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o"

# External object files for target cutlass_test_unit_conv_device_simt
cutlass_test_unit_conv_device_simt_EXTERNAL_OBJECTS = \
"/home/javierfdez/github_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o" \
"/home/javierfdez/github_repository/Cutlass/build/test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o"

test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f32nhwc_f32nhwc_f32nhwc_simt_f32_sm50.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_dgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_wgrad_implicit_gemm_cf32nhwc_cf32nhwc_cf32nhwc_simt_f32_sm50.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/conv2d_fprop_implicit_gemm_f16nhwc_f16nhwc_f16nhwc_simt_f16_sm60.cu.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/CMakeFiles/cutlass_test_unit_infra.dir/common/filter_architecture.cpp.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/CMakeFiles/cutlass_test_unit_infra_lib.dir/test_unit.cpp.o
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/build.make
test/unit/conv/device/cutlass_test_unit_conv_device_simt: /usr/local/cuda-10.0/lib64/libcudart.so
test/unit/conv/device/cutlass_test_unit_conv_device_simt: _deps/googletest-build/googlemock/gtest/libgtestd.a
test/unit/conv/device/cutlass_test_unit_conv_device_simt: test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable cutlass_test_unit_conv_device_simt"
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cutlass_test_unit_conv_device_simt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/build: test/unit/conv/device/cutlass_test_unit_conv_device_simt
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/build

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/clean:
	cd /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device && $(CMAKE_COMMAND) -P CMakeFiles/cutlass_test_unit_conv_device_simt.dir/cmake_clean.cmake
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/clean

test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/depend:
	cd /home/javierfdez/github_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierfdez/github_repository/Cutlass /home/javierfdez/github_repository/Cutlass/test/unit/conv/device /home/javierfdez/github_repository/Cutlass/build /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device /home/javierfdez/github_repository/Cutlass/build/test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/unit/conv/device/CMakeFiles/cutlass_test_unit_conv_device_simt.dir/depend

