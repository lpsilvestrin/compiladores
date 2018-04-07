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
%token KW_TO
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

// escalares
lit_value: LIT_CHAR | LIT_INTEGER | LIT_REAL 
    ; 

//----------- FUNCTION

function: header block 
    ;

header: kw_type TK_IDENTIFIER '(' def_params ')' 
    ;

//pode ser vazio, mas nao pode sobrar virgula no final
def_params: kw_type TK_IDENTIFIER | l_param
    | 
    ;

l_param: kw_type TK_IDENTIFIER ',' l_param | kw_type TK_IDENTIFIER 
    ;

//----------- BLOCK  
block: '{' l_commands '}' 
    ;

//it says that it can have an perty command and a ; after
l_commands: command | command ';' l_commands
    ;


//----------- COMMAND 
command: atrib | flow_c | read | print | return 
    | 
    ;

//missing pointers
atrib: TK_IDENTIFIER '=' expression | TK_IDENTIFIER '[' expression ']' '=' expression
    ;

read: KW_READ TK_IDENTIFIER 
    ;

print: KW_PRINT l_print 
    ;

l_print: LIT_STRING l_print | arit_expr l_print 
    | 
    ;

return: KW_RETURN expression ;

value: TK_IDENTIFIER | TK_IDENTIFIER '[' int_expression ']' | lit_value | '#' TK_IDENTIFIER | '&' TK_IDENTIFIER
    ;

expression: arit_expr |  bool_expr |  TK_IDENTIFIER '(' call_params ')';

call_params: value | l_value | ;

l_value: value ',' l_value | value ;

arit_expr: value | value aritmetic_op arit_expr | '('arit_expr ')'  
    ;

bool_expr: value relational_op bool_expr | '!' bool_expr | value 
    ;

relational_op: OPERATOR_LE | OPERATOR_GE | OPERATOR_EQ | OPERATOR_NE | OPERATOR_AND | OPERATOR_OR 
    ;
aritmetic_op: '*' | '\\' | '+' | '-' 
    ;

//----------- FLOW CONTROL

flow_c: for | if | ifthenelse | while 
    ;

for: KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' block
    ;

while: KW_WHILE '(' expression ')' block
    ;

if: KW_IF '(' expression ')' KW_THEN block
    ;

ifthenelse: KW_IF '(' expression ')' KW_THEN command KW_ELSE block
    ;


%%
