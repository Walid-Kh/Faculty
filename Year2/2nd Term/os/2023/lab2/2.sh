#!/bin/bash

if [ $# -ne 2 ]
then 
    echo "error"
    exit 1
fi

if [ ! -d  "$1" ]
then 
    echo "error directroy doesn't exist"
    exit 1
fi

if [ -z "$2" ]
then 
    term='error'
else 
    term="$2"
fi

files=$(grep -rl "$term" "$1")

if [ -z "$files" ]
then 
    echo "No files were found!"
    exit 0
fi 
echo "$files"
