#
# Marcely e Luis Pedro, 2018/1
#

etapa2: y.tab.o lex.yy.o hashtable.o main.c
	gcc -g -Wall -o etapa2 y.tab.o lex.yy.o main.c hashtable.o

y.tab.o:
	yacc -d -v parser.y
	gcc -g -Wall -c y.tab.c
	
lex.yy.o: scanner.l
	lex --header-file=lex.yy.h scanner.l
	gcc -g -Wall -c lex.yy.c


hashtable.o: hashtable.c hashtable.h
	gcc -g -Wall -c hashtable.c


test_hash: test_hash.c hashtable.o
	gcc -g -Wall -o main test_hash.c hashtable.o

clean:
	rm lex.yy.* etapa2 *.o  y.output y.tab.*
