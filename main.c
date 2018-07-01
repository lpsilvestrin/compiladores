#include <stdlib.h>
#include <stdio.h>
#include "lex.yy.h"
#include "hashtable.h"
#include "tac.h"
#include "assembly_gen.h"

extern FILE* yyin; //CAREFUL WITH IT
extern int yyparse();
extern void initMe();
extern void setOutput(FILE* pointer);
extern int getLineNumber();
extern void create_lit_ids();
extern ASTree* get_parsed_tree();
extern hashTable *SymbolsTable; 
extern int _SEMANTIC_ERROR;

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: etapa6 <input_file> <output_file>\n");
		exit(1);
	}

	if((yyin = fopen(argv[1], "r"))==NULL) {
		printf("Problem reading the file %s\n", argv[1]);
		exit(1);
	}
	FILE* f;
	if ((f = fopen(argv[2],"w"))==NULL) {
		printf("Problem reading the file %s\n", argv[2]);
		exit(1);
		//setOutput(f); //send the pointer to ther parser
	}

	initMe();
	if(yyin){
		yyparse();
		if (_SEMANTIC_ERROR == 1) {
			printf("Found a semantic error\n");
			exit(4);
		}
		ASTree* parsed_tree = get_parsed_tree();
		TAC *tac = tac_reverse(tac_generate_code(parsed_tree));
		tac_print_code(tac);
		//printHash(SymbolsTable);
		create_lit_ids(SymbolsTable);
		printHash(SymbolsTable);
		gen_assembly(tac, SymbolsTable, f); 
		//gen_assembly(tac, stdout); // for debug sake 


	}
	exit(0);
}
