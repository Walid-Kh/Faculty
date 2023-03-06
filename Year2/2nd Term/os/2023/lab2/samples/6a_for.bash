#!/bin/bash
for i in $( ls ); do
    echo item: $i
done
# for i in `ls`; do # is correct too

for i in {1..5..2}; do
    echo item: $i
done
# for i in {1..5..1}; do #is the same as for i in {1..5}; do