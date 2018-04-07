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
    6,    8,    2,    5,    2,    4,    0,    2,    4,    3,
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
   71,   72,   81,   82,   80,    0,    0,    0,    0,    0,
    0,    0,    0,   34,    0,    0,    0,    0,    0,   62,
   40,    0,   42,   43,    0,    0,   35,    0,    0,    0,
   20,    0,    9,    0,    0,   14,    0,    0,    0,    0,
    0,    0,    0,   59,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   33,    0,   22,    0,   11,    0,   10,    0,    0,    0,
    0,    0,    0,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,   49,   38,   39,    0,    0,
    0,    0,   16,    0,   75,    0,   61,    0,   63,    0,
    0,   12,    0,    0,    0,    0,   65,   32,   84,    0,
    0,    0,    0,   19,   74,    0,   68,   76,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   10,   60,  131,   11,   29,
   49,  133,   30,   31,   32,   33,   34,   35,   36,   37,
   38,   61,   67,   62,   63,   64,  113,  147,   39,   40,
   41,   42,
};
static const YYINT yysindex[] = {                      -152,
    0,    0,    0,    0,    0, -152, -152,    0,    0,  -34,
 -103,    0,    0,   -8, -252,  219,    0, -147, -250, -152,
   -7,   -3,   19,   28, -237,  -27,  -33,  -47,    0,  -56,
   13,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,  -16, -179,   56, -147,
  -27,  -27, -164,    0,  -15,  -23, -159,  -23, -157,    0,
    0,  405,    0,    0,   31,   95,    0,    4,  -27,  -27,
    0,  219,    0,  -11,   99,    0,   76,   98,  103,   79,
  -27,  -19,   91,    0,  380,    0,  -23,  -23,  -23,  -23,
  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -33,  -33,
    0,   55,    0, -147,    0, -152,    0, -112,  219,  -27,
   63,  108,  116,    0,   91,   91,   91,   91,  412,  412,
   59,   59,   30,   30,    0,    0,    0,    0,   97,  101,
  106, -113,    0,  219,    0,  -99,    0,  -19,    0,  -27,
 -147,    0,  123,  -93,  -27,  126,    0,    0,    0, -152,
  219,  131,  -19,    0,    0,  219,    0,    0,
};
static const YYINT yyrindex[] = {                       173,
    0,    0,    0,    0,    0,  174,  175,    0,    0,    0,
    0,    0,    0,    0,    0,  -32,    0,    0,    0,  136,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   54,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  373,    0,    0,    0,    0,    0,
    0,  -38,    0,    0,   -2,  -55,    0,  -50,    0,    0,
    0,  -32,    0,    0,  141,    0,    0,    0,    0,    0,
    0,  142,   83,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -37,    0,
    0,  143,    0,    0,   96,  109,  122,  139,  172,  331,
   53,   67,   20,   39,    0,    0,    0,    0,    0,  127,
    0,    0,    0,  -37,    0,    0,    0,    0,    0,    0,
    0,    0,  144,  -24,    0,  146,    0,    0,    0,    0,
  -37,    0,    0,    0,    0,  -37,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   22,    0,    0,    0,    0,   11,    6,   47,    0,  179,
    0,   41,  121,  -31,    0,    0,    0,    0,    0,    0,
    0,  392,  -66,  422,    0,  -64,    0,   42,    0,    0,
    0,    0,
};
#define YYTABLESIZE 684
static const YYINT yytable[] = {                         56,
   15,   57,   41,   36,   59,   56,   58,   57,   37,   56,
   59,   57,   58,   69,   59,   57,   58,  112,   59,   16,
   41,   29,   21,   46,   82,   47,   29,   12,   13,   58,
   48,   20,  127,  128,   73,  100,   51,   54,   58,   58,
   58,   58,   58,   70,   58,   93,   95,  105,   96,  104,
   94,   44,   18,   50,   41,   77,   58,   58,   52,   58,
   44,   44,   44,   97,   44,   98,   44,   53,   71,   36,
   45,   72,   73,  146,   37,   81,   74,  135,   44,   45,
   45,   45,   19,   45,   46,   45,   41,   29,  146,   97,
   58,   98,   29,   46,   46,   75,   76,   45,   47,   46,
   73,   95,  144,   96,    1,    2,    3,   47,   47,  130,
   80,   46,   44,   47,   56,   84,  132,   86,   97,  155,
   98,   81,   58,   56,  158,   47,   99,   50,   43,   44,
   45,   45,   93,   95,  107,   96,   50,   94,  108,  110,
   51,   56,  106,  109,   44,   46,  130,  129,  134,   51,
   97,  138,   98,   52,   50,  137,  139,  140,  141,   47,
  132,  143,   52,   45,  142,  145,  150,   51,  151,  153,
   53,  156,    2,    3,    4,   56,   17,   46,   21,   53,
   52,   15,   66,   64,   18,   83,   67,  149,   50,   17,
  154,   47,  103,    0,  157,    0,    0,   53,    0,    0,
    0,   51,    0,   54,    0,    0,   36,   56,    0,    0,
    0,   37,   54,    0,   52,    0,    0,    0,    0,    0,
   50,    0,    0,   41,   29,    0,   41,    0,    0,    0,
   54,   53,    0,   51,    0,    0,    0,    0,    0,    0,
   14,   65,   43,   44,   45,   66,   52,   55,   43,   44,
   45,   65,   43,   44,   45,   65,   43,   44,   45,   58,
    0,    0,   58,   53,   54,    0,   58,   58,   58,   58,
   58,   58,   87,   88,   89,   90,   91,   92,    0,    0,
    0,   44,    0,    0,   44,    0,    0,    0,   44,   44,
   44,   44,   44,   44,    0,    0,   54,    0,    0,    0,
   45,    0,    0,   45,    0,    0,    0,   45,   45,   45,
   45,   45,   45,    0,   46,    0,    0,   46,    0,    0,
    0,   46,   46,   46,   46,   46,   46,    0,   47,    0,
    0,   47,    0,    0,    0,   47,   47,   47,   47,   47,
   47,   16,    0,    0,   56,    0,    0,   56,    0,    0,
    0,   56,   56,   56,   56,   56,   56,   50,    0,    0,
   50,    0,   55,    0,   50,   50,   50,   50,   50,   50,
   51,   55,    0,   51,    0,    0,    0,   51,   51,   51,
   51,   51,   51,   52,    0,    0,   52,    0,    0,   55,
   52,   52,   52,   52,   52,   52,    0,    0,    0,    0,
   53,    0,    0,   53,    0,    0,    0,   53,   53,   53,
   53,   53,   53,   58,   58,   58,    0,   58,    0,   58,
  114,   93,   95,   55,   96,    0,   94,    0,    0,    0,
    0,   58,   58,   54,   58,    0,   54,    0,    0,   97,
    0,   98,   78,   79,   54,   54,   93,   95,   68,   96,
    0,   94,    0,   93,   95,   55,   96,    0,   94,    0,
  101,  102,    0,    0,   97,   58,   98,    0,    0,    0,
    0,   97,  111,   98,    0,    0,    0,   83,   22,   85,
    0,   23,   24,    0,   25,   26,   27,    0,    0,    0,
    0,    0,    0,   28,    0,    0,    0,   58,    0,    0,
    0,  136,    0,    0,    0,    0,    0,    0,  115,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,
   68,   68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  148,    0,    0,    0,    0,  152,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   55,    0,    0,   55,    0,    0,    0,    0,
    0,    0,    0,   55,   55,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   58,    0,    0,   58,    0,    0,
    0,   58,   58,   58,   58,   58,   58,    0,   87,   88,
   89,   90,   91,   92,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   87,   88,   89,   90,   91,   92,    0,
   87,   88,   89,   90,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   41,   59,   38,   33,   40,   35,   59,   33,
   38,   35,   40,   61,   38,   35,   40,   82,   38,  123,
   59,   59,  275,   18,   40,  276,   59,    6,    7,   32,
   20,   40,   99,  100,   59,   32,   40,  275,   41,   42,
   43,   44,   45,   91,   47,   42,   43,   59,   45,   61,
   47,   32,   61,   61,   93,   50,   59,   60,   40,   62,
   41,   42,   43,   60,   45,   62,   47,   40,  125,  125,
   32,   59,   59,  138,  125,   91,   93,  109,   59,   41,
   42,   43,   91,   45,   32,   47,  125,  125,  153,   60,
   93,   62,  125,   41,   42,  275,   41,   59,   32,   47,
  125,   43,  134,   45,  257,  258,  259,   41,   42,  104,
  275,   59,   93,   47,   32,  275,  106,  275,   60,  151,
   62,   91,  125,   41,  156,   59,   32,   32,  276,  277,
  278,   93,   42,   43,   59,   45,   41,   47,   41,   61,
   32,   59,   44,   41,  125,   93,  141,   93,  261,   41,
   60,   44,   62,   32,   59,   93,   41,   61,   58,   93,
  150,  275,   41,  125,   59,  265,   44,   59,  262,   44,
   32,   41,    0,    0,    0,   93,   41,  125,  125,   41,
   59,   41,   41,   41,   41,   59,   41,  141,   93,   11,
  150,  125,   72,   -1,  153,   -1,   -1,   59,   -1,   -1,
   -1,   93,   -1,   32,   -1,   -1,  262,  125,   -1,   -1,
   -1,  262,   41,   -1,   93,   -1,   -1,   -1,   -1,   -1,
  125,   -1,   -1,  262,  262,   -1,  265,   -1,   -1,   -1,
   59,   93,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
  275,  275,  276,  277,  278,  279,  125,  275,  276,  277,
  278,  275,  276,  277,  278,  275,  276,  277,  278,  262,
   -1,   -1,  265,  125,   93,   -1,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,   -1,   -1,
   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,  269,  270,
  271,  272,  273,  274,   -1,   -1,  125,   -1,   -1,   -1,
  262,   -1,   -1,  265,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  274,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,   -1,  262,   -1,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  123,   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,  262,   -1,   -1,
  265,   -1,   32,   -1,  269,  270,  271,  272,  273,  274,
  262,   41,   -1,  265,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  274,  262,   -1,   -1,  265,   -1,   -1,   59,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,   -1,
  262,   -1,   -1,  265,   -1,   -1,   -1,  269,  270,  271,
  272,  273,  274,   41,   42,   43,   -1,   45,   -1,   47,
   41,   42,   43,   93,   45,   -1,   47,   -1,   -1,   -1,
   -1,   59,   60,  262,   62,   -1,  265,   -1,   -1,   60,
   -1,   62,   51,   52,  273,  274,   42,   43,   27,   45,
   -1,   47,   -1,   42,   43,  125,   45,   -1,   47,   -1,
   69,   70,   -1,   -1,   60,   93,   62,   -1,   -1,   -1,
   -1,   60,   81,   62,   -1,   -1,   -1,   56,  260,   58,
   -1,  263,  264,   -1,  266,  267,  268,   -1,   -1,   -1,
   -1,   -1,   -1,  275,   -1,   -1,   -1,  125,   -1,   -1,
   -1,  110,   -1,   -1,   -1,   -1,   -1,   -1,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  140,   -1,   -1,   -1,   -1,  145,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  274,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,   -1,  269,  270,
  271,  272,  273,  274,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
  269,  270,  271,  272,
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
"def_parameters : scalar_type TK_IDENTIFIER ',' tail_def_parameters",
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
