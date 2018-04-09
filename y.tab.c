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
#include <stdlib.h>
#include <stdio.h>
#line 24 "y.tab.c"

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
    0,    0,    1,    1,    2,    2,    4,    4,    5,    5,
    3,    9,   11,   11,   11,   12,   12,   10,   13,   13,
   14,   14,   14,   14,   14,   14,   14,   15,   15,   20,
   21,   21,   21,   17,   18,   23,   23,   23,   23,   19,
   22,   22,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   26,   26,   26,
   26,   26,   25,   27,   27,   27,   28,   28,   16,   16,
   16,   16,   29,   30,   31,   32,    6,    6,    6,    7,
    7,    7,    8,    8,
};
static const YYINT yylen[] = {                            2,
    2,    0,    1,    1,    1,    1,    5,    6,    6,    8,
    2,    5,    2,    4,    0,    2,    4,    3,    1,    3,
    1,    1,    1,    1,    1,    1,    0,    1,    1,    6,
    3,    4,    4,    2,    2,    1,    1,    2,    2,    2,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    1,    2,    2,
    4,    1,    4,    1,    3,    0,    1,    3,    1,    1,
    1,    1,    6,    8,    5,    9,    1,    1,    1,    1,
    1,    1,    1,    2,
};
static const YYINT yydefred[] = {                         2,
    0,   77,   78,   79,    1,    3,    4,    5,    6,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,    0,   19,   22,
   23,   24,   25,   26,   28,   29,   69,   70,   71,   72,
    0,    0,    0,   81,   82,   80,    0,    0,    0,    0,
    0,   34,    0,    0,    0,    0,    0,   62,   40,    0,
   42,   43,    0,   36,    0,    0,    0,    0,   18,    0,
    0,   12,    0,    7,    0,    0,    0,    0,    0,    0,
    0,   60,    0,   59,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,    0,    0,
    0,   31,   20,    0,    9,    0,    8,    0,    0,    0,
    0,    0,    0,    0,   57,   50,   51,   52,   53,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   32,
    0,   33,    0,    0,   83,    0,    0,   75,    0,   63,
    0,   61,    0,   16,    0,   10,   84,    0,    0,    0,
   30,    0,    0,    0,   17,   74,    0,   76,
};
static const YYINT yydgoto[] = {                          1,
    5,    6,    7,    8,    9,   10,   58,  136,   11,   27,
   42,  134,   28,   29,   30,   31,   32,   33,   34,   35,
   36,   59,   65,   60,   61,   62,  112,  113,   37,   38,
   39,   40,
};
static const YYINT yysindex[] = {                         0,
 -133,    0,    0,    0,    0,    0,    0,    0,    0,  -22,
 -103,    2, -253,  244,    0, -133, -242, -128,  -25,    3,
   15,   22, -201,   18,   78,  -43,    0,  -44,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -199,   39,   -2,    0,    0,    0,   38, -128,   18,   18,
 -177,    0,    4,   44, -175,   44, -168,    0,    0,  334,
    0,    0,   21,    0,  170,  334,   18,  107,    0,  244,
   65,    0,  -13,    0,   55,   76,   81,   66,  -19,   18,
  334,    0,  397,    0,   44,   44,   44,   44,   44,   44,
   44,   44,   44,   44,   44,   44,    0,  334,   35,  178,
  187,    0,    0, -133,    0, -128,    0, -129,  244,   18,
    0,   92,  100,   53,    0,    0,    0,    0,    0, -231,
 -231,  345,  345,  328,  328,  253,  253,   91,    4,    0,
    4,    0, -122,  116,    0,   51,  244,    0, -104,    0,
  -19,    0,   18,    0, -133,    0,    0,  -99,   18,    0,
    0, -101,  244,  131,    0,    0,  244,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -38,    0,  136,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  428,    0,    0,    0,    0,    0,    0,  266,
    0,    0,  -33,    0,  -55,  135,    0,    0,    0,  -38,
  137,    0,    0,    0,    0,    0,    0,    0,  138,    0,
  311,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -53,    0,
   13,    0,    0,    0,    0,    0,    0,    0,    0,  -10,
   26,  238,  273,  124,  155,   61,   96,    0,  434,    0,
  434,    0,    0,  140,    0,    0,  -53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -35,    0,   34,
    0,    0,  -53,    0,    0,    0,  -53,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,  -15,   -1,    0,    0,  165,
    0,    0,    0,  349,    0,    0,    0,    0,    0,    0,
    0,  511,    0,  588,    0,  -76,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 708
static const YYINT yytable[] = {                         58,
   41,   58,  111,   35,   58,   27,   58,   58,   58,   58,
   58,   58,   13,   58,   70,   57,   47,   68,   55,   14,
   27,   19,   54,   73,   54,   58,   58,   54,   58,   54,
   54,   54,   54,   43,   54,   48,   54,   85,   86,   87,
   88,   16,   49,   79,  106,  105,   75,   67,   54,   54,
   54,   54,   57,   64,   50,   55,   67,   56,   55,   58,
   55,   51,   18,   55,  150,   55,   55,   55,   55,   35,
   55,   27,   55,   52,   65,   71,   54,   68,   57,   72,
   69,   55,   54,   56,   55,   55,   27,   55,  133,   73,
   73,   58,   17,   48,   80,   48,   74,   78,   48,   82,
   48,   48,   48,   48,  135,   48,   84,   48,  104,  146,
   54,   80,   57,  107,   54,   55,  108,   56,   55,   48,
   48,  109,   48,    2,    3,    4,  110,  128,   49,  152,
   49,  137,  140,   49,  147,   49,   49,   49,   49,   54,
   49,  101,   49,  141,  100,  142,   56,   44,   45,   46,
   55,  143,  144,   48,   49,   49,   46,   49,   46,  145,
  149,   46,  153,   46,   46,   46,   46,   37,   46,   37,
   46,  157,   37,  155,   37,   15,   15,   13,   66,   39,
   14,   39,   46,    0,   39,   48,   39,   47,   49,   47,
    0,    0,   47,   37,   47,   47,   47,   47,    0,   47,
    0,   47,   54,    0,   57,   39,   35,   55,   27,   56,
   54,    0,   57,   47,    0,   55,   46,   56,    0,   54,
   49,   57,    0,    0,   55,    0,   56,    0,   58,    0,
    0,   58,    0,    0,    0,   58,   58,   58,   58,   58,
   58,   58,   58,   58,   58,   58,    0,   47,   46,    0,
    0,   54,   12,    0,   54,   63,   44,   45,   46,   37,
    0,    0,   54,   54,   54,   54,   54,   54,   54,    0,
   45,   39,   45,    0,    0,   45,    0,   45,   45,   47,
   45,    0,   45,    0,    0,    0,    0,   55,    0,    0,
   55,    0,   53,   44,   45,   46,   45,    0,   55,   55,
   55,   55,   55,   55,   55,   44,   41,   44,    0,    0,
   44,    0,   44,   44,    0,   44,    0,   44,   63,   44,
   45,   46,   48,    0,   41,   48,   44,   45,   46,    0,
   45,   44,    0,    0,    0,   48,   48,   48,   48,   48,
    0,    0,    0,   56,    0,   56,    0,    0,   56,    0,
   56,   56,   63,   44,   45,   46,   64,   49,   41,    0,
   49,    0,   45,    0,    0,   44,   14,    0,    0,   56,
   49,   49,   49,   49,   49,   93,   92,    0,   91,    0,
   94,   53,   44,   45,   46,   46,   93,   95,   46,   96,
   41,   94,    0,   95,    0,   96,   37,   44,   46,   46,
   46,   46,   46,   56,   95,    0,   96,    0,   39,   37,
   37,   37,   37,   37,    0,    0,   47,    0,  103,   47,
    0,   39,   39,   39,   39,   39,    0,    0,    0,   47,
   47,   47,   47,   47,    0,   56,    0,  115,   93,   92,
    0,   91,    0,   94,   63,   44,   45,   46,   97,    0,
    0,    0,  129,   44,   45,   46,   95,  138,   96,    0,
    0,  131,   44,   45,   46,    0,    0,    0,   58,   58,
   58,    0,   58,    0,   58,   58,   58,    0,   58,    0,
   58,    0,    0,    0,    0,  148,   58,   58,    0,   58,
    0,    0,   58,   58,    0,   58,    0,    0,    0,   45,
    0,  156,   45,   20,    0,  158,   21,   22,    0,   23,
   24,   25,   45,   45,   45,   45,   45,    0,   26,    0,
   58,   85,   86,   87,   88,   89,   90,   41,    0,    0,
   41,    0,    0,    0,   44,    0,    0,   44,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   44,   44,
   44,   44,   58,    0,    0,    0,    0,    0,   58,   76,
   77,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   56,    0,    0,   56,    0,   99,  102,    0,
    0,    0,    0,    0,    0,   56,   56,   56,   56,   56,
  114,    0,    0,    0,    0,    0,   85,   86,   87,   88,
   89,   90,   85,   86,   87,   88,   89,   90,    0,    0,
  130,  132,   66,   85,   86,   87,   88,   89,   90,    0,
  139,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   81,    0,   83,    0,    0,    0,    0,    0,    0,
    0,    0,   98,  151,    0,    0,    0,    0,    0,  154,
    0,    0,    0,    0,    0,   85,   86,   87,   88,   89,
   90,    0,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  126,  127,    0,    0,    0,    0,    0,   58,
    0,    0,   58,    0,    0,   58,   58,   58,   58,   58,
   58,   58,   58,   58,   58,   58,   58,   58,
};
static const YYINT yycheck[] = {                         33,
   16,   35,   79,   59,   38,   59,   40,   41,   42,   43,
   44,   45,   35,   47,   59,   35,   18,   61,   38,  123,
   59,  275,   33,   59,   35,   59,   60,   38,   62,   40,
   41,   42,   43,  276,   45,   61,   47,  269,  270,  271,
  272,   40,   40,   40,   58,   59,   48,   91,   59,   60,
   33,   62,   35,   41,   40,   38,   44,   40,   33,   93,
   35,   40,   61,   38,  141,   40,   41,   42,   43,  125,
   45,  125,   47,  275,   41,  275,   33,   44,   35,   41,
  125,   38,   93,   40,   59,   60,  125,   62,  104,  125,
   93,  125,   91,   33,   91,   35,   59,  275,   38,  275,
   40,   41,   42,   43,  106,   45,  275,   47,   44,   59,
   33,   91,   35,   59,  125,   38,   41,   40,   93,   59,
   60,   41,   62,  257,  258,  259,   61,   93,   33,  145,
   35,  261,   41,   38,  136,   40,   41,   42,   43,   33,
   45,   35,   47,   44,   38,   93,   40,  276,  277,  278,
  125,   61,  275,   93,   59,   60,   33,   62,   35,   44,
  265,   38,  262,   40,   41,   42,   43,   33,   45,   35,
   47,   41,   38,  275,   40,   11,   41,   41,   41,   33,
   41,   35,   59,   -1,   38,  125,   40,   33,   93,   35,
   -1,   -1,   38,   59,   40,   41,   42,   43,   -1,   45,
   -1,   47,   33,   -1,   35,   59,  262,   38,  262,   40,
   33,   -1,   35,   59,   -1,   38,   93,   40,   -1,   33,
  125,   35,   -1,   -1,   38,   -1,   40,   -1,  262,   -1,
   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,   -1,   93,  125,   -1,
   -1,  262,  275,   -1,  265,  275,  276,  277,  278,  125,
   -1,   -1,  273,  274,  275,  276,  277,  278,  279,   -1,
   33,  125,   35,   -1,   -1,   38,   -1,   40,   41,  125,
   43,   -1,   45,   -1,   -1,   -1,   -1,  262,   -1,   -1,
  265,   -1,  275,  276,  277,  278,   59,   -1,  273,  274,
  275,  276,  277,  278,  279,   33,   41,   35,   -1,   -1,
   38,   -1,   40,   41,   -1,   43,   -1,   45,  275,  276,
  277,  278,  262,   -1,   59,  265,  276,  277,  278,   -1,
   93,   59,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,   -1,   -1,   33,   -1,   35,   -1,   -1,   38,   -1,
   40,   41,  275,  276,  277,  278,  279,  262,   93,   -1,
  265,   -1,  125,   -1,   -1,   93,  123,   -1,   -1,   59,
  275,  276,  277,  278,  279,   42,   43,   -1,   45,   -1,
   47,  275,  276,  277,  278,  262,   42,   60,  265,   62,
  125,   47,   -1,   60,   -1,   62,  262,  125,  275,  276,
  277,  278,  279,   93,   60,   -1,   62,   -1,  262,  275,
  276,  277,  278,  279,   -1,   -1,  262,   -1,   70,  265,
   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,  275,
  276,  277,  278,  279,   -1,  125,   -1,   41,   42,   43,
   -1,   45,   -1,   47,  275,  276,  277,  278,  279,   -1,
   -1,   -1,  275,  276,  277,  278,   60,  109,   62,   -1,
   -1,  275,  276,  277,  278,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,  137,   59,   60,   -1,   62,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,  262,
   -1,  153,  265,  260,   -1,  157,  263,  264,   -1,  266,
  267,  268,  275,  276,  277,  278,  279,   -1,  275,   -1,
   93,  269,  270,  271,  272,  273,  274,  262,   -1,   -1,
  265,   -1,   -1,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,  277,
  278,  279,  125,   -1,   -1,   -1,   -1,   -1,  125,   49,
   50,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,   -1,   -1,  265,   -1,   67,   68,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   80,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,   -1,   -1,
  100,  101,   25,  269,  270,  271,  272,  273,  274,   -1,
  110,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   54,   -1,   56,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   65,  143,   -1,   -1,   -1,   -1,   -1,  149,
   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,
  274,   -1,   85,   86,   87,   88,   89,   90,   91,   92,
   93,   94,   95,   96,   -1,   -1,   -1,   -1,   -1,  262,
   -1,   -1,  265,   -1,   -1,  262,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 315
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_FLOAT",
"KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_TO","KW_READ","KW_RETURN",
"KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program instruction",
"program :",
"instruction : global_def",
"instruction : function_def",
"global_def : global_var_def",
"global_def : vector_def",
"global_var_def : scalar_type TK_IDENTIFIER '=' init_value ';'",
"global_var_def : scalar_type '#' TK_IDENTIFIER '=' init_value ';'",
"vector_def : scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"vector_def : scalar_type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' init_values_list ';'",
"function_def : header block",
"header : scalar_type TK_IDENTIFIER '(' def_parameters ')'",
"def_parameters : scalar_type TK_IDENTIFIER",
"def_parameters : scalar_type TK_IDENTIFIER ',' tail_def_parameters",
"def_parameters :",
"tail_def_parameters : scalar_type TK_IDENTIFIER",
"tail_def_parameters : tail_def_parameters ',' scalar_type TK_IDENTIFIER",
"block : '{' commands_list '}'",
"commands_list : simple_command",
"commands_list : commands_list ';' simple_command",
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
"var_assignment : TK_IDENTIFIER '=' '&' expression",
"var_assignment : TK_IDENTIFIER '=' '#' expression",
"read_c : KW_READ TK_IDENTIFIER",
"print_c : KW_PRINT print_list",
"print_list : LIT_STRING",
"print_list : arithmetic_or_boolean_expression",
"print_list : print_list LIT_STRING",
"print_list : print_list arithmetic_or_boolean_expression",
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
"parameters_list : tail_parameters_list ',' id",
"parameters_list :",
"tail_parameters_list : id",
"tail_parameters_list : tail_parameters_list ',' id",
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
"init_values_list : init_values_list init_value",

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
#line 293 "parser.y"
int yyerror (char const *s) {
    fflush(stderr);
    fprintf(stderr,"ERROR: %s ---> Line: %d\n", s, getLineNumber());
    exit(3);
}
#line 477 "y.tab.c"

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
