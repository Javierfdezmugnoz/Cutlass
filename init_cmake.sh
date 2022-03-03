#!/bin/bash
PATH2RESULTS=$PWD"/exp_results"
PATH2ROOT=$PWD
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
# TECH_XOR_INTERNAL=1
# TECH_ONES_INTERNAL=2
# TECH_TWOS_INTERNAL=3
# TECH_FLETCHER_INTERNAL=4
# TECH_CRC_INTERNAL=5

UNPROTECTED=0
XOR_CHECKSUM=1
ONES_CHECKSUM=2
TWOS_CHECKSUM=3
FLETCHER_CHECKSUM=4
CRC_CHECKSUM=5

TIMING_EXPERIMENT=$1
DC_EXPERIMENT=$2
ES_EXP=$3

OPTIMIZATION_FLAG="O3"

#ARRAYS WITH THE DIMENSION OF THE EXPERIMENTS
tm_square1=(80 80 80)
tm_square2=(160 160 160)
tm_square3=(320 320 320)
tm_unbalanced1=(18 230400 64)
tm_unbalanced2=(1024 900 468)
tm_unbalanced3=(128 14400 128)
tm_unbalanced4=(256 3600 768)

dc_square1=(20 20 20)
dc_square2=(40 40 40)
dc_square3=(80 80 80)
dc_unbalanced1=(32 29 144)
dc_unbalanced2=(8 900 8)
dc_unbalanced3=(15 225 48)
dc_unbalanced4=(1024 900 468)
dc_unbalanced5=(128 14400 128)
dc_unbalanced6=(256 3600 768)

dc_unbalanced7=(16 25 4)
dc_unbalanced8=(128 200 32)


#tm_arrays=('tm_square1' 'tm_square2' 'tm_square3' 'tm_unbalanced1' 'tm_unbalanced2' 'tm_unbalanced3' 'tm_unbalanced4')
tm_arrays=('tm_unbalanced5' 'tm_unbalanced6')

dc_arrays=('dc_unbalanced8')
#dc_arrays=( 'dc_square1' 'dc_square2' 'dc_square3' 'dc_unbalanced1' 'dc_unbalanced2' 'dc_unbalanced3' 'dc_unbalanced4' 'dc_unbalanced5' 'dc_unbalanced6')

# New phase: YOLO-v3 tiny evaluation
layer_2=(2 2704 9)
layer_3=(4 676 18)
layer_4=(8 169 36)
layer_11=(128 169 256)

# layer_1=( )
# layer_5=( )
# layer_6=( )
# layer_7=( )
# layer_8=( )
# layer_9=( )
# layer_10=( )
# layer_12=( )
# layer_13=( )
# dc_arrays_tiny=('layer_1' 'layer_2' 'layer_3' 'layer_4' 'layer_5' 'layer_6' 'layer_7' 'layer_8' 'layer_9' 'layer_10' 'layer_11' 'layer_12' 'layer_13')
# dc_arrays_tiny=('layer_2' 'layer_3' 'layer_4' 'layer_11')
dc_arrays_tiny=('layer_2')



if [ $TIMING_EXPERIMENT -eq 1 ]
        then
                declare -n arr=tm_arrays
        else
                #declare -n arr=dc_arrays
                declare -n arr=dc_arrays_tiny
fi

        for j_loop in "${arr[@]}"
        do
        declare -n M_DIM="$j_loop[0]"
        declare -n N_DIM="$j_loop[1]"
        declare -n K_DIM="$j_loop[2]"
        FOLDER_NAME=${M_DIM}"_"${N_DIM}"_"${K_DIM}
        if [ $TIMING_EXPERIMENT -eq 1 ]
        then
                mkdir exp_results/"opt_"${OPTIMIZATION_FLAG}/timing/$FOLDER_NAME
        else
                mkdir exp_results/"opt_"${OPTIMIZATION_FLAG}/dc/$FOLDER_NAME
        fi

        rm -rf build
        for i_loop in `seq $TECH_TWOS_CRC 1 $TECH_FLET_CRC` #0 1 ${TECH_NO_ED}` #${TECH_FLET_CRC}
        do
                case $i_loop in
                $TECH_NO_ED)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_NO_ED
                        #NAME=$(printf %2d "${TECH_NO_ED}")
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
                NAME=$(printf %02d "$i_loop")"_"$NAME
                cmake .. -DCMAKE_BUILD_TYPE=Release -DCUTLASS_NVCC_ARCHS=72 -DCUTLASS_ENABLE_CUBLAS=OFF -DCUTLASS_ENABLE_CUDNN=OFF -Wno-dev -DCUDA_COMPILER=clang -DCUTLASS_CUDA_CLANG_FLAGS="-"$OPTIMIZATION_FLAG -DCMAKE_CXX_COMPILER=clang++ -DEXTERNAL_ES=$EXTERNAL_ES -DINTERMEDIATE_ES=$INTERMEDIATE_ES -DINTERNAL_ES=$INTERNAL_ES -DNAME=$NAME -DDIM_M=$M_DIM -DDIM_N=$N_DIM -DDIM_K=$K_DIM -DTIMING_EXP=$TIMING_EXPERIMENT -DDC_EXP=$DC_EXPERIMENT -DES_EXP=$ES_EXP
                #cmake .. -DCMAKE_BUILD_TYPE=Debug -DCUTLASS_NVCC_ARCHS=72 -DCUTLASS_ENABLE_CUBLAS=OFF -DCUTLASS_ENABLE_CUDNN=OFF -Wno-dev -DCUDA_COMPILER=clang -DCUTLASS_CUDA_CLANG_FLAGS="-"$OPTIMIZATION_FLAG -DCMAKE_CXX_COMPILER=clang++ -DEXTERNAL_ES=$EXTERNAL_ES -DINTERMEDIATE_ES=$INTERMEDIATE_ES -DINTERNAL_ES=$INTERNAL_ES -DNAME=$NAME -DDIM_M=$M_DIM -DDIM_N=$N_DIM -DDIM_K=$K_DIM -DTIMING_EXP=$TIMING_EXPERIMENT -DDC_EXP=$DC_EXPERIMENT -DES_EXP=$ES_EXP
                echo "NAME: $NAME"
                echo "MATRIX_DIM = [$M_DIM,$N_DIM,$K_DIM]"
                echo "[TIMING,DC,ES_OPT]=[$1,$2,$3]"
                cd examples/18_Sim_test/.
                cmake --build . --clean-first
                sudo ./18_Simt

                if [ $TIMING_EXPERIMENT -eq 1 ]
                then
                        mkdir ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/timing/${FOLDER_NAME}
                        mv ./${M_DIM}*.csv ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/timing/${FOLDER_NAME}/.
                else
                        mkdir ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/dc/${FOLDER_NAME}
                        mv ./${M_DIM}*.csv ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/dc/${FOLDER_NAME}/.
                fi
                cd ${PATH2ROOT}

        done
        if [ $TIMING_EXPERIMENT -eq 1 ]
        then
                cp ${PATH2ROOT}/convergence.sh ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/timing/${FOLDER_NAME}/.
                cd ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/timing/${FOLDER_NAME}/.

        else
                cp ${PATH2ROOT}/convergence.sh ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/dc/${FOLDER_NAME}/.
                cd ${PATH2RESULTS}/"opt_"${OPTIMIZATION_FLAG}/dc/${FOLDER_NAME}/.
        fi
        bash convergence.sh ${FOLDER_NAME} $OPTIMIZATION_FLAG
        cd ${PATH2ROOT}
done
