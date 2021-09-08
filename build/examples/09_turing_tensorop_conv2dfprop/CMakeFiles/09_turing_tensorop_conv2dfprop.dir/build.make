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
include examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/progress.make

# Include the compile flags for this target's objects.
include examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/flags.make

examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o: examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/flags.make
examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o: ../examples/09_turing_tensorop_conv2dfprop/turing_tensorop_conv2dfprop.cu
examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o: examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o -MF CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o.d -o CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o -c /home/javifdez/git_repositories/Cutlass/examples/09_turing_tensorop_conv2dfprop/turing_tensorop_conv2dfprop.cu

examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.i"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repositories/Cutlass/examples/09_turing_tensorop_conv2dfprop/turing_tensorop_conv2dfprop.cu > CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.i

examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.s"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repositories/Cutlass/examples/09_turing_tensorop_conv2dfprop/turing_tensorop_conv2dfprop.cu -o CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.s

# Object files for target 09_turing_tensorop_conv2dfprop
09_turing_tensorop_conv2dfprop_OBJECTS = \
"CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o"

# External object files for target 09_turing_tensorop_conv2dfprop
09_turing_tensorop_conv2dfprop_EXTERNAL_OBJECTS =

examples/09_turing_tensorop_conv2dfprop/09_turing_tensorop_conv2dfprop: examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/turing_tensorop_conv2dfprop.cu.o
examples/09_turing_tensorop_conv2dfprop/09_turing_tensorop_conv2dfprop: examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/build.make
examples/09_turing_tensorop_conv2dfprop/09_turing_tensorop_conv2dfprop: /usr/local/cuda-10.2/lib64/libcudart.so
examples/09_turing_tensorop_conv2dfprop/09_turing_tensorop_conv2dfprop: examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 09_turing_tensorop_conv2dfprop"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/09_turing_tensorop_conv2dfprop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/build: examples/09_turing_tensorop_conv2dfprop/09_turing_tensorop_conv2dfprop
.PHONY : examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/build

examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/clean:
	cd /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop && $(CMAKE_COMMAND) -P CMakeFiles/09_turing_tensorop_conv2dfprop.dir/cmake_clean.cmake
.PHONY : examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/clean

examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/depend:
	cd /home/javifdez/git_repositories/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repositories/Cutlass /home/javifdez/git_repositories/Cutlass/examples/09_turing_tensorop_conv2dfprop /home/javifdez/git_repositories/Cutlass/build /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop /home/javifdez/git_repositories/Cutlass/build/examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/09_turing_tensorop_conv2dfprop/CMakeFiles/09_turing_tensorop_conv2dfprop.dir/depend

