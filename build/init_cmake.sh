#!/bin/bash

echo "NAME: $4"
echo "MATRIX_DIM = [$5,$6,$7]"
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCUTLASS_NVCC_ARCHS=53 -DCUTLASS_ENABLE_CUBLAS=OFF -DCUTLASS_ENABLE_CUDNN=OFF -Wno-dev -DCUDA_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CUDA_FLAGS=-O0 -DEXTERNAL_ES=$1 -DINTERMEDIATE_ES=$2 -DINTERNAL_ES=$3 -DNAME=$4 -DDIM_M=$5 -DDIM_N=$6 -DDIM_K=$7

cp ../time_measurement.sh examples/18_Sim_test/.
cp ../convergence.sh examples/18_Sim_test/.
cd examples/18_Sim_test

