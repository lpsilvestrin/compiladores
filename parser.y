%{
#include <stdlib.h>
#include <stdio.h>
%}

%start program

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
%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR  

/*association rules*/
%left OPERATOR_AND OPERATOR_OR
%left OPERATOR_EQ OPERATOR_GE OPERATOR_LE OPERATOR_NE
%left '(' ')'
%left '{' '}'
%left ','
%left '!'
%left '*' '/'
%left '+' '-'
%left '<' '>'
%right '='
%left ';'
%nonassoc KW_THEN
%nonassoc KW_ELSE
%nonassoc KW_TO

%%
//----------- MAIN FLOW
//a program is a (empty) list of instructions
//accepts empty production
program: 
    program instruction 
    |
    ; 

//the instructions is a list of global definitions and functions (without any order)
instruction: 
    global_def 
    | function_def 
    ;


//----------- GLOBAL STRUCTURES
//a global definition can be a scalar variable or a vector
global_def: 
    global_var_def 
    | vector_def
    ;

//an init value can only be scalar values
global_var_def: 
    scalar_type TK_IDENTIFIER '=' init_value ';' 
    | scalar_type '#' TK_IDENTIFIER '=' init_value ';'
    ;

//initialization is given by values separated by " " after a ":"
vector_def: 
    scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ';' 
    | scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' init_values_list ';' 
    ;


//----------- FUNCTION
//a function is made of a header and a block
function_def: header block 
    ;

// the header have a return type, an identifier and a (empty) list of arguments
header: 
    scalar_type TK_IDENTIFIER '('  ')' 
    ; //def_parameters

//accepts empty production
def_parameters: 
    scalar_type TK_IDENTIFIER 
    | tail_def_parameters
    | 
    ;

tail_def_parameters: 
    scalar_type TK_IDENTIFIER 
    | tail_def_parameters ',' scalar_type TK_IDENTIFIER 
    ;


//----------- BLOCK  
//the {} are from the block
block: 
    '{' | block '}';

commands_list: | ;

//----------- LEAVES
//list of scalar types
scalar_type: 
    KW_CHAR 
    | KW_INT 
    | KW_FLOAT 
    ;

//initialization possibilities
init_value: 
    LIT_CHAR 
    | LIT_INTEGER 
    | LIT_REAL
    ;

//vector init list
init_values_list: 
    init_value 
    | init_values_list init_value
    ; // CAN WE HAVE POINTERS HERE ???

// ---------------------- ISSUES

//(default nope)
//podemos por ponteiros nos valores de inicialização de vetores ? sim
//assignments podem ser feitos com # ?!!!!!!!!!!
//a lista do print pode ser vazia?
//expressoes de aritmetica podem ser aplicadas sobre ponteiros e memory refs ?
//podemos aceitar vetor[function()] ?


%%
int yyerror (char const *s) {
    fflush(stderr);
    fprintf(stderr,"ERROR: %s ---> Line: %d\n", s, getLineNumber());
    exit(3);
}