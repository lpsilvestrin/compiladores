#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

extern FILE *yyin; //CAREFUL WITH IT
extern int yylex();
extern void tokenTreatment(int tk_code);
extern void initMe();
extern int isRunning();
extern hashTable* SymbolsTable;
extern char *yytext;

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: etapa1 <file>");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
  if(yyin){
    initMe(); //init da hash e etc
    int token;
    while(isRunning()){
        token = yylex();
        if(!isRunning()){
          break;
        }else{
          tokenTreatment(token);
		  hashNode *n = NULL;
		  printf("[HASH] Searching for %s inside our hash\n", yytext);
		  getHash(yytext, SymbolsTable, &n);
		  if (n != NULL) {
			printf("[HASH] Found %s\n", n->id);
		  } else {
		  	printf("[HASH] Failed to find %s\n", yytext);
		  }

        }
      }
  	fclose(yyin);



    return 0;
  }else{
    return 1;
  }
}
