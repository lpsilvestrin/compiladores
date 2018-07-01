#
# Marcely e Luis Pedro, 2018/1
#

etapa2: semantic.o y.tab.o lex.yy.o hashtable.o astree.o tac.o assembly_gen.o main.c 
	gcc -g -Wall -o etapa6 semantic.o y.tab.o lex.yy.o hashtable.o astree.o tac.o assembly_gen.o main.c 

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

tac.o: tac.c tac.h 
	gcc -g -Wall -c tac.c

assembly_gen.o: assembly_gen.c assembly_gen.h
	gcc -g -Wall -c assembly_gen.c


test_hash: hash_tester.c hashtable.o
	gcc -g -Wall -o main hash_tester.c hashtable.o

clean:
	rm etapa6 *.o y.output
	rm y.tab.* lex.yy.*
