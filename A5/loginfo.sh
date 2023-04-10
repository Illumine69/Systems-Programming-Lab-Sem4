#!/bin/bash

# Sanskar Mittal
# 21CS10057

if [ $# -eq 0 ]; then
    S=`last -w`     # -w : Display full user and domain names in the output
else
    S=`last -w -n $1`
fi

A=()        # Array A stores the individual lines of last login
while read -r line; do
    A+=("$line")
done <<< "$S"

records=$(( ${#A[@]} - 2 ))
echo "$records login records read"

pattern="^([a-zA-Z0-9]*)"   

T=()        # T stores the matches
i=0
while [ $records -gt 0 ]
do
    if [[ ${A[i]} =~ $pattern ]]; then
        T+=("${BASH_REMATCH[1]}")
    fi
    i=$(( $i + 1 ))
    records=$(( $records - 1 ))
done

num_T=${#T[@]}
declare -A H=()     # H is associative array
i=0
while [ $num_T -gt 0 ]
do
    H["${T[$i]}"]=$(( H["${T[$i]}"] + 1 ))
    i=$(( $i + 1 ))
    num_T=$(( $num_T - 1 ))
done

for key in ${!H[@]}; do echo "$key logged in ${H[$key]} times"; done
