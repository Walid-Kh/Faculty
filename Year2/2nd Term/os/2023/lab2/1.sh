#!/bin/bash
function PrintNames
if [ "$#" -ne 0 ];
then
    if [ ! -d "$1" ];
    then
        echo "Directory ($1) dose not exists."
        exit 1;
    else
        cd $1
        files=$(ls | grep ".txt" | sort);
    if [ -z files ]
    then
        echo "No files have been found"
        exit 1
    fi
    echo "$files"
    fi
else
    echo "--------------- no directory is provided --------------"
    echo "------------ the current directory is used ------------"
    files=$(ls | grep ".txt" | sort);
    if [ -z "$files" ]
    then
        echo "No files have been found"
        exit 1
    fi
    echo "$files"
fi


# PrintNames;
# PrintNames "./test";
PrintNames "~/Desktop/";
