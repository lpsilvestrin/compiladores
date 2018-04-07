%{
#include<stdio.h>
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
%left '+' '-'
%left '*' '/'
%nonassoc KW_THEN
%nonassoc KW_ELSE
%nonassoc KW_TO

%%
//----------- MAIN FLOW
//a program is a (empty) list of instructions
//accepts empty production
program: 
    instructions
    |
    ; 

//the instructions is a list of global definitions and functions (without any order)
instructions: 
    global_def 
    | function_def 
    | global_def instructions 
    | function_def instructions
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

vector_def: 
    scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ';' 
    | scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' '=' init_values_list ';' 
    ;


//----------- FUNCTION
//a function is made of a header and a block
function_def: header block 
    ;

// the header have a return type, an identifier and a (empty) list of arguments
header: 
    scalar_type TK_IDENTIFIER '(' def_parameters ')' 
    ;

//accepts empty production
def_parameters: 
    scalar_type TK_IDENTIFIER 
    | scalar_type TK_IDENTIFIER ',' tail_def_parameters
    | 
    ;

tail_def_parameters: 
    scalar_type TK_IDENTIFIER 
    | scalar_type TK_IDENTIFIER ',' tail_def_parameters 
    ;


//----------- BLOCK  
//the {} are from the block
block: 
    '{' commands_list '}' 
    ;

//the ; is associated to the commands list, and not the command itself, therefore we can have <empty>;<something>
commands_list: 
    simple_command 
    | simple_command ';' commands_list
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

//for now i'm considering that you cannot assign values to pointers and refferences
assignment_c: 
    vector_assignment 
    | var_assignment 
    ;

vector_assignment: 
    TK_IDENTIFIER '[' expression ']' '=' expression
    ;

var_assignment: 
    TK_IDENTIFIER '=' expression
    ;

//read should be followed by a variable to put something inside or it, it only accepts scalar values, so no vector or pointers here
read_c: 
    KW_READ TK_IDENTIFIER 
    ;

//print if followed by a list of things to be printed (token " " between the items)
print_c: 
    KW_PRINT print_list
    ;

//each element can be either a string or an arithmetic expression
print_list: 
    LIT_STRING 
    | arithmetic_or_boolean_expression 
    | LIT_STRING " " print_list 
    | arithmetic_or_boolean_expression " " print_list 
    ;

return_c: KW_RETURN expression 
    ;


//----------- EXPRESSION
//for the moment we have no distinction between boolean and arithmetic
//for the moment it should accept every kind of operator and sub-expression, and therefore i'm considering it accepts # and &
expression: 
    arithmetic_or_boolean_expression 
    | function_expression 
    ;

//an arithmetic expression is a recursive definition of operations over the leaves 
//boolean expressions are made of relational operations applied over arithmetic expressions or 
//logic operators aplied over logic expressions
//he defined the relational operator set as the union of the arithmetic set and the usual relational ones
arithmetic_or_boolean_expression: 
    id 
    | arithmetic_or_boolean_expression '+' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression '-' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression '*' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression '/' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression '<' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression '>' arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_LE arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_GE arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_EQ arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_NE arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_AND arithmetic_or_boolean_expression 
    | arithmetic_or_boolean_expression OPERATOR_OR arithmetic_or_boolean_expression 
    | '!' arithmetic_or_boolean_expression 
    | '(' arithmetic_or_boolean_expression ')'
    ;

//the leaves can be variables, vector positions with integer expression inside and literals
//for the moment we have no distinction between logical, arithmetic and string operations, and therefore id accepts all
id: 
    TK_IDENTIFIER 
    | '#' TK_IDENTIFIER 
    | '&' TK_IDENTIFIER 
    | TK_IDENTIFIER '[' expression ']' 
    | init_value 
    ;

//a function is a identifier followed by its parameters separated by a ','
function_expression: 
    TK_IDENTIFIER '(' parameters_list ')'
    ;

//accepts empty production
parameters_list: 
    id 
    | id ',' tail_parameters_list 
    | 
    ;

tail_parameters_list: 
    id 
    | id ',' tail_parameters_list 
    ;


//----------- FLOW CONTROL

flow_c: 
    if_c 
    | if_then_else_c 
    | while_c 
    | for_c
    ;

if_c: 
    KW_IF '(' expression ')' KW_THEN simple_command
    ;

if_then_else_c: 
    KW_IF '(' expression ')' KW_THEN simple_command KW_ELSE simple_command
    ;

while_c: 
    KW_WHILE '(' expression ')' simple_command
    ;

for_c: 
    KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command
    ;

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
    | init_value ':' init_values_list 
    ; // CAN WE HAVE POINTERS HERE ???

// ---------------------- ISSUES

//(default nope)
//podemos por ponteiros nos valores de inicialização de vetores ?
//assignments podem ser feitos com # e & ?!!!!!!!!!!
//a lista do print pode ser vazia?
//expressoes de aritmetica podem ser aplicadas sobre ponteiros e memory refs ?
//as estruturas de flow control podem aceitar um bloco ou apenas um comando?
//podemos aceitar vetor[function()] ?


%%
