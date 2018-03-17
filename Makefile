#
# UFRGS - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
#
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l
#

etapa1: lex.yy.c hashtable.o main.c 
	gcc -g -o etapa1 lex.yy.c main.c hashtable.o

lex.yy.c: scanner.l
	lex scanner.l



hashtable.o: hashtable.c hashtable.h
	gcc -g -Wall -c hashtable.c


test_hash: test_hash.c hashtable.o
	gcc -g -Wall -o main test_hash.c hashtable.o

clean:
	rm lex.yy.c etapa1 *.o  
