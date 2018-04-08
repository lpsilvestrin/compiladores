#include <stdlib.h>
#include <stdio.h>
#include "lex.yy.h"

extern FILE *yyin; //CAREFUL WITH IT
extern int yyparse();
extern void initMe();

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: etapa2 <file>");
		exit(1);
	}
	if((yyin = fopen(argv[1], "r"))==NULL) {
		printf("Problem reading the file %s\n", argv[1]);
		exit(1);
	}else {
		initMe();
		if(yyin){
    return yyparse();
  	}
	}
	exit(0);
}
