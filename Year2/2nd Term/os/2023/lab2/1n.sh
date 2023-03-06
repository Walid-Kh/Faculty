#!/bin/bash

# 1. Write a bash script that accepts a directory path as an argument
# and prints the names of all files in that directory that have the '.txt' extension,
# sorted in alphabetical order. If no directory is provided,
# the script should use the current directory.
# The script should also handle cases where the provided directory does not exist
# or is not a directory. In these cases, the script should print an error message and
# exit with a non-zero exit code.

if [ ! -z "$1" ]; then
  dir="$1"
else
  dir="."
fi

if [ ! -d "$dir" ]; then
  echo "Error: $dir is not a directory"
  exit 1
fi

files=$(ls "$dir" | grep ".txt" | sort)
if [ -z "$files" ]
then 
    echo "no files have been found"
    exit 1
else 
    echo "$files"
fi