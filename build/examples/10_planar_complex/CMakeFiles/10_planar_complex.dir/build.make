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
include examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/progress.make

# Include the compile flags for this target's objects.
include examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/flags.make

examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o: examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/flags.make
examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o: ../examples/10_planar_complex/planar_complex.cu
examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o: examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o"
	cd /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o -MF CMakeFiles/10_planar_complex.dir/planar_complex.cu.o.d -o CMakeFiles/10_planar_complex.dir/planar_complex.cu.o -c /home/javierfdez/github_repository/Cutlass/examples/10_planar_complex/planar_complex.cu

examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10_planar_complex.dir/planar_complex.cu.i"
	cd /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/javierfdez/github_repository/Cutlass/examples/10_planar_complex/planar_complex.cu > CMakeFiles/10_planar_complex.dir/planar_complex.cu.i

examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10_planar_complex.dir/planar_complex.cu.s"
	cd /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/javierfdez/github_repository/Cutlass/examples/10_planar_complex/planar_complex.cu -o CMakeFiles/10_planar_complex.dir/planar_complex.cu.s

# Object files for target 10_planar_complex
10_planar_complex_OBJECTS = \
"CMakeFiles/10_planar_complex.dir/planar_complex.cu.o"

# External object files for target 10_planar_complex
10_planar_complex_EXTERNAL_OBJECTS =

examples/10_planar_complex/10_planar_complex: examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/planar_complex.cu.o
examples/10_planar_complex/10_planar_complex: examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/build.make
examples/10_planar_complex/10_planar_complex: tools/library/libcutlassd.so
examples/10_planar_complex/10_planar_complex: /usr/local/cuda-10.0/lib64/libcudart.so
examples/10_planar_complex/10_planar_complex: examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javierfdez/github_repository/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 10_planar_complex"
	cd /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/10_planar_complex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/build: examples/10_planar_complex/10_planar_complex
.PHONY : examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/build

examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/clean:
	cd /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex && $(CMAKE_COMMAND) -P CMakeFiles/10_planar_complex.dir/cmake_clean.cmake
.PHONY : examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/clean

examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/depend:
	cd /home/javierfdez/github_repository/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javierfdez/github_repository/Cutlass /home/javierfdez/github_repository/Cutlass/examples/10_planar_complex /home/javierfdez/github_repository/Cutlass/build /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex /home/javierfdez/github_repository/Cutlass/build/examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/10_planar_complex/CMakeFiles/10_planar_complex.dir/depend

