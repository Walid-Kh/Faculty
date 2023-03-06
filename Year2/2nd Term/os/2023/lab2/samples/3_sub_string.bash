#!/bin/bash
# Length of a string
stringZ=abcABC123ABCabc
echo ${#stringZ}                 # 15
echo `expr length $stringZ`      # 15

# Substring extraction
echo ${stringZ:0}                     # abcABC123ABCabc
echo ${stringZ:1}                     # bcABC123ABCabc
echo ${stringZ:7:3}                   # 23A, Three characters of substring.
echo ${stringZ: -4}                   # Cabc
echo ${stringZ: -4:1}                 # C