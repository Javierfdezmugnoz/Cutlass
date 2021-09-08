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
include examples/ES_protection/CMakeFiles/checksum_alg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/ES_protection/CMakeFiles/checksum_alg.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/ES_protection/CMakeFiles/checksum_alg.dir/progress.make

# Include the compile flags for this target's objects.
include examples/ES_protection/CMakeFiles/checksum_alg.dir/flags.make

examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o: examples/ES_protection/CMakeFiles/checksum_alg.dir/flags.make
examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o: ../examples/ES_protection/checksum.cu
examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o: examples/ES_protection/CMakeFiles/checksum_alg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection && /usr/local/cuda-10.2/bin/nvcc -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -MD -MT examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o -MF CMakeFiles/checksum_alg.dir/checksum.cu.o.d -x cu -c /home/javifdez/git_repositories/Cutlass/examples/ES_protection/checksum.cu -o CMakeFiles/checksum_alg.dir/checksum.cu.o

examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/checksum_alg.dir/checksum.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/checksum_alg.dir/checksum.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target checksum_alg
checksum_alg_OBJECTS = \
"CMakeFiles/checksum_alg.dir/checksum.cu.o"

# External object files for target checksum_alg
checksum_alg_EXTERNAL_OBJECTS =

examples/ES_protection/libchecksum_algd.a: examples/ES_protection/CMakeFiles/checksum_alg.dir/checksum.cu.o
examples/ES_protection/libchecksum_algd.a: examples/ES_protection/CMakeFiles/checksum_alg.dir/build.make
examples/ES_protection/libchecksum_algd.a: examples/ES_protection/CMakeFiles/checksum_alg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/javifdez/git_repositories/Cutlass/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA static library libchecksum_algd.a"
	cd /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection && $(CMAKE_COMMAND) -P CMakeFiles/checksum_alg.dir/cmake_clean_target.cmake
	cd /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checksum_alg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/ES_protection/CMakeFiles/checksum_alg.dir/build: examples/ES_protection/libchecksum_algd.a
.PHONY : examples/ES_protection/CMakeFiles/checksum_alg.dir/build

examples/ES_protection/CMakeFiles/checksum_alg.dir/clean:
	cd /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection && $(CMAKE_COMMAND) -P CMakeFiles/checksum_alg.dir/cmake_clean.cmake
.PHONY : examples/ES_protection/CMakeFiles/checksum_alg.dir/clean

examples/ES_protection/CMakeFiles/checksum_alg.dir/depend:
	cd /home/javifdez/git_repositories/Cutlass/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/javifdez/git_repositories/Cutlass /home/javifdez/git_repositories/Cutlass/examples/ES_protection /home/javifdez/git_repositories/Cutlass/build /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection /home/javifdez/git_repositories/Cutlass/build/examples/ES_protection/CMakeFiles/checksum_alg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/ES_protection/CMakeFiles/checksum_alg.dir/depend
