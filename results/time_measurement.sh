#!/bin/bash

# Define an enum type
TECH_XOR_EXTERNAL=0
TECH_XOR_INTERMEDIATE=1
TECH_XOR_INTERNAL=2
TECH_ONES_EXTERNAL=3
TECH_ONES_INTERMEDIATE=4
TECH_ONES_INTERNAL=5
TECH_TWOS_EXTERNAL=6
TECH_TWOS_INTERMEDIATE=7
TECH_TWOS_INTERNAL=8
TECH_FLETCHER_EXTERNAL=9
TECH_FLETCHER_INTERMEDIATE=10
TECH_FLETCHER_INTERNAL=11
TECH_CRC_EXTERNAL=12
TECH_CRC_INTERMEDIATE=13
TECH_CRC_INTERNAL=14
TECH_XOR_FLET=15
TECH_XOR_CRC=16
TECH_ONES_FLET=17
TECH_ONES_CRC=18
TECH_TWOS_FLET=19
TECH_TWOS_CRC=20
TECH_FLET_CRC=21
TECH_NO_ED=22

UNPROTECTED=0
XOR_CHECKSUM=1
ONES_CHECKSUM=2
TWOS_CHECKSUM=3
FLETCHER_CHECKSUM=4
CRC_CHECKSUM=5

TIMING_EXPERIMENT=$1
DC_EXPERIMENT=$2

echo "TIMING_EXPERIMENT=$TIMING_EXPERIMENT"
echo "DC_EXPERIMENT=$DC_EXPERIMENT"
echo $TECH_FLET_CRC
# Define an enum type with the kind of memory
 for j_loop in 20 #80 160 320 128 256 #80 160 320 128 256 512 
        do
        for i_loop in `seq 0 1 ${TECH_NO_ED}` #${TECH_FLET_CRC}
        do
                case $i_loop in
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
                $TECH_NO_ED)
                        EXTERNAL_ES=$UNPROTECTED
                        INTERMEDIATE_ES=$UNPROTECTED
                        INTERNAL_ES=$UNPROTECTED
                        NAME=TECH_NO_ED
                ;;
                esac
                cd ../../.
                bash init_cmake.sh $EXTERNAL_ES $INTERMEDIATE_ES $INTERNAL_ES $i_loop"_"$NAME $j_loop $j_loop $j_loop $TIMING_EXPERIMENT $DC_EXPERIMENT
                cd examples/18_Sim_test
                cmake --build . --clean-first
                ./18_Simt
        done
	bash convergence.sh $j_loop
done
