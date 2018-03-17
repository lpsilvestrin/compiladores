%{
#include <stdlib.h>
#include <stdio.h>
#include "tokens.h"
#include "hashtable.h"


#define _TABLESIZE 100

//control variables
int lineNumber = 1;
int running = 1;
hashTable *SymbolsTable;
void updateSymbolsTable(char*);


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
print 															{return KW_PRINT; }

"<="																{return OPERATOR_LE; }
">="																{return OPERATOR_GE; }
"=="																{return OPERATOR_EQ; }
"!="																{return OPERATOR_NE; }
"&&"																{return OPERATOR_AND; }
"||"																{return OPERATOR_OR; }

[,;:()[\]{}+\-*/<>=!&$#]						{return yytext[0]; }

[0-9]+															{return LIT_INTEGER; }
[0-9]+[.][0-9]+											{return LIT_REAL; }
"\'"[a-zA-Z0-9_-]+"\'"							{return LIT_CHAR; }
"\"".*[\\"].*"\""													{return LIT_STRING; }
[a-zA-Z][a-zA-Z0-9_-]*							{return TK_IDENTIFIER; }

<<EOF>>															{running = 0; printf("EOF REACHED\n"); return running;}
" "																	{}
\t																	{}
"//".*															{}
"/*".*															{BEGIN(COMMENT); }
\n 																	{lineNumber++; }
.																		{return TOKEN_ERROR; }

<COMMENT>\n								{lineNumber++; }
<COMMENT>"*/"							{BEGIN(INITIAL); }
<COMMENT>.								{}




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
    case KW_CHAR: printf("LINE %d: Found a char\n", lineNumber );
    break;
    case KW_INT: printf("LINE %d: Found an int\n", lineNumber );
    break;
    case KW_FLOAT: printf("LINE %d: Found a float\n", lineNumber );
    break;
    case KW_IF: printf("LINE %d: Found an if\n", lineNumber );
    break;
    case KW_THEN: printf("LINE %d: Found a then\n", lineNumber );
    break;
    case KW_ELSE: printf("LINE %d: Found an else\n", lineNumber );
    break;
    case KW_WHILE: printf("LINE %d: Found a while\n", lineNumber );
    break;
    case KW_FOR: printf("LINE %d: Found a for\n", lineNumber );
    break;
    case KW_READ: printf("LINE %d: Found a read\n", lineNumber );
    break;
    case KW_RETURN: printf("LINE %d: Found a return\n", lineNumber );
    break;
    case KW_PRINT: printf("LINE %d: Found a print\n", lineNumber );
    break;
    case OPERATOR_LE: printf("LINE %d: Found a LE\n", lineNumber );
    break;
    case OPERATOR_GE: printf("LINE %d: Found a GE\n", lineNumber );
    break;
    case OPERATOR_EQ: printf("LINE %d: Found an EQ\n", lineNumber );
    break;
    case OPERATOR_NE: printf("LINE %d: Found a NE\n", lineNumber );
    break;
    case OPERATOR_AND: printf("LINE %d: Found an AND\n", lineNumber );
    break;
    case OPERATOR_OR: printf("LINE %d: Found an OR\n", lineNumber );
    break;
    case TK_IDENTIFIER:
		printf("LINE %d: Found an identifier called %s\n", lineNumber, yytext);
		updateSymbolsTable(yytext);
    break;
    case LIT_INTEGER: printf("LINE %d: Found a LIT INTEGER with value %s\n", lineNumber, yytext );
    break;
    case LIT_REAL: printf("LINE %d: Found a REAL with value %s\n", lineNumber, yytext );
    break;
    case LIT_CHAR: printf("LINE %d: Found a LIT CHAR %s\n", lineNumber, yytext );
    break;
    case LIT_STRING: printf("LINE %d: Found a LIT STRING %s\n", lineNumber, yytext ); //nao reconhece \" na string
    break;
    case TOKEN_ERROR: printf("LINE %d: Token error <%s>\n\n", lineNumber, yytext);
		break;
		default: printf("LINE %d: Found the special character <%s>\n", lineNumber, yytext);
	}
}

void initMe() {
	initHash(&SymbolsTable, _TABLESIZE);
}

void updateSymbolsTable(char* id) {
	hashNode *n;
	initNode(&n); 		// inicializando área de memória e atribuindo
						// pro ponteiro
	strcpy(n->key, id); // atribuindo identificador como key
	insertHash(n, SymbolsTable); // inserindo na tabela
}
