#!/bin/bash

# Sanskar Mittal
# 21CS10057

function FIB () {   # Calculates fibonacci numbers
    local n=$1
    if [ ! ${F[$n]} ]; then
        FIB $((n-1))
        FIB $((n-2))
        F[$n]=$(( F[n-1] + F[n-2] ))
    fi
}

if [ $# -eq 0 ]; then
    echo "Run fibrep.sh with a single positive integer argument"
    exit 0
elif [ $1 -le 0 ] ; then
    echo "Invalid argument $1 to fibrep.sh"
    exit 0
else
    t=0
    N=$1
    declare -ai F=([0]=0 [1]=1)     # Fibonacci array initialised
    while [ ${F[t]} -lt $N ]
    do
        t=$(( $t + 1 ))
        FIB $t
    done
    echo "Computed Fibonacci numbers up to F($t) = ${F[$t]}"
    declare -ai Zeck=()     # Zeck stores the number whose Fibonacci value is used in the representation
    n_t=$t
    while [ $N -ne 0 ]
    do
        if [ $N -ge ${F[$t]} ]; then    # if N >= F[t]
            N=$(( $N - ${F[$t]} ))
            Zeck+=($t)
        fi
        t=$(( $t - 1 ))
    done
    echo -n "$1 = "
    for (( i = 0; i < ${#Zeck[@]}; i++ ))       # print the Zeckendorf representation
    do
        if [ $i -eq $(( ${#Zeck[@]} - 1 )) ]; then
            echo -n "F(${Zeck[i]})"
            echo ""
        else
            echo -n "F(${Zeck[i]}) + "
        fi
    done
fi
