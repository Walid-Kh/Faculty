#!/bin/bash

function isPrime {
    local X=$1
    if [ $X == 1 ] || [ $X == 2 ]
    then
        echo 1
        return
    elif (( X % 2 == 0 ))
    then
        echo 0
        return
    else 
        for (( i=3; i<=`echo "sqrt($X)" | bc`; i+=1 )); do
            if (( $X % $i == 0 ))
            then
                echo 0
                return
            fi
        done
        echo 1
        return
    fi
}

function findPrime {
    N=3
    if [ "$#" = 1 ]
    then 
        X=$1
    else 
        N=$1
        X=$2
    fi
    largestNumber=0
    numberOfPrimes=0
    
    for (( i=0; i<=${#X}-N; i++ )) do 
        number=${X:$i:$N}
        res=$(isPrime $number)
        if [ $res == "1" ]; then 
            let numberOfPrimes=$numberOfPrimes+1
            if [ $largestNumber -lt $number ]; then 
                largestNumber=$number
            fi
        fi
        
    done 
    
    echo $largestNumber $numberOfPrimes
}

findPrime "$@"
