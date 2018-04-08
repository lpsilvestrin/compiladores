%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
#include "hashtable.h"


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
void updateSymbolsTable(char* id);
void checkSymbolsTable(char* token);

%}

%x COMMENT
%%
char    {fprintf(stderr,"LINE %d: Found a char\n", lineNumber );return KW_CHAR; }
int     {fprintf(stderr,"LINE %d: Found an int\n", lineNumber );return KW_INT; }
float   {fprintf(stderr,"LINE %d: Found a float\n", lineNumber );return KW_FLOAT; }
if      {fprintf(stderr,"LINE %d: Found an if\n", lineNumber );return KW_IF; }
then    {fprintf(stderr,"LINE %d: Found a then\n", lineNumber );return KW_THEN; }
else    {fprintf(stderr,"LINE %d: Found an else\n", lineNumber );return KW_ELSE; }
while   {fprintf(stderr,"LINE %d: Found a while\n", lineNumber );return KW_WHILE; }
for     {fprintf(stderr,"LINE %d: Found a for\n", lineNumber );return KW_FOR; }
to      {fprintf(stderr,"LINE %d: Found a to\n", lineNumber );return KW_TO; }
read    {fprintf(stderr,"LINE %d: Found a read\n", lineNumber );return KW_READ; }
return  {fprintf(stderr,"LINE %d: Found a return\n", lineNumber );return KW_RETURN; }
print   {fprintf(stderr,"LINE %d: Found a print\n", lineNumber );return KW_PRINT; }

"<="  {fprintf(stderr,"LINE %d: Found a LE\n", lineNumber );return OPERATOR_LE; }
">="  {fprintf(stderr,"LINE %d: Found a GE\n", lineNumber );return OPERATOR_GE; }
"=="  {fprintf(stderr,"LINE %d: Found an EQ\n", lineNumber );return OPERATOR_EQ; }
"!="  {fprintf(stderr,"LINE %d: Found a NE\n", lineNumber );return OPERATOR_NE; }
"&&"  {fprintf(stderr,"LINE %d: Found an AND\n", lineNumber );return OPERATOR_AND; }
"||"  {fprintf(stderr,"LINE %d: Found an OR\n", lineNumber );return OPERATOR_OR; }

[,;:()[\]{}+\-*/<>=!&$#]  {fprintf(stderr,"LINE %d: Found the special character <%s>\n", lineNumber, yytext);return yytext[0]; }

[0-9]+                  {fprintf(stderr,"LINE %d: Found a LIT INTEGER with value %s\n", lineNumber, yytext );
		updateSymbolsTable(yytext);checkSymbolsTable(yytext);return LIT_INTEGER; }
[0-9]+[.][0-9]+         {fprintf(stderr,"LINE %d: Found a REAL with value %s\n", lineNumber, yytext );
		updateSymbolsTable(yytext);checkSymbolsTable(yytext);return LIT_REAL; }
'([^'\"]|\\['\"nt])'    {fprintf(stderr,"LINE %d: Found a LIT CHAR %s\n", lineNumber, yytext );
		updateSymbolsTable(yytext);checkSymbolsTable(yytext);return LIT_CHAR; }
\"(\\.|[^"])*\"         {fprintf(stderr,"LINE %d: Found a LIT STRING %s\n", lineNumber, yytext );
		updateSymbolsTable(yytext);checkSymbolsTable(yytext);return LIT_STRING; }
[a-zA-Z][a-zA-Z0-9_-]*  {fprintf(stderr,"LINE %d: Found an identifier called %s\n", lineNumber, yytext);
		updateSymbolsTable(yytext);checkSymbolsTable(yytext);return TK_IDENTIFIER; }

<<EOF>>   {running = 0; printf("EOF REACHED\n"); return running;}
" "       {}
\t        {}
"//".*    {}
"/*"      {fprintf(stderr,"Starting multiple lines comment");BEGIN(COMMENT); }
\n        {lineNumber++; }
.         {fprintf(stderr, "LINE %d: Token error <%s>\n\n", lineNumber, yytext); return TOKEN_ERROR; }

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

void updateSymbolsTable(char* id) {
	hashNode *n;
	initNode(&n); 		// inicializando área de memória e atribuindo pro ponteiro
	strcpy(n->id, id); // atribuindo identificador como key
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
