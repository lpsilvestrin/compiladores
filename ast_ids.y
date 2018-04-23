%{
#include <stdlib.h>
#include <stdio.h>
%}

%start ast_symbols

%token AST_INITIAL 
%token AST_GLOBAL_VAR_DEF 
%token AST_GLOBAL_VECTOR_DEF 
%token AST_VECTOR_DEF
%token AST_INT 
%token AST_FUNCTION_DEF
%token AST_HEADER 
%token AST_DEF_PARAM 
%token AST_DEF_PARAM_T 
%token AST_COMMANDS_L 
%token AST_VECTOR_AS 
%token AST_VAR_AS 
%token AST_READ 
%token AST_PRINT 
%token AST_NOT_EXP 
%token AST_NEG_EXP 
%token AST_PAR_EXP 
%token AST_PLUS_EXP 
%token AST_MINUS_EXP 
%token AST_MUL_EXP 
%token AST_DIV_EXP 
%token AST_LESS_EXP
%token AST_GREAT_EXP 
%token AST_LE_EXP 
%token AST_GE_EXP 
%token AST_EQ_EXP 
%token AST_NE_EXP 
%token AST_AND_EXP 
%token AST_OR_EXP 
%token AST_ID 
%token AST_ID_POINTER 
%token AST_ID_ADDRESS 
%token AST_VECTOR 
%token AST_FUNCTION 
%token AST_PARAM 
%token AST_IF 
%token AST_IFELSE 
%token AST_FOR 
%token AST_WHILE 
%token AST_REAL 
%token AST_CHAR 
%token AST_INIT_VALUES 
%%

ast_symbols:;

%%
int yyerror (char const *s) {
    //fflush(stderr);
    //fprintf(stderr,"ERROR: %s ---> Line: %d\n", s, getLineNumber());
    exit(1);
}
