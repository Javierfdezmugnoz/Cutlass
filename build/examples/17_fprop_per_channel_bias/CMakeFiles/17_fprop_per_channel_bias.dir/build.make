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
include examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/progress.make

# Include the compile flags for this target's objects.
include examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/flags.make

examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o: examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/flags.make
examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o: ../examples/17_fprop_per_channel_bias/fprop_per_channel_bias.cu
examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o: examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o -MF CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o.d -o CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o -c /home/javifdez/git_repositories/Cutlass/examples/17_fprop_per_channel_bias/fprop_per_channel_bias.cu

examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.i"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javifdez/git_repositories/Cutlass/examples/17_fprop_per_channel_bias/fprop_per_channel_bias.cu > CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.i

examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.s"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javifdez/git_repositories/Cutlass/examples/17_fprop_per_channel_bias/fprop_per_channel_bias.cu -o CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.s

# Object files for target 17_fprop_per_channel_bias
17_fprop_per_channel_bias_OBJECTS = \
"CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o"

# External object files for target 17_fprop_per_channel_bias
17_fprop_per_channel_bias_EXTERNAL_OBJECTS =

examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/fprop_per_channel_bias.cu.o
examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/build.make
examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias: /usr/local/cuda-10.2/lib64/libcudart.so
examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias: examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 17_fprop_per_channel_bias"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/17_fprop_per_channel_bias.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/build: examples/17_fprop_per_channel_bias/17_fprop_per_channel_bias
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/build

examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/clean:
	cd /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias && $(CMAKE_COMMAND) -P CMakeFiles/17_fprop_per_channel_bias.dir/cmake_clean.cmake
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/clean

examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/depend:
	cd /home/javifdez/git_repositories/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repositories/Cutlass /home/javifdez/git_repositories/Cutlass/examples/17_fprop_per_channel_bias /home/javifdez/git_repositories/Cutlass/build /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias /home/javifdez/git_repositories/Cutlass/build/examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/17_fprop_per_channel_bias/CMakeFiles/17_fprop_per_channel_bias.dir/depend

