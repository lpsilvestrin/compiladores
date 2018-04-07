/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include<stdio.h>
#line 23 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_CHAR 257
#define KW_INT 258
#define KW_FLOAT 259
#define KW_IF 260
#define KW_THEN 261
#define KW_ELSE 262
#define KW_WHILE 263
#define KW_FOR 264
#define KW_TO 265
#define KW_READ 266
#define KW_RETURN 267
#define KW_PRINT 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_NE 272
#define OPERATOR_AND 273
#define OPERATOR_OR 274
#define TK_IDENTIFIER 275
#define LIT_INTEGER 276
#define LIT_REAL 277
#define LIT_CHAR 278
#define LIT_STRING 279
#define TOKEN_ERROR 280
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    2,    2,    4,    4,
    5,    5,    3,    9,   11,   11,   11,   12,   12,   10,
   13,   13,   14,   14,   14,   14,   14,   14,   14,   15,
   15,   20,   21,   17,   18,   23,   23,   23,   23,   19,
   22,   22,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   26,   26,   26,
   26,   26,   25,   27,   27,   27,   28,   28,   16,   16,
   16,   16,   29,   30,   31,   32,    6,    6,    6,    7,
    7,    7,    8,    8,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    1,    2,    2,    1,    1,    5,    6,
    6,    8,    2,    5,    2,    1,    0,    2,    4,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    0,    1,
    1,    6,    3,    2,    2,    1,    1,    3,    3,    2,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    1,    2,    2,
    4,    1,    4,    1,    3,    0,    1,    3,    1,    1,
    1,    1,    6,    8,    5,    9,    1,    1,    1,    1,
    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
   77,   78,   79,    0,    1,    0,    0,    7,    8,    0,
    0,    5,    6,    0,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,
    0,   24,   25,   26,   27,   28,   30,   31,   69,   70,
   71,   72,   81,   82,   80,    0,    0,    0,    0,   16,
    0,    0,    0,    0,   34,    0,    0,    0,    0,    0,
   62,   40,    0,   42,   43,    0,    0,   35,    0,    0,
    0,   20,    0,    9,    0,    0,   14,    0,    0,    0,
    0,    0,    0,   59,    0,    0,   60,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   33,    0,   22,    0,   11,    0,   10,    0,    0,
    0,    0,    0,    0,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,   39,    0,
    0,    0,    0,   19,    0,   75,    0,   61,    0,   63,
    0,    0,   12,    0,    0,    0,    0,   65,   32,   84,
    0,    0,    0,   74,    0,   68,   76,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   10,   61,  132,   11,   29,
   49,   50,   30,   31,   32,   33,   34,   35,   36,   37,
   38,   62,   68,   63,   64,   65,  114,  148,   39,   40,
   41,   42,
};
static const YYINT yysindex[] = {                       -88,
    0,    0,    0,    0,    0,  -88,  -88,    0,    0,  -34,
 -114,    0,    0,  117, -254,  -69,    0,  -67, -250,  -88,
  -32,   -5,   -3,   13, -237,  -27,  -33,  -39,    0,  -54,
   14,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   19,  -37, -194,   64,    0,
  -67,  -27,  -27, -166,    0,  -36, -160,  -23,  -23, -157,
    0,    0,  160,    0,    0,   30,   95,    0,    4,  -27,
  -27,    0,  -69,    0,  -41,  106,    0,   78,   97,  120,
  101,  -27,  -19,    0,   27,  160,    0,  -23,  -23,  -23,
  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -33,
  -33,    0,   61,    0,  -67,    0,  -88,    0,  -89,  -69,
  -27,   81,  135,  141,    0,  160,  160,  160,  160,  160,
  160,  113,  113,  -35,  -35,  160,  160,    0,    0,  123,
  131,  145,  -85,    0,  -69,    0,  -51,    0,  -19,    0,
  -27,  -67,    0,  106,  -47,  -27,  172,    0,    0,    0,
  -69,  180,  -19,    0,  -69,    0,    0,
};
static const YYINT yyrindex[] = {                       223,
    0,    0,    0,    0,    0,  226,  227,    0,    0,    0,
    0,    0,    0,    0,    0,  -28,    0,    0,    0,  187,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  104,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,    0,    0,    0,    0,
    0,    0,  108,    0,    0,   -2,   17,    0,   40,    0,
    0,    0,  -28,    0,    0,  189,    0,    0,    0,    0,
    0,    0,  190,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
    0,    0,  199,    0,    0,   87,   88,   92,   93,   94,
   99,   63,   71,   43,   51,  100,  107,    0,    0,    0,
  188,    0,    0,    0,   58,    0,    0,    0,    0,    0,
    0,    0,    0,  220,  -25,    0,  221,    0,    0,    0,
   58,    0,    0,    0,   58,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   26,    0,    0,    0,    0,   -6,  263,  122,    0,  254,
    0,  159,  211, -107,    0,    0,    0,    0,    0,    0,
    0,  269,  -77,  348,    0,   24,    0,  133,    0,    0,
    0,    0,
};
#define YYTABLESIZE 449
static const YYINT yytable[] = {                         59,
   15,   57,  136,   83,   60,   59,   58,   57,   16,   59,
   60,   57,   58,   48,   60,   57,   58,  106,   60,  105,
   21,   70,  128,  129,   98,   47,   99,  145,   51,   58,
   29,   12,   13,   73,   52,  101,   53,   55,   58,   58,
   58,   58,   58,  154,   58,   96,   94,  157,   95,   56,
   97,   71,   54,   16,   82,   75,   58,   58,   56,   58,
   58,   58,   58,   98,   58,   99,   58,  115,   96,   94,
   72,   95,   73,   97,   46,   36,   56,   74,   58,   58,
   76,   58,   47,   46,   46,   46,   98,   46,   99,   46,
   58,   47,   47,   47,   44,   47,   29,   47,   37,   73,
  133,   46,   45,   44,   77,   44,  113,   44,   81,   47,
   56,   45,   58,   45,   84,   45,   29,   87,   50,   51,
   82,   44,   58,   52,   53,   54,  100,   50,   51,   45,
   55,   48,   52,   53,   54,   46,  108,  109,   49,   55,
   48,   36,   56,   47,   58,   50,   51,   49,   41,  107,
   52,   53,   54,  130,   96,   44,   20,   55,   48,   97,
  110,  111,  147,   45,   37,   49,   41,   46,    1,    2,
    3,  135,   98,  138,   99,   47,  147,   18,  139,   50,
   51,  140,   29,  141,   52,   53,   54,   44,  142,  144,
   22,   55,   48,   23,   24,   45,   25,   26,   27,   49,
   41,   96,   94,  143,   95,   28,   97,   19,   43,   44,
   45,   50,   51,  146,  151,  153,   52,   53,   54,   98,
  155,   99,    2,   55,   48,    3,    4,   17,   21,   15,
   66,   49,   41,   88,   89,   90,   91,   92,   93,   64,
   14,   66,   43,   44,   45,   67,   83,   56,   43,   44,
   45,   66,   43,   44,   45,   66,   43,   44,   45,   58,
   18,   67,   58,  150,   17,  134,   58,   58,   58,   58,
   58,   58,   88,   89,   90,   91,   92,   93,   36,   56,
   46,   58,   56,  104,   58,  156,    0,    0,   58,   58,
   58,   58,   58,   58,    0,   88,   89,   90,   91,   92,
   93,   37,    0,    0,   46,    0,    0,   46,    0,    0,
    0,    0,   47,   78,    0,   47,    0,    0,    0,   29,
   79,   80,    0,    0,   44,    0,    0,   44,    0,    0,
    0,    0,   45,    0,    0,   45,    0,    0,  102,  103,
    0,    0,    0,    0,    0,    0,    0,    0,   50,   51,
  112,   50,   51,   52,   53,   54,   52,   53,   54,    0,
   55,   48,    0,   55,   48,    0,    0,  131,   49,   41,
    0,   49,   41,    0,   69,    0,    0,    0,    0,  137,
    0,   88,   89,   90,   91,   92,   93,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  131,   85,   86,    0,    0,  149,
    0,    0,    0,    0,  152,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   88,   89,
   90,   91,   92,   93,    0,  116,  117,  118,  119,  120,
  121,  122,  123,  124,  125,  126,  127,   69,   69,
};
static const YYINT yycheck[] = {                         33,
   35,   35,  110,   40,   38,   33,   40,   35,  123,   33,
   38,   35,   40,   20,   38,   35,   40,   59,   38,   61,
  275,   61,  100,  101,   60,  276,   62,  135,   61,   32,
   59,    6,    7,   59,   40,   32,   40,  275,   41,   42,
   43,   44,   45,  151,   47,   42,   43,  155,   45,   32,
   47,   91,   40,  123,   91,   93,   59,   60,   41,   62,
   41,   42,   43,   60,   45,   62,   47,   41,   42,   43,
  125,   45,   59,   47,   32,   59,   59,   59,   59,   60,
  275,   62,   32,   41,   42,   43,   60,   45,   62,   47,
   93,   41,   42,   43,   32,   45,  125,   47,   59,  125,
  107,   59,   32,   41,   41,   43,   83,   45,  275,   59,
   93,   41,   93,   43,  275,   45,   59,  275,   32,   32,
   91,   59,  125,   32,   32,   32,   32,   41,   41,   59,
   32,   32,   41,   41,   41,   93,   59,   41,   32,   41,
   41,  125,  125,   93,  125,   59,   59,   41,   41,   44,
   59,   59,   59,   93,   42,   93,   40,   59,   59,   47,
   41,   61,  139,   93,  125,   59,   59,  125,  257,  258,
  259,  261,   60,   93,   62,  125,  153,   61,   44,   93,
   93,   41,  125,   61,   93,   93,   93,  125,   58,  275,
  260,   93,   93,  263,  264,  125,  266,  267,  268,   93,
   93,   42,   43,   59,   45,  275,   47,   91,  276,  277,
  278,  125,  125,  265,  262,   44,  125,  125,  125,   60,
   41,   62,    0,  125,  125,    0,    0,   41,  125,   41,
   41,  125,  125,  269,  270,  271,  272,  273,  274,   41,
  275,  275,  276,  277,  278,  279,   59,  275,  276,  277,
  278,  275,  276,  277,  278,  275,  276,  277,  278,  262,
   41,   41,  265,  142,   11,  107,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,  262,  262,
   18,  262,  265,   73,  265,  153,   -1,   -1,  269,  270,
  271,  272,  273,  274,   -1,  269,  270,  271,  272,  273,
  274,  262,   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,   -1,  262,   51,   -1,  265,   -1,   -1,   -1,  262,
   52,   53,   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,   70,   71,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  262,
   82,  265,  265,  262,  262,  262,  265,  265,  265,   -1,
  262,  262,   -1,  265,  265,   -1,   -1,  105,  262,  262,
   -1,  265,  265,   -1,   27,   -1,   -1,   -1,   -1,  111,
   -1,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  142,   58,   59,   -1,   -1,  141,
   -1,   -1,   -1,   -1,  146,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,
  271,  272,  273,  274,   -1,   88,   89,   90,   91,   92,
   93,   94,   95,   96,   97,   98,   99,  100,  101,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 315
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"' '","'!'",0,"'#'",0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,
0,0,0,0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_FLOAT",
"KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_TO","KW_READ","KW_RETURN",
"KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : instructions",
"program :",
"instructions : global_def",
"instructions : function_def",
"instructions : global_def instructions",
"instructions : function_def instructions",
"global_def : global_var_def",
"global_def : vector_def",
"global_var_def : scalar_type TK_IDENTIFIER '=' init_value ';'",
"global_var_def : scalar_type '#' TK_IDENTIFIER '=' init_value ';'",
"vector_def : scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"vector_def : scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' '=' init_values_list ';'",
"function_def : header block",
"header : scalar_type TK_IDENTIFIER '(' def_parameters ')'",
"def_parameters : scalar_type TK_IDENTIFIER",
"def_parameters : tail_def_parameters",
"def_parameters :",
"tail_def_parameters : scalar_type TK_IDENTIFIER",
"tail_def_parameters : scalar_type TK_IDENTIFIER ',' tail_def_parameters",
"block : '{' commands_list '}'",
"commands_list : simple_command",
"commands_list : simple_command ';' commands_list",
"simple_command : block",
"simple_command : assignment_c",
"simple_command : flow_c",
"simple_command : read_c",
"simple_command : print_c",
"simple_command : return_c",
"simple_command :",
"assignment_c : vector_assignment",
"assignment_c : var_assignment",
"vector_assignment : TK_IDENTIFIER '[' expression ']' '=' expression",
"var_assignment : TK_IDENTIFIER '=' expression",
"read_c : KW_READ TK_IDENTIFIER",
"print_c : KW_PRINT print_list",
"print_list : LIT_STRING",
"print_list : arithmetic_or_boolean_expression",
"print_list : LIT_STRING ' ' print_list",
"print_list : arithmetic_or_boolean_expression ' ' print_list",
"return_c : KW_RETURN expression",
"expression : arithmetic_or_boolean_expression",
"expression : function_expression",
"arithmetic_or_boolean_expression : id",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '+' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '-' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '*' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '/' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '<' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression '>' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_LE arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_GE arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_EQ arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_NE arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_AND arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : arithmetic_or_boolean_expression OPERATOR_OR arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : '!' arithmetic_or_boolean_expression",
"arithmetic_or_boolean_expression : '(' arithmetic_or_boolean_expression ')'",
"id : TK_IDENTIFIER",
"id : '#' TK_IDENTIFIER",
"id : '&' TK_IDENTIFIER",
"id : TK_IDENTIFIER '[' expression ']'",
"id : init_value",
"function_expression : TK_IDENTIFIER '(' parameters_list ')'",
"parameters_list : id",
"parameters_list : id ',' tail_parameters_list",
"parameters_list :",
"tail_parameters_list : id",
"tail_parameters_list : id ',' tail_parameters_list",
"flow_c : if_c",
"flow_c : if_then_else_c",
"flow_c : while_c",
"flow_c : for_c",
"if_c : KW_IF '(' expression ')' KW_THEN simple_command",
"if_then_else_c : KW_IF '(' expression ')' KW_THEN simple_command KW_ELSE simple_command",
"while_c : KW_WHILE '(' expression ')' simple_command",
"for_c : KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command",
"scalar_type : KW_CHAR",
"scalar_type : KW_INT",
"scalar_type : KW_FLOAT",
"init_value : LIT_CHAR",
"init_value : LIT_INTEGER",
"init_value : LIT_REAL",
"init_values_list : init_value",
"init_values_list : init_value ':' init_values_list",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
