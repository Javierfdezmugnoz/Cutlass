#!/bin/bash

#ARRAYS WITH THE DIMENSION OF THE EXPERIMENTS
tm_square1=(80 80 80)
tm_square2=(160 160 160)
tm_square3=(320 320 320)
tm_unbalanced1=(18 230400 64)

dc_square1=(20 20 20)
dc_square2=(40 40 40)
dc_square3=(80 80 80)
dc_unbalanced1=(32 29 144)
dc_unbalanced2=(8 900 8)
dc_unbalanced3=(15 225 48)

tm_arrays=('tm_square1' 'tm_square2' 'tm_square3' 'tm_unbalanced1')
dc_arrays=('dc_square1' 'dc_square2' 'dc_square3' 'dc_unbalanced1' 'dc_unbalanced2' 'dc_unbalanced3')

if [ 1 -eq 1 ]
    then
            declare -n arr=tm_arrays
    else
            arr=${dc_arrays}
                
fi

for a in "${arr[@]}";
do
    declare -n M_DIM="$a[0]"
    declare -n N_DIM="$a[1]"
    declare -n K_DIM="$a[2]"
    echo "$M_DIM"
    echo "$N_DIM"
    echo "$K_DIM"
    echo "==========="
done