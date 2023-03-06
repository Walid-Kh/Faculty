#!/bin/bash

function increment {
	counter=0;
	inc=1;
	# Check that function has no arguments 
	if [ "$#" -ne 0 ];
	then
		inc=$1; # if it has arguments set the increment with the first argument
	fi

	for i in `seq 10 -1 1`;
	do
             echo "The counter is $counter";
             let counter=counter+$inc;
	done
}

# Call functions
# without arguments
increment;
echo "calling increment with an increment of 3";
#with arguments
increment 3;