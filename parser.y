%{
#include <stdlib.h>
#include <stdio.h>
#include "astree.h"
#include "hashtable.h"

%}

%union
{
	ASTree* astree_pointer;
    hashNode* hashTable_pointer;
}

%start program

/*grammar rules*/
%type<astree_pointer> program
%type<astree_pointer> instruction
%type<astree_pointer> global_def
%type<astree_pointer> function_def
%type<astree_pointer> global_var_def
%type<astree_pointer> vector_def
%type<astree_pointer> header
%type<astree_pointer> block
%type<astree_pointer> def_parameters
%type<astree_pointer> def_parameters_tail
%type<astree_pointer> commands_list
%type<astree_pointer> simple_command
%type<astree_pointer> assignment_c
%type<astree_pointer> flow_c 
%type<astree_pointer> read_c
%type<astree_pointer> print_c 
%type<astree_pointer> return_c
%type<astree_pointer> vector_assignment 
%type<astree_pointer> var_assignment
%type<astree_pointer> expression
%type<astree_pointer> parameters_list
%type<astree_pointer> parameters_list_tail
%type<astree_pointer> if_c 
%type<astree_pointer> if_then_else_c 
%type<astree_pointer> while_c 
%type<astree_pointer> for_c
%type<astree_pointer> init_value
%type<astree_pointer> init_values_list
%type<astree_pointer> scalar_type
%type<astree_pointer> size



/*lang181 special tokens*/
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

%token<hashTable_pointer> TK_IDENTIFIER
%token<hashTable_pointer> LIT_INTEGER
%token<hashTable_pointer> LIT_REAL
%token<hashTable_pointer> LIT_CHAR
%token<hashTable_pointer> LIT_STRING

%token TOKEN_ERROR  

/*association rules*/
//%left //comentei oq nao faz diferenca
//%left '('
//%left '[' 
%left OPERATOR_AND OPERATOR_OR OPERATOR_EQ OPERATOR_GE OPERATOR_LE OPERATOR_NE '<' '>'
%left '-' '+'
%left '*' '/'
%right '!'
%nonassoc KW_THEN
%nonassoc KW_ELSE
//%nonassoc ')'
//%nonassoc ']'
//%nonassoc ','
//%nonassoc '#'
//%nonassoc '&'


%%
//----------- MAIN FLOW
//a program is a (empty) list of instructions
//accepts empty production
program: 
    program instruction     {$$=astree_create(AST_INITIAL,0,$2,$1,0,0);}
    |                       {$$=0;} // <<<<<<<<<<<<<<< CHECK THIS
    ; 

//the instructions is a list of global definitions and functions (without any order)
instruction: 
    global_def      {$$=$1;} //only one place to go
    | function_def  {$$=$1;}
    ;


//----------- GLOBAL STRUCTURES
//a global definition can be a scalar variable or a vector
global_def: 
    global_var_def  {$$=$1;}
    | vector_def    {$$=$1;}
    ;

//an init value can only be scalar values
global_var_def: 
    scalar_type TK_IDENTIFIER '=' init_value ';'        {$$=astree_create(AST_GLOBAL_VAR_DEF,$2,$1,$4,0,0);}
    | scalar_type '#' TK_IDENTIFIER '=' init_value ';'  {$$=astree_create(AST_GLOBAL_VAR_DEF,$3,$1,$5,0,0);}  
    ;

//initialization is given by values separated by " " after a ":"
vector_def: 
    scalar_type TK_IDENTIFIER '[' size ']' ';'                          {$$=astree_create(AST_VECTOR_DEF,$2,$1,$4,0,0);} 
    | scalar_type TK_IDENTIFIER '[' size ']' ':' init_values_list ';'   {$$=astree_create(AST_VECTOR_DEF,$2,$1,$4,$7,0);}  
    ;



//----------- FUNCTION
//a function is made of a header and a block
function_def: 
    header block    {$$=astree_create(AST_FUNCTION_DEF,0,$1,$2,0,0);}
    ;

// the header have a return type, an identifier and a (empty) list of arguments
header:
    scalar_type TK_IDENTIFIER def_parameters    {$$=astree_create(AST_HEADER,$2,$1,$3,0,0);}
    ; 

def_parameters: 
	'(' ')'
	| '(' def_parameters_tail ')' 
    ;

def_parameters_tail:
	scalar_type TK_IDENTIFIER  
    | def_parameters_tail ',' scalar_type TK_IDENTIFIER
	;	


//----------- BLOCK  
//the {} are from the block
block: 
    '{' commands_list '}' 
    ;

//the ; is associated to the commands list, and not the command itself, therefore we can have <empty>;<something>
commands_list: 
    simple_command 
    | commands_list ';' simple_command
    ;


//----------- SIMPLE COMMAND 
//no ; here!!
//a block is considered as a simple command
//accepts empty production
simple_command: 
    block 
    | assignment_c 
    | flow_c 
    | read_c 
    | print_c 
    | return_c
    | 
    ;

//for now i'm considering that you CAN assign values to pointers and refferences
assignment_c: 
    vector_assignment 
    | var_assignment 
    ;

vector_assignment: 
    TK_IDENTIFIER '[' expression ']' '=' expression 
    ;

//accepting pointers and mem refs only in the leaves
var_assignment: 
    TK_IDENTIFIER '=' expression
    ;

//read should be followed by a variable to put something inside or it, it only accepts scalar values, so no vector or pointers here
read_c: 
    KW_READ TK_IDENTIFIER 
    ;

//print if followed by a list of things to be printed (token " " between the items)
//each element can be either a string or an arithmetic expression
print_c: 
    KW_PRINT 
    | print_c LIT_STRING  
    | print_c expression  
    ;

return_c: KW_RETURN expression 
    ;


//----------- EXPRESSION
//for the moment it should accept every kind of operator and sub-expression, and therefore i'm considering it accepts # and &
//an arithmetic expression is a recursive definition of operations over the leaves 
//boolean expressions are made of relational operations applied over arithmetic expressions or 
//logic operators aplied over logic expressions
//he defined the relational operator set as the union of the arithmetic set and the usual relational ones
expression: 
    init_value
    | TK_IDENTIFIER 
    | '#' TK_IDENTIFIER 
    | '&' TK_IDENTIFIER
    | TK_IDENTIFIER '[' expression ']' 
    | TK_IDENTIFIER parameters_list
    | '!' expression 
    | '-' expression 
    | '(' expression ')'
    | expression '+' expression 
    | expression '-' expression 
    | expression '*' expression 
    | expression '/' expression 
    | expression '<' expression 
    | expression '>' expression 
    | expression OPERATOR_LE expression 
    | expression OPERATOR_GE expression 
    | expression OPERATOR_EQ expression 
    | expression OPERATOR_NE expression 
    | expression OPERATOR_AND expression 
    | expression OPERATOR_OR expression 
    ;

//the leaves can be variables, vector positions with integer expression inside and literals
//for the moment we have no distinction between logical, arithmetic and string operations, and therefore id accepts all
//id: 
//    TK_IDENTIFIER 
//    | '#' TK_IDENTIFIER 
//    | '&' TK_IDENTIFIER 
//    | TK_IDENTIFIER '[' expression ']' 
//    | TK_IDENTIFIER parameters_list  
//    | init_value 
//    ;

//accepts empty production
parameters_list: 
	'(' ')'
    | '(' parameters_list_tail ')'
    ;

parameters_list_tail:
	expression 
    | parameters_list_tail ',' expression  
	;

//a function is a identifier followed by its parameters separated by a ','
//function_expression: 
//     TK_IDENTIFIER parameters_list
//    ;



//----------- FLOW CONTROL

flow_c: 
    if_c 
    | if_then_else_c 
    | while_c 
    | for_c
    ;

if_c: 
    KW_IF '(' expression ')' KW_THEN simple_command
    ; { $$=astree_create(KW_IF,,$3,$6,0,0); }

if_then_else_c: 
    KW_IF '(' expression ')' KW_THEN simple_command KW_ELSE simple_command { $$=astree_create(KW_IF,0,$3,$6,$8,0); }
    ;

while_c: 
    KW_WHILE '(' expression ')' simple_command { $$=astree_create(KW_WHILE,0,$3,$5,0,0); }
    ;

for_c: 
    KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command { $$=astree_create(KW_FOR,$3,$5,$7,$9,0); }
    ;

//----------- LEAVES
//list of scalar types
scalar_type: 
    KW_CHAR { $$=astree_create(KW_CHAR,0,0,0,0,0); }
    | KW_INT { $$=astree_create(KW_INT,0,0,0,0,0); }
    | KW_FLOAT { $$=astree_create(KW_FLOAT,0,0,0,0,0); }
    ;

//initialization possibilities
init_value: 
    LIT_CHAR { $$=astree_create(LIT_CHAR, 0,0,0,0,0); } 
    | LIT_INTEGER { $$=astree_create(LIT_INTEGER, 0,0,0,0,0); }
    | LIT_REAL { $$=astree_create(LIT_REAL,0,0,0,0,0); }
    ;

//vector init list
init_values_list: 
    init_value 
    | init_values_list init_value
    ; 

size:
    LIT_INTEGER {$$=astree_create(AST_INT,$1,0,0,0,0);}
    ;    


%%
int yyerror (char const *s) {
    fflush(stderr);
    fprintf(stderr,"ERROR: %s ---> Line: %d\n", s, getLineNumber());
    exit(3);
}
