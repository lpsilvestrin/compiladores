#include <stdlib.h>
#include <stdio.h>
#include "lex.yy.h"
#include "hashtable.h"

extern FILE* yyin; //CAREFUL WITH IT
extern int yyparse();
extern void initMe();
extern void setOutput(FILE* pointer);
extern int getLineNumber();
extern hashTable *SymbolsTable; 

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Usage: etapa3 <input_file> <output_file>\n");
		exit(1);
	}
	if((yyin = fopen(argv[1], "r"))==NULL) {
		printf("Problem reading the file %s\n", argv[1]);
		exit(1);
	}

	FILE* f;
	if((f = fopen(argv[2],"w"))==NULL) {
		printf("Problem reading the file %s\n", argv[2]);
		exit(1);
	}
	initMe();
	setOutput(f); //send the pointer to ther parser
	if(yyin){
		yyparse();
		//printf("Last line: %d\n", getLineNumber());
		printf("printing the hash table contents:\n");
		printHash(SymbolsTable);
	}
	exit(0);
}
