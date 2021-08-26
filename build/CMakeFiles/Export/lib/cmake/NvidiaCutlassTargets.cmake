# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.18)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget nvidia::cutlass::cutlass nvidia::cutlass::tools::util nvidia::cutlass::library nvidia::cutlass::library_static nvidia::cutlass::library::includes nvidia::cutlass::profiler)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target nvidia::cutlass::cutlass
add_library(nvidia::cutlass::cutlass INTERFACE IMPORTED)

set_target_properties(nvidia::cutlass::cutlass PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target nvidia::cutlass::tools::util
add_library(nvidia::cutlass::tools::util INTERFACE IMPORTED)

set_target_properties(nvidia::cutlass::tools::util PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "\$<\$<BOOL:OFF>:cublas>"
)

# Create imported target nvidia::cutlass::library
add_library(nvidia::cutlass::library SHARED IMPORTED)

set_target_properties(nvidia::cutlass::library PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_LINK_LIBRARIES "cudart;-Wl,-rpath,'\$ORIGIN';-Wl,-rpath,'\$ORIGIN/../lib64';-Wl,-rpath,'\$ORIGIN/../lib';-Wl,-rpath,'/usr/local/cuda-10.0/lib64';-Wl,-rpath,'/usr/local/cuda-10.0/lib';nvidia::cutlass::library::includes"
)

# Create imported target nvidia::cutlass::library_static
add_library(nvidia::cutlass::library_static STATIC IMPORTED)

set_target_properties(nvidia::cutlass::library_static PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
  INTERFACE_LINK_LIBRARIES "cudart;-Wl,-rpath,'\$ORIGIN';-Wl,-rpath,'\$ORIGIN/../lib64';-Wl,-rpath,'\$ORIGIN/../lib';-Wl,-rpath,'/usr/local/cuda-10.0/lib64';-Wl,-rpath,'/usr/local/cuda-10.0/lib';nvidia::cutlass::library::includes"
)

# Create imported target nvidia::cutlass::library::includes
add_library(nvidia::cutlass::library::includes INTERFACE IMPORTED)

set_target_properties(nvidia::cutlass::library::includes PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "nvidia::cutlass::cutlass;nvidia::cutlass::tools::util"
)

# Create imported target nvidia::cutlass::profiler
add_executable(nvidia::cutlass::profiler IMPORTED)

set_target_properties(nvidia::cutlass::profiler PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_11"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/NvidiaCutlassTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
