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
   22,   22,   22,   24,   24,   24,   25,   25,   25,   25,
   27,   27,   27,   27,   27,   26,   30,   30,   30,   31,
   31,   16,   16,   16,   16,   32,   33,   34,   35,   36,
   36,    6,    6,    6,    7,    7,    7,    8,    8,   28,
   28,   28,   28,   29,   29,   29,   29,   29,   29,   29,
   29,   29,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    1,    2,    2,    1,    1,    5,    6,
    6,    8,    2,    5,    2,    1,    0,    2,    4,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    0,    1,
    1,    6,    3,    2,    2,    1,    1,    3,    3,    2,
    1,    1,    1,    1,    3,    3,    1,    3,    2,    3,
    1,    2,    2,    4,    1,    4,    1,    3,    0,    1,
    3,    1,    1,    1,    1,    6,    8,    5,    9,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
   72,   73,   74,    0,    1,    0,    0,    7,    8,    0,
    0,    5,    6,    0,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,
    0,   24,   25,   26,   27,   28,   30,   31,   62,   63,
   64,   65,   76,   77,   75,    0,    0,    0,    0,   16,
    0,    0,    0,    0,   34,    0,    0,    0,    0,    0,
   55,   40,    0,    0,   43,   44,    0,    0,    0,   35,
    0,    0,    0,   20,    0,    9,    0,    0,   14,    0,
    0,    0,    0,    0,    0,   52,    0,    0,    0,    0,
   53,   80,   81,   82,   83,    0,   84,   85,   86,   87,
   88,   89,   90,   91,   92,    0,    0,    0,    0,   33,
    0,   22,    0,   11,    0,   10,    0,    0,    0,    0,
    0,    0,   46,   50,    0,    0,   38,   39,    0,    0,
    0,    0,   19,    0,   23,   71,   68,    0,   54,    0,
   56,    0,    0,   12,    0,    0,    0,    0,   58,   32,
   79,    0,    0,    0,   67,    0,   61,   69,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   10,   61,  131,   11,  135,
   49,   50,   30,  136,   32,   33,   34,   35,   36,   37,
   38,   62,   70,   63,   64,   65,   66,   96,  106,  122,
  149,   39,   40,   41,   42,  137,
};
static const YYINT yysindex[] = {                       -75,
    0,    0,    0,    0,    0,  -75,  -75,    0,    0,  -34,
  -94,    0,    0,   19, -237,  -90,    0,  -89, -224,  -75,
    7,   33,   52,   73, -222,  -33,  -25,  -31,    0,  -43,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   57,   27, -152,   92,    0,
  -89,  -33,  -33, -136,    0,  -12, -135,  -29,  -29, -131,
    0,    0,  113,   89,    0,    0,   56,  118,  -19,    0,
   -6,  -33,  -33,    0,  -90,    0,   47,  108,    0,   94,
  116,  119,   98,  -33,  -15,    0,   13,   83,  113,   89,
    0,    0,    0,    0,    0,  -19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -29,  -25,   13,  -25,    0,
   72,    0,  -89,    0,  -75,    0,  -82,  -90,  -33,   78,
  142,  149,    0,    0,  113,   89,    0,    0,  130,  134,
  135,  -79,    0,  -90,    0,    0,    0,  -72,    0,  -15,
    0,  -33,  -89,    0,  108,  -65,  -33,  154,    0,    0,
    0,  -90,  159,  -15,    0,  -90,    0,    0,
};
static const YYINT yyrindex[] = {                       201,
    0,    0,    0,    0,    0,  204,  207,    0,    0,    0,
    0,    0,    0,    0,    0,  -32,    0,    0,    0,  167,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   29,    0,    0,    0,    0,
    0,    0,   42,  -27,    0,    0,    2,  -56,    0,    0,
  -41,    0,    0,    0,  -32,    0,    0,  172,    0,    0,
    0,    0,    0,    0,  173,    0,   76,    0,   55,   44,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -35,    0,    0,
  174,    0,    0,    0,   16,   70,    0,    0,    0,  157,
    0,    0,    0,  -35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  176,  -28,    0,  177,    0,    0,
    0,  -35,    0,    0,    0,  -35,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   35,    0,    0,    0,    0,   -8,   -1,   77,    0,   24,
    0,  104,  151,    6,    0,    0,    0,    0,    0,    0,
    0,  150,  -42,  103,   60,    0,  -77,  -39,    0,    0,
   71,    0,    0,    0,    0,   12,
};
#define YYTABLESIZE 363
static const YYINT yytable[] = {                         59,
   15,   57,   36,   59,   60,   57,   58,  121,   60,   57,
   58,   48,   60,   42,   69,   57,   46,   37,   60,   57,
   69,   31,   60,   29,  105,  109,   29,   85,   16,   72,
   66,   42,   16,   51,   17,   92,   94,   21,   95,   29,
   12,   13,   51,   51,   51,   51,   51,   45,  105,   80,
  105,   47,   55,  123,   92,   94,   45,   95,   20,   73,
   51,   51,  148,   51,  127,   42,  128,   51,   36,   51,
   51,   51,   52,   51,   45,   45,  148,   45,   84,   18,
   31,   74,   41,   37,   49,   93,  105,   51,   51,   29,
   51,   53,   29,   51,   51,   47,   66,   42,   29,   75,
   41,   47,   49,   47,   93,  114,  132,  113,   45,   19,
   48,  130,   54,   47,   47,   76,   47,   88,   90,   77,
   51,   51,   78,  124,   92,   94,   51,   95,   48,   71,
   92,   94,   79,   95,   41,   47,   49,   47,   83,   86,
   45,  130,  103,   91,  104,  146,   84,   47,  103,  107,
  104,  115,  116,   51,   92,   94,  117,   95,  119,  118,
   87,   89,   48,  155,  129,  126,   41,  158,   49,   22,
  139,  108,   23,   24,   93,   25,   26,   27,  134,   47,
   93,    1,    2,    3,   28,  140,   43,   44,   45,  141,
  142,  143,  147,  144,   48,  145,  152,  154,  125,  156,
    2,   81,   82,    3,   93,   36,    4,   17,   89,   71,
   21,   71,   15,   59,   57,   78,   18,   60,  133,  151,
   37,  110,  111,    0,  157,  112,   29,    0,    0,    0,
    0,    0,    0,  120,   42,    0,    0,   42,    0,    0,
   14,   56,   43,   44,   45,   67,   43,   44,   45,   67,
   43,   44,   45,   68,    0,   67,   43,   44,   45,   67,
   43,   44,   45,   51,    0,    0,   51,    0,  138,    0,
   51,   51,   51,   51,   51,   51,    0,   45,    0,    0,
   45,    0,    0,    0,   45,   45,   45,   45,   45,   45,
   51,  150,    0,   51,    0,    0,  153,   51,   51,   51,
   51,   51,   51,   41,    0,   49,   41,    0,   49,    0,
   47,   47,   47,   47,   47,   47,   47,    0,    0,   47,
    0,    0,    0,   47,   47,   47,   47,   47,   47,    0,
    0,   48,    0,    0,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   47,   47,   47,   47,   47,   47,
    0,   97,   98,   99,  100,  101,  102,   97,   98,   99,
  100,  101,  102,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   59,   33,   38,   35,   40,   85,   38,   35,
   40,   20,   38,   41,   40,   35,   18,   59,   38,   35,
   40,   16,   38,   59,   64,   32,   59,   40,  123,   61,
   59,   59,  123,   32,   11,   42,   43,  275,   45,   16,
    6,    7,   41,   42,   43,   44,   45,   32,   88,   51,
   90,  276,  275,   41,   42,   43,   41,   45,   40,   91,
   59,   60,  140,   62,  107,   93,  109,   61,  125,   41,
   42,   43,   40,   45,   59,   60,  154,   62,   91,   61,
   75,  125,   41,  125,   41,   92,  126,   59,   60,  125,
   62,   40,  125,   92,   93,   41,  125,  125,   75,   59,
   59,   60,   59,   62,   92,   59,  115,   61,   93,   91,
   41,  113,   40,   59,   60,   59,   62,   58,   59,   93,
   92,   93,  275,   41,   42,   43,  125,   45,   59,   27,
   42,   43,   41,   45,   93,   60,   93,   62,  275,  275,
  125,  143,   60,  275,   62,  134,   91,   93,   60,   32,
   62,   44,   59,  125,   42,   43,   41,   45,   61,   41,
   58,   59,   93,  152,   93,  106,  125,  156,  125,  260,
   93,   69,  263,  264,   92,  266,  267,  268,  261,  125,
   92,  257,  258,  259,  275,   44,  276,  277,  278,   41,
   61,   58,  265,   59,  125,  275,  262,   44,   96,   41,
    0,   52,   53,    0,   92,  262,    0,   41,  106,  107,
  125,  109,   41,   41,   41,   59,   41,   41,  115,  143,
  262,   72,   73,   -1,  154,   75,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   84,  262,   -1,   -1,  265,   -1,   -1,
  275,  275,  276,  277,  278,  275,  276,  277,  278,  275,
  276,  277,  278,  279,   -1,  275,  276,  277,  278,  275,
  276,  277,  278,  262,   -1,   -1,  265,   -1,  119,   -1,
  269,  270,  271,  272,  273,  274,   -1,  262,   -1,   -1,
  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
  262,  142,   -1,  265,   -1,   -1,  147,  269,  270,  271,
  272,  273,  274,  262,   -1,  262,  265,   -1,  265,   -1,
  269,  270,  271,  272,  273,  274,  262,   -1,   -1,  265,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
   -1,  269,  270,  271,  272,  273,  274,  269,  270,  271,
  272,  273,  274,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 319
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"' '","'!'",0,"'#'",0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,0,0,0,0,0,
0,0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'['","'\\\\'","']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT",
"KW_FLOAT","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_TO","KW_READ",
"KW_RETURN","KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"print_list : arithmetic_expression",
"print_list : LIT_STRING ' ' print_list",
"print_list : arithmetic_expression ' ' print_list",
"return_c : KW_RETURN expression",
"expression : arithmetic_expression",
"expression : boolean_expression",
"expression : function_expression",
"arithmetic_expression : id",
"arithmetic_expression : arithmetic_expression arithmetic_op arithmetic_expression",
"arithmetic_expression : '(' arithmetic_expression ')'",
"boolean_expression : arithmetic_expression",
"boolean_expression : boolean_expression relational_op boolean_expression",
"boolean_expression : '!' boolean_expression",
"boolean_expression : '(' boolean_expression ')'",
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
"if_c : KW_IF '(' expression ')' KW_THEN flow_command",
"if_then_else_c : KW_IF '(' expression ')' KW_THEN flow_command KW_ELSE flow_command",
"while_c : KW_WHILE '(' expression ')' flow_command",
"for_c : KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' flow_command",
"flow_command : block",
"flow_command : simple_command",
"scalar_type : KW_CHAR",
"scalar_type : KW_INT",
"scalar_type : KW_FLOAT",
"init_value : LIT_CHAR",
"init_value : LIT_INTEGER",
"init_value : LIT_REAL",
"init_values_list : init_value",
"init_values_list : init_value ':' init_values_list",
"arithmetic_op : '*'",
"arithmetic_op : '\\\\'",
"arithmetic_op : '+'",
"arithmetic_op : '-'",
"relational_op : OPERATOR_LE",
"relational_op : OPERATOR_GE",
"relational_op : OPERATOR_EQ",
"relational_op : OPERATOR_NE",
"relational_op : OPERATOR_AND",
"relational_op : OPERATOR_OR",
"relational_op : '<'",
"relational_op : '>'",
"relational_op : arithmetic_op",

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
