#!/bin/bash
y=1;
y=$y+1; echo $y;                           # 1+1 ! so we need to use let  
let y=$y+1; echo $y;                       # 2 
y=$((y+1)); echo $y;                       # 2 
y=`expr $y + 1`; echo $y;                  # 2 
y=$((2 ** 3))                              # 8; it calculates 2^3