#!/bin/bash

make clean
make

for f in tests/*; do 
	echo $f;
	./etapa3 $f $f".out"
	
done
