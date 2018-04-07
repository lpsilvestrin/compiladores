%{
#include<stdio.h>

%}

%start program

/*Declaração da linguagem*/
%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_RETURN
%token KW_PRINT
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR
%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR  /*Ainda precisa ou tiramos esse?*/



%%
program: instructions
    |
    ; 

// ????
instructions: global_struct instructions | function instructions
    ;

//----------- GLOBAL STRUCTURES

global_struct: global_var | global_vector
    ;

//Nao faco ideia se ta certo declarar assim

global_var: kw_type TK_IDENTIFIER '=' lit_value ';' | kw_type '#' TK_IDENTIFIER '=' lit_value ';'
    ;

global_vector: TK_IDENTIFIER '[' LIT_INTEGER ']' ';' | TK_IDENTIFIER '[' LIT_INTEGER ']' '=' lit_list ';' 
    ;

kw_type: KW_CHAR | KW_INT | KW_FLOAT
    ;

lit_list: lit_value | lit_value ':' lit_list 
    ;

// tirei o lit_string, mas nao sei
lit_value: LIT_CHAR | LIT_INTEGER | LIT_REAL 
    ; 

//----------- FUNCTION

function: header '{' block '}' 
    ;

header: kw_type TK_IDENTIFIER '(' params ')' 
    ;

//pode ser vazio, mas nao pode sobrar virgula no final
params: kw_type TK_IDENTIFIER | l_param
    | 
    ;

l_param: kw_type TK_IDENTIFIER ',' l_param | kw_type TK_IDENTIFIER 
    ;

%%
