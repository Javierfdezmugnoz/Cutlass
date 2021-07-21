# Install script for directory: /home/ubuntu/github/cutlass/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/github/cutlass/build/examples/00_basic_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/01_cutlass_utilities/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/02_dump_reg_shmem/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/03_visualize_layout/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/04_tile_iterator/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/05_batched_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/06_splitK_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/07_volta_tensorop_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/08_turing_tensorop_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/09_turing_tensorop_conv2dfprop/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/10_planar_complex/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/11_planar_complex_array/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/12_gemm_bias_relu/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/13_two_tensor_op_fusion/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/14_ampere_tf32_tensorop_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/15_ampere_sparse_tensorop_gemm/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/16_ampere_tensorop_conv2dfprop/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/17_fprop_per_channel_bias/cmake_install.cmake")
  include("/home/ubuntu/github/cutlass/build/examples/18_Sim_test/cmake_install.cmake")

endif()

