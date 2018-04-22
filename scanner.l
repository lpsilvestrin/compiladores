%{
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include "astree.h"
#include "y.tab.h"


#define _TABLESIZE 100

//control variables
int lineNumber;
int running;
hashTable *SymbolsTable;

//interfaces
int yywrap();
int getLineNumber();
int isRunning();
void initMe();
void tokenTreatment(int tk_code);
hashNode* updateSymbolsTable(char* id, int type);
void checkSymbolsTable(char* token);

%}

%x COMMENT
%%
char    {return KW_CHAR; }
int     {return KW_INT; }
float   {return KW_FLOAT; }
if      {return KW_IF; }
then    {return KW_THEN; }
else    {return KW_ELSE; }
while   {return KW_WHILE; }
for     {return KW_FOR; }
to      {return KW_TO; }
read    {return KW_READ; }
return  {return KW_RETURN; }
print   {return KW_PRINT; }

"<="  {return OPERATOR_LE; }
">="  {return OPERATOR_GE; }
"=="  {return OPERATOR_EQ; }
"!="  {return OPERATOR_NE; }
"&&"  {return OPERATOR_AND; }
"||"  {return OPERATOR_OR; }

[,;:()[\]{}+\-*/<>=!&$#]  {return yytext[0]; }

[0-9]+                  {yylval.hashTable_pointer = updateSymbolsTable(yytext, SYMBOL_LIT_INT);/*checkSymbolsTable(yytext)*/;return LIT_INTEGER; }
[0-9]+[.][0-9]+         {yylval.hashTable_pointer = updateSymbolsTable(yytext, SYMBOL_LIT_REAL);/*checkSymbolsTable(yytext)*/;return LIT_REAL; }
'([^'\"]|\\['\"nt])'    {yylval.hashTable_pointer = updateSymbolsTable(yytext, SYMBOL_LIT_CHAR);/*checkSymbolsTable(yytext)*/;return LIT_CHAR; }
\"(\\.|[^"])*\"         {yylval.hashTable_pointer = updateSymbolsTable(yytext, SYMBOL_LIT_STRING);/*checkSymbolsTable(yytext)*/;return LIT_STRING; }
[a-zA-Z][a-zA-Z0-9_-]*  {yylval.hashTable_pointer = updateSymbolsTable(yytext, SYMBOL_IDENTIFIER);/*checkSymbolsTable(yytext)*/;return TK_IDENTIFIER; }

<<EOF>>   {running = 0; printf("EOF REACHED\n"); return running;}
" "       {}
\t        {}
"//".*    {}
"/*"      {BEGIN(COMMENT); }
\n        {lineNumber++; }
.         {return TOKEN_ERROR; }

<COMMENT>\n       {lineNumber++; }
<COMMENT>"\\n"    {}
<COMMENT>"*"+"/"  {BEGIN(INITIAL); }
<COMMENT>.        {}
%%

int yywrap() {
	return 1;
}

int getLineNumber() {
	return lineNumber;
}

int isRunning() {
	return running;
}

void initMe() {
	lineNumber = 1;
	running = 1;
	initHash(&SymbolsTable, _TABLESIZE);
}

hashNode* updateSymbolsTable(char* id, int type) {
	hashNode *n;
	initNode(&n); 		// inicializando área de memória e atribuindo pro ponteiro
	strcpy(n->id, id); // atribuindo identificador como key
	n->type = type;
	insertHash(n, SymbolsTable); // inserindo na tabela
}

void checkSymbolsTable(char* token) {
	hashNode *n = NULL;
	printf("[HASH] Searching for %s inside our hash\n", token);
	getHash(token, SymbolsTable, &n);
	if (n != NULL) {
	printf("[HASH] Found %s\n", n->id);
	} else {
		printf("[HASH] Failed to find %s\n", yytext);
	}
}
