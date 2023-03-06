#!/bin/bash 
COUNTER=20
## What is the wrong in this one???!
until [  $COUNTER -lt 10 ]; 
do
	echo COUNTER $COUNTER
	let COUNTER+=1
done