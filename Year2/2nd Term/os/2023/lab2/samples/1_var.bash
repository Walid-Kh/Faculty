#!/bin/bash
string_var1=abcABC123ABCabc;
string_var2="Hello World!";
num_var=1234;
echo `expr 2 \* 3`                      # 6
echo `expr 2 + 3`                       # 5
echo $(expr 2 + 3)                      # 5
echo `expr 1.5 \* 3`                    # error: expr: non-integer argument
a = 3 #Error, Why?
a= 3 #Error, Why?
a=3 #Error, Why?
echo $a