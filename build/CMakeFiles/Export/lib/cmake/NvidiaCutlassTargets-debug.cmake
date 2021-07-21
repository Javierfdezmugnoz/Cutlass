#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nvidia::cutlass::library" for configuration "Debug"
set_property(TARGET nvidia::cutlass::library APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nvidia::cutlass::library PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcutlassd.so"
  IMPORTED_SONAME_DEBUG "libcutlassd.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS nvidia::cutlass::library )
list(APPEND _IMPORT_CHECK_FILES_FOR_nvidia::cutlass::library "${_IMPORT_PREFIX}/lib/libcutlassd.so" )

# Import target "nvidia::cutlass::library_static" for configuration "Debug"
set_property(TARGET nvidia::cutlass::library_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nvidia::cutlass::library_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcutlassd.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS nvidia::cutlass::library_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_nvidia::cutlass::library_static "${_IMPORT_PREFIX}/lib/libcutlassd.a" )

# Import target "nvidia::cutlass::profiler" for configuration "Debug"
set_property(TARGET nvidia::cutlass::profiler APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nvidia::cutlass::profiler PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/cutlass_profiler"
  )

list(APPEND _IMPORT_CHECK_TARGETS nvidia::cutlass::profiler )
list(APPEND _IMPORT_CHECK_FILES_FOR_nvidia::cutlass::profiler "${_IMPORT_PREFIX}/bin/cutlass_profiler" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
