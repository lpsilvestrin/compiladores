#
# Marcely e Luis Pedro, 2018/1
#

etapa2: semantic.o y.tab.o lex.yy.o hashtable.o astree.o main.c
	gcc -g -Wall -o etapa4 semantic.o y.tab.o lex.yy.o hashtable.o astree.o main.c 

y.tab.o: parser.y
	yacc -d -v parser.y
	gcc -g -c y.tab.c
	
lex.yy.o: scanner.l
	lex --header-file=lex.yy.h scanner.l
	gcc -g -c lex.yy.c 

semantic.o: semantic.h semantic.c
	gcc -g -Wall -c semantic.c

hashtable.o: hashtable.c hashtable.h
	gcc -g -Wall -c hashtable.c


astree.o: astree.c astree.h 
	gcc -g -Wall -c astree.c


test_hash: hash_tester.c hashtable.o
	gcc -g -Wall -o main hash_tester.c hashtable.o

clean:
	rm etapa4 lex.yy.* y.output y.tab.* 
	rm *.o 
