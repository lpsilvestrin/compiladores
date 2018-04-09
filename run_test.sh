#!/bin/bash

make clean
make

for f in tests/*; do 
	echo $f;
	./etapa2 $f &> /dev/null
	if [ $? -ne 0 ] 
	then
		echo "PROBLEMA!";
	fi
	
done
