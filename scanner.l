%{
#include <stdlib.h>

#include "tokens.h"

int lineNumber = 1;
int running = 1;

%}

%%
if		{ return KW_IF; }
\n		{ lineNumber++; }



.		{ return 999; }
%%

int yywrap(void) {
	return 1; 
}

int getLineNumber() {
	return lineNumber;
}

int isRunning() {
	return running;
}

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
