#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

#define _MAXSTR = 50;

/*
extern int lineNumber;
extern int running;
extern int getLineNumber();
extern int isRunning();


int main(int argc, char** argv) {
	if (argc < 2) {
		printf("nome do arquivo inválido");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	int res = yylex();
	while (res != 0) {
		printf("achou %d\n", res);
		res = yylex();
	}

	fclose(yyin);
	exit(0);
}
*/



int main(int argc, char** argv) {

	hashTable* hTable;
	initHash(&hTable, 25);
	hashNode* n1, *n2,* n3,* n4,* e;
	initNode(&n1);
	initNode(&n2);
	initNode(&n3);
	initNode(&n4);
	strcpy(n1->key, "test1");	
	strcpy(n2->key, "test2");	
	strcpy(n3->key, "test3");	
	strcpy(n4->key, "test4");	
	insertHash(n1, hTable);
	insertHash(n2, hTable);
	insertHash(n2, hTable);
	insertHash(n3, hTable);
	
	getHash(n1->key, hTable, &e);
	printf("retreived: %s\n", e->key);
	
	exit(0);
}

