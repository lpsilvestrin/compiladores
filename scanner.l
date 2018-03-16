%{
#include <stdlib.h>
#include "tokens.h"

//control variables
int lineNumber = 1;
int running = 1;

%}

%%

char 						{return KW_CHAR; }
int 						{return KW_INT; }
float 					{return KW_FLOAT; }
if							{return KW_IF; }
then 						{return KW_THEN; }
else 						{return KW_ELSE; }
while 					{return KW_WHILE; }
for 						{return KW_FOR; }
read 						{return KW_READ; }
return 					{return KW_RETURN; }
print 					{return KW_RETURN; }

"//"						{lineNumber++; }
"/*"						{}
\n 							{lineNumber++; }


.								{return TOKEN_ERROR; }


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

void tokenTreatment(int tk_code) {
  switch (tk_code) {
    case KW_CHAR: printf("achei um char\n" );
    break;
    case KW_INT: printf("achei um int\n" );
    break;
    case KW_FLOAT: printf("achei um float\n" );
    break;
    case KW_IF: printf("achei um if\n" );
    break;
    case KW_THEN: printf("achei um then\n" );
    break;
    case KW_ELSE: printf("achei um else\n" );
    break;
    case KW_WHILE: printf("achei um while\n" );
    break;
    case KW_FOR: printf("achei um for\n" );
    break;
    case KW_READ: printf("achei um read\n" );
    break;
    case KW_RETURN: printf("achei um return\n" );
    break;
    case KW_PRINT: printf("achei um print\n" );
    break;
    case OPERATOR_LE: printf("achei um LE\n" );
    break;
    case OPERATOR_GE: printf("achei um GE\n" );
    break;
    case OPERATOR_EQ: printf("achei um EQ\n" );
    break;
    case OPERATOR_NE: printf("achei um NE\n" );
    break;
    case OPERATOR_AND: printf("achei um AND\n" );
    break;
    case OPERATOR_OR: printf("achei um OR\n" );
    break;
    case TK_IDENTIFIER: printf("achei um TK IDENTIFIER\n" );
    break;
    case LIT_INTEGER: printf("achei um LIT INTEGER\n" );
    break;
    case LIT_REAL: printf("achei um REAL\n" );
    break;
    case LIT_CHAR: printf("achei um LIT CHAR\n" );
    break;
    case LIT_STRING: printf("achei um LIT STRING\n" );
    break;
    case TOKEN_ERROR: printf("Token error <%s> at line %d\n", yytext, lineNumber);
	}
}


/*int main(int argc, char** argv) {
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
}*/
