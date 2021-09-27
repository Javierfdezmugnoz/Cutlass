#!/bin/bash

# Define an enum type
TECH_NO_ED=0
TECH_XOR_EXTERNAL=1
TECH_XOR_INTERMEDIATE=2
TECH_XOR_INTERNAL=3
TECH_ONES_EXTERNAL=4
TECH_ONES_INTERMEDIATE=5
TECH_ONES_INTERNAL=6
TECH_TWOS_EXTERNAL=7
TECH_TWOS_INTERMEDIATE=8
TECH_TWOS_INTERNAL=9
TECH_FLETCHER_EXTERNAL=10
TECH_FLETCHER_INTERMEDIATE=11
TECH_FLETCHER_INTERNAL=12
TECH_CRC_EXTERNAL=13
TECH_CRC_INTERMEDIATE=14
TECH_CRC_INTERNAL=15
TECH_XOR_FLET=16
TECH_XOR_CRC=17
TECH_ONES_FLET=18
TECH_ONES_CRC=19
TECH_TWOS_FLET=20
TECH_TWOS_CRC=21
TECH_FLET_CRC=22


UNPROTECTED=0
XOR_CHECKSUM=1
ONES_CHECKSUM=2
TWOS_CHECKSUM=3
FLETCHER_CHECKSUM=4
CRC_CHECKSUM=5

TIMING_EXPERIMENT=$1
DC_EXPERIMENT=$2
ES_EXP=$3

OPTIMIZATION_FLAG="-O0"

# Define an enum type with the kind of memory
 for j_loop in 80 #80 160 320 128 #160 256 320 #20 40 80 #80 160 320 128 256 #80 160 320 128 256 512 # 
        do
        mkdir timing_measurements/$j_loop
        for i_loop in `seq $TECH_NO_ED 1 $TECH_XOR_INTERMEDIATE` #0 1 ${TECH_NO_ED}` #${TECH_FLET_CRC}
        do
                case $i_loop in
                $TECH_NO_ED)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_NO_ED
                ;;
                $TECH_XOR_EXTERNAL)
                        EXTERNAL_ES=$XOR_CHECKSUM
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_XOR_EXTERNAL
                ;;
                $TECH_XOR_INTERMEDIATE)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$XOR_CHECKSUM
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_XOR_INTERMEDIATE
                ;;
                $TECH_XOR_INTERNAL)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$XOR_CHECKSUM
                        NAME=TECH_XOR_INTERNAL
                ;;
                $TECH_ONES_EXTERNAL)
                        EXTERNAL_ES=$ONES_CHECKSUM
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_ONES_EXTERNAL
               ;;
                $TECH_ONES_INTERMEDIATE)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$ONES_CHECKSUM
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_ONES_INTERMEDIATE
                ;;
                $TECH_ONES_INTERNAL)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$ONES_CHECKSUM
                        NAME=TECH_ONES_INTERNAL
                ;;
                $TECH_TWOS_EXTERNAL)
                        EXTERNAL_ES=$TWOS_CHECKSUM
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_TWOS_EXTERNAL
                ;;
                $TECH_TWOS_INTERMEDIATE)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$TWOS_CHECKSUM
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_TWOS_INTERMEDIATE
                ;;
                 $TECH_TWOS_INTERNAL)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$TWOS_CHECKSUM
                        NAME=TECH_TWOS_INTERNAL
                ;;
                $TECH_FLETCHER_EXTERNAL)
                        EXTERNAL_ES=$FLETCHER_CHECKSUM
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_FLETCHER_EXTERNAL
                ;;
                $TECH_FLETCHER_INTERMEDIATE)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$FLETCHER_CHECKSUM
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_FLETCHER_INTERMEDIATE
                ;;
                $TECH_FLETCHER_INTERNAL)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$FLETCHER_CHECKSUM
                        NAME=TECH_FLETCHER_INTERNAL
                ;;
                $TECH_CRC_EXTERNAL)
                        EXTERNAL_ES=$CRC_CHECKSUM
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_CRC_EXTERNAL
                ;;
                $TECH_CRC_INTERMEDIATE)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$CRC_CHECKSUM
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_CRC_INTERMEDIATE
                ;;
                $TECH_CRC_INTERNAL)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$CRC_CHECKSUM
                        NAME=TECH_CRC_INTERNAL
                ;;
                $TECH_XOR_FLET)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$FLETCHER_CHECKSUM
                        INTERNAL_ES=$XOR_CHECKSUM
                        NAME=TECH_XOR_FLET
                ;;
                $TECH_XOR_CRC)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$CRC_CHECKSUM
                        INTERNAL_ES=$XOR_CHECKSUM
                        NAME=TECH_XOR_CRC
                ;;
                $TECH_ONES_FLET)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$FLETCHER_CHECKSUM
                        INTERNAL_ES=$ONES_CHECKSUM
                        NAME=TECH_ONES_FLET
                ;;
                $TECH_ONES_CRC)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$CRC_CHECKSUM
                        INTERNAL_ES=$ONES_CHECKSUM
                        NAME=TECH_ONES_CRC
                ;;
                $TECH_TWOS_FLET)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$FLETCHER_CHECKSUM
                        INTERNAL_ES=$TWOS_CHECKSUM
                        NAME=TECH_TWOS_FLET
                ;;
                $TECH_TWOS_CRC)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$CRC_CHECKSUM
                        INTERNAL_ES=$TWOS_CHECKSUM
                        NAME=TECH_TWOS_CRC
               ;;
                $TECH_FLET_CRC)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$CRC_CHECKSUM
                        INTERNAL_ES=$FLETCHER_CHECKSUM
                        NAME=TECH_FLET_CRC
                ;;
                esac
                rm -rf build
                mkdir build
                cd build/.
                cmake .. -DCMAKE_BUILD_TYPE=Debug -DCUTLASS_NVCC_ARCHS=72 -DCUTLASS_ENABLE_CUBLAS=OFF -DCUTLASS_ENABLE_CUDNN=OFF -Wno-dev -DCUDA_COMPILER=clang -DCUTLASS_CUDA_CLANG_FLAGS=$OPTIMIZATION_FLAG -DCMAKE_CXX_COMPILER=clang++ -DEXTERNAL_ES=$EXTERNAL_ES -DINTERMEDIATE_ES=$INTERMEDIATE_ES -DINTERNAL_ES=$INTERNAL_ES -DNAME=$i_loop"_"$NAME -DDIM_M=$j_loop -DDIM_N=$j_loop -DDIM_K=$j_loop -DTIMING_EXP=$TIMING_EXPERIMENT -DDC_EXP=$DC_EXPERIMENT -DES_EXP=$ES_EXP
                echo "NAME: $i_loop"_"$NAME"
                echo "MATRIX_DIM = [$j_loop,$j_loop,$j_loop]"
                echo "[TIMING,DC,ES_OPT]=[$1,$2,$3]"
                cd examples/18_Sim_test/.
                cmake --build . --clean-first
                sudo ./18_Simt
                mv ./${j_loop}"_"${j_loop}"_"${j_loop}"_"$i_loop"_"${NAME} ../../../timing_measurements/$j_loop/.
                cd ../../../.
        done
        cp convergence.sh timing_measurements/${j_loop}/.
        cd timing_measurements/$j_loop/.
	bash convergence.sh $j_loop $OPTIMIZATION_FLAG
done










        