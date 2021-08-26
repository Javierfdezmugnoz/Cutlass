# CMake generated Testfile for 
# Source directory: /home/javierfdez/github_repository/Cutlass/tools/profiler
# Build directory: /home/javierfdez/github_repository/Cutlass/build/tools/profiler
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ctest_profiler_0 "/home/javierfdez/github_repository/Cutlass/build/tools/profiler/cutlass_profiler" "--operation=Gemm" "--providers=cutlass" "--verification-providers=cublas,device" "--junit-output=test_cutlass_profiler_gemm")
set_tests_properties(ctest_profiler_0 PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;91;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;0;")
add_test(ctest_profiler_1 "/home/javierfdez/github_repository/Cutlass/build/tools/profiler/cutlass_profiler" "--operation=Conv2d" "--providers=cutlass" "--verification-providers=cudnn,device" "--junit-output=test_cutlass_profiler_conv2d")
set_tests_properties(ctest_profiler_1 PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;91;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;0;")
add_test(ctest_profiler_2 "/home/javierfdez/github_repository/Cutlass/build/tools/profiler/cutlass_profiler" "--operation=Conv3d" "--providers=cutlass" "--verification-providers=cudnn,device,host" "--junit-output=test_cutlass_profiler_conv3d")
set_tests_properties(ctest_profiler_2 PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;91;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;0;")
add_test(ctest_profiler_3 "/home/javierfdez/github_repository/Cutlass/build/tools/profiler/cutlass_profiler" "--operation=SparseGemm" "--providers=cutlass" "--verification-providers=cublas,device,host" "--junit-output=test_cutlass_profiler_spgemm")
set_tests_properties(ctest_profiler_3 PROPERTIES  _BACKTRACE_TRIPLES "/home/javierfdez/github_repository/Cutlass/CMakeLists.txt;608;add_test;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;91;cutlass_add_executable_tests;/home/javierfdez/github_repository/Cutlass/tools/profiler/CMakeLists.txt;0;")
