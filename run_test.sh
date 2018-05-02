#!/bin/bash

make clean
make

for f in tests/*; do 
	echo $f;
	./etapa3 $f $f".out1"
	./etapa3 $f".out1" $f".out2"
	echo "diff"
	diff $f".out1" $f".out2" | grep ">"
	
done
