#!/bin/bash

DIROUT=out
DIROUT2=out_cpy

make clean
make
mkdir -p $DIROUT
mkdir -p $DIROUT2

for f in tests/*; do 
	fn=$(basename $f)
	echo $f;
	./etapa3 $f $DIROUT/$fn".out"	
done


for f in $DIROUT/*; do 
	fn=$(basename $f)
	echo $f;
	./etapa3 $f $DIROUT2/$fn
done


for f in $DIROUT/*; do 
	fn=$(basename $f)
	echo $f;
	diff $f $DIROUT2/$fn
done
