#
# Marcely e Luis Pedro, 2018/1
#

etapa2: ast_ids.h y.tab.o lex.yy.o hashtable.o astree.o main.c
	gcc -g -Wall -o etapa3 y.tab.o lex.yy.o hashtable.o astree.o main.c 

y.tab.o: ast_ids.h parser.y
	yacc -d -v parser.y
	gcc -g -Wall -c y.tab.c
	
lex.yy.o: scanner.l
	lex --header-file=lex.yy.h scanner.l
	gcc -g -Wall -c lex.yy.c 


hashtable.o: hashtable.c hashtable.h
	gcc -g -Wall -c hashtable.c

ast_ids.h:
	yacc -d -v ast_ids.y -o ast_ids.c

astree.o: ast_ids.h astree.c astree.h 
	gcc -g -Wall -c astree.c


test_hash: test_hash.c hashtable.o
	gcc -g -Wall -o main test_hash.c hashtable.o

clean:
	rm ast_ids.h ast_ids.output ast_ids.c
	rm etapa3 lex.yy.* y.output y.tab.* 
	rm *.o 
