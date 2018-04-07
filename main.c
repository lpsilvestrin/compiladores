#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

extern FILE *yyin; //CAREFUL WITH IT
extern int yyparse();

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: etapa2 <file>");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
  if(yyin){
    return yyparse();
  }
}
