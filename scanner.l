%{
#include <stdlib.h>
#include "tokens.h"

//control variables
int lineNumber = 1;
int running = 1;

%}

%x COMMENT
%%


char 																{return KW_CHAR; }
int 																{return KW_INT; }
float 															{return KW_FLOAT; }
if																	{return KW_IF; }
then 																{return KW_THEN; }
else 																{return KW_ELSE; }
while 															{return KW_WHILE; }
for 																{return KW_FOR; }
read 																{return KW_READ; }
return 															{return KW_RETURN; }
print 															{return KW_RETURN; }

"<="																{return OPERATOR_LE; }
">="																{return OPERATOR_GE; }
"=="																{return OPERATOR_EQ; }
"!="																{return OPERATOR_NE; }
"&&"																{return OPERATOR_AND; }
"||"																{return OPERATOR_OR; }

[,;:()[\]{}+\-*/<>=!&$#]						{return yytext[0]; }

[0-9]+															{return LIT_INTEGER; }
[0-9]+[.][0-9]+											{return LIT_REAL; }
[a-zA-Z][a-zA-Z0-9_-]*							{return TK_IDENTIFIER; }




" "																	{}
\t																	{}
"/*".*															{BEGIN(COMMENT); }
"//".*															{}
\n 																	{lineNumber++; }
.																		{return TOKEN_ERROR; }

<COMMENT>
\n												{lineNumber++; }
"*/"											{BEGIN(INITIAL); }
.													{}

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
    case KW_CHAR: printf("LINE %d: achei um char\n", lineNumber );
    break;
    case KW_INT: printf("LINE %d: achei um int\n", lineNumber );
    break;
    case KW_FLOAT: printf("LINE %d: achei um float\n", lineNumber );
    break;
    case KW_IF: printf("LINE %d: achei um if\n", lineNumber );
    break;
    case KW_THEN: printf("LINE %d: achei um then\n", lineNumber );
    break;
    case KW_ELSE: printf("LINE %d: achei um else\n", lineNumber );
    break;
    case KW_WHILE: printf("LINE %d: achei um while\n", lineNumber );
    break;
    case KW_FOR: printf("LINE %d: achei um for\n", lineNumber );
    break;
    case KW_READ: printf("LINE %d: achei um read\n", lineNumber );
    break;
    case KW_RETURN: printf("LINE %d: achei um return\n", lineNumber );
    break;
    case KW_PRINT: printf("LINE %d: achei um print\n", lineNumber );
    break;
    case OPERATOR_LE: printf("LINE %d: achei um LE\n", lineNumber );
    break;
    case OPERATOR_GE: printf("LINE %d: achei um GE\n", lineNumber );
    break;
    case OPERATOR_EQ: printf("LINE %d: achei um EQ\n", lineNumber );
    break;
    case OPERATOR_NE: printf("LINE %d: achei um NE\n", lineNumber );
    break;
    case OPERATOR_AND: printf("LINE %d: achei um AND\n", lineNumber );
    break;
    case OPERATOR_OR: printf("LINE %d: achei um OR\n", lineNumber );
    break;
    case TK_IDENTIFIER: printf("LINE %d: Found an identified called %s\n", lineNumber, yytext); //colocar na hash
    break;
    case LIT_INTEGER: printf("LINE %d: achei um LIT INTEGER de valor %s\n", lineNumber, yytext );
    break;
    case LIT_REAL: printf("LINE %d: achei um REAL de valor %s\n", lineNumber, yytext );
    break;
    case LIT_CHAR: printf("LINE %d: achei um LIT CHAR\n", lineNumber );
    break;
    case LIT_STRING: printf("LINE %d: achei um LIT STRING\n", lineNumber);
    break;
    case TOKEN_ERROR: printf("LINE %d: Token error <%s>\n\n", lineNumber, yytext);
		break;
		default: printf("LINE %d: Found the special character <%s>\n", lineNumber, yytext);
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
