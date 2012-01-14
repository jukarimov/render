#!/bin/bash

Usage="Convert RAW export file from Blender to our xyz format\nUsage: input.raw\n"

FIN=$1
test "$FIN" == "" && printf "$Usage" && exit || FOUT="$(echo $FIN | cut -d '.' -f 1).xyz" && echo Saving to $FOUT ...

n=0;
cat $FIN | while read i; do 
	for j in $i; do 
		echo -n "$j"; 
		n=$(($n+1)); 
		test "$(($n % 3))" == "0" && echo || printf "\t"; 
	done; 
done > $FOUT
