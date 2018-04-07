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
    0,    0,   59,    0,    0,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   33,    0,   22,    0,   11,    0,   10,    0,    0,    0,
    0,    0,    0,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,   39,    0,    0,
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
static const YYINT yysindex[] = {                      -224,
    0,    0,    0,    0,    0, -224, -224,    0,    0,  -34,
 -103,    0,    0,   -8, -244, -109,    0, -151, -222, -224,
    7,   32,   52,   66, -179,  -27,  -33,  -17,    0,  -13,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   58,    9, -156,   87, -151,
  -27,  -27, -146,    0,  -22, -144,  -23,  -23, -142,    0,
    0,  173,    0,    0,   45,  105,    0,    4,  -27,  -27,
    0, -109,    0,   17,   94,    0,   80,   99,  100,   81,
  -27,  -19,    0,  163,  173,    0,  -23,  -23,  -23,  -23,
  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -33,  -33,
    0,   53,    0, -151,    0, -224,    0, -111, -109,  -27,
   60,  112,  119,    0,  132,  132,  132,  132,  345,  345,
   62,   62,   43,   43,  173,  173,    0,    0,  102,  107,
  108, -114,    0, -109,    0,  -96,    0,  -19,    0,  -27,
 -151,    0,  126,  -86,  -27,  134,    0,    0,    0, -224,
 -109,  142,  -19,    0,    0, -109,    0,    0,
};
static const YYINT yyrindex[] = {                       184,
    0,    0,    0,    0,    0,  185,  187,    0,    0,    0,
    0,    0,    0,    0,    0,  -32,    0,    0,    0,  147,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   64,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  338,    0,    0,    0,    0,    0,
    0,  -38,    0,    0,   -2,  -55,    0,  -50,    0,    0,
    0,  -32,    0,    0,  152,    0,    0,    0,    0,    0,
    0,  156,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -36,    0,
    0,  158,    0,    0,   89,  103,  139,  154,  264,  274,
   56,   75,   20,   39,  337,  361,    0,    0,    0,  144,
    0,    0,    0,  -36,    0,    0,    0,    0,    0,    0,
    0,    0,  160,  -31,    0,  168,    0,    0,    0,    0,
  -36,    0,    0,    0,    0,  -36,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   19,    0,    0,    0,    0,    2,    6,   70,    0,  206,
    0,   69,  149,  -61,    0,    0,    0,    0,    0,    0,
    0,  121,  -62,  402,    0,  -53,    0,   76,    0,    0,
    0,    0,
};
#define YYTABLESIZE 626
static const YYINT yytable[] = {                         58,
   15,   56,   41,   36,   59,   58,   57,   56,   37,   58,
   59,   56,   57,   16,   59,   56,   57,   82,   59,   16,
   41,   48,   29,   46,   12,   13,   29,   73,  112,   58,
   21,   20,    1,    2,    3,  100,  127,  128,   58,   58,
   58,   58,   58,   69,   58,   95,   93,  135,   94,   56,
   96,   46,   18,   47,   41,   77,   58,   58,   56,   58,
   46,   46,   46,   97,   46,   98,   46,   50,   81,   36,
   47,   51,  144,   70,   37,  105,   56,  104,   46,   47,
   47,   47,   19,   47,  146,   47,   41,   44,   29,  155,
   58,   52,   29,   73,  158,   54,   44,   47,   44,  146,
   44,   74,   97,   95,   98,   53,   45,  132,   96,  130,
   56,   71,   46,   72,   44,   45,   73,   45,   75,   45,
   50,   97,   58,   98,   43,   44,   45,   76,   80,   50,
   83,   47,   86,   45,   51,   81,   99,  106,  107,  108,
  109,  110,   56,   51,   46,  129,  130,   50,   44,  134,
   22,  132,  137,   23,   24,  138,   25,   26,   27,  139,
  143,   51,  140,   47,  141,   28,  142,   45,  145,  150,
   52,   78,   79,   95,   93,  151,   94,  153,   96,   52,
   44,   50,  156,    2,    3,   53,    4,   17,   21,  101,
  102,   97,   15,   98,   53,   51,   66,   52,   64,   45,
   18,  111,   83,  114,   95,   93,   36,   94,   67,   96,
  149,   37,   53,   50,   95,   93,   17,   94,  154,   96,
  103,    0,   97,   41,   98,   29,   41,   51,  157,    0,
  136,   52,   97,    0,   98,    0,    0,    0,    0,    0,
   14,   65,   43,   44,   45,   66,   53,   55,   43,   44,
   45,   65,   43,   44,   45,   65,   43,   44,   45,   58,
  148,    0,   58,   52,    0,  152,   58,   58,   58,   58,
   58,   58,   87,   88,   89,   90,   91,   92,   53,   56,
    0,   46,   56,    0,   46,    0,    0,    0,   46,   46,
   46,   46,   46,   46,    0,   54,    0,    0,    0,    0,
   47,    0,    0,   47,   54,   55,    0,   47,   47,   47,
   47,   47,   47,    0,   55,    0,    0,   44,    0,    0,
   44,    0,   54,    0,   44,   44,   44,   44,   44,   44,
    0,    0,   55,    0,    0,    0,   45,    0,    0,   45,
    0,    0,    0,   45,   45,   45,   45,   45,   45,    0,
   50,    0,    0,   50,    0,    0,   54,   50,   50,   50,
   50,   50,   50,    0,   51,    0,   55,   51,   48,    0,
    0,   51,   51,   51,   51,   51,   51,   48,   58,   58,
   58,    0,   58,    0,   58,    0,   95,   93,   54,   94,
    0,   96,   49,    0,    0,   48,   58,   58,   55,   58,
   52,   49,    0,   52,   97,    0,   98,   52,   52,   52,
   52,   52,   52,    0,    0,   53,    0,    0,   53,   49,
    0,    0,   53,   53,   53,   53,   53,   53,   68,   48,
   58,   87,   88,   89,   90,   91,   92,    0,    0,    0,
    0,   87,   88,   89,   90,   91,   92,    0,    0,    0,
    0,    0,    0,   49,    0,    0,    0,    0,   84,   85,
    0,   48,   58,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   49,    0,    0,  115,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,
   68,   68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   54,    0,    0,   54,    0,
    0,    0,    0,    0,    0,   55,   54,   54,   55,    0,
    0,    0,    0,    0,    0,    0,   55,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   58,
    0,   48,   58,    0,    0,    0,   58,   58,   58,   58,
   58,   58,    0,   87,   88,   89,   90,    0,    0,    0,
    0,    0,   49,    0,    0,   49,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   41,   59,   38,   33,   40,   35,   59,   33,
   38,   35,   40,  123,   38,   35,   40,   40,   38,  123,
   59,   20,   59,   18,    6,    7,   59,   59,   82,   32,
  275,   40,  257,  258,  259,   32,   99,  100,   41,   42,
   43,   44,   45,   61,   47,   42,   43,  109,   45,   32,
   47,   32,   61,  276,   93,   50,   59,   60,   41,   62,
   41,   42,   43,   60,   45,   62,   47,   61,   91,  125,
   32,   40,  134,   91,  125,   59,   59,   61,   59,   41,
   42,   43,   91,   45,  138,   47,  125,   32,  125,  151,
   93,   40,  125,  125,  156,  275,   41,   59,   43,  153,
   45,   93,   60,   42,   62,   40,   32,  106,   47,  104,
   93,  125,   93,   59,   59,   41,   59,   43,  275,   45,
   32,   60,  125,   62,  276,  277,  278,   41,  275,   41,
  275,   93,  275,   59,   32,   91,   32,   44,   59,   41,
   41,   61,  125,   41,  125,   93,  141,   59,   93,  261,
  260,  150,   93,  263,  264,   44,  266,  267,  268,   41,
  275,   59,   61,  125,   58,  275,   59,   93,  265,   44,
   32,   51,   52,   42,   43,  262,   45,   44,   47,   41,
  125,   93,   41,    0,    0,   32,    0,   41,  125,   69,
   70,   60,   41,   62,   41,   93,   41,   59,   41,  125,
   41,   81,   59,   41,   42,   43,  262,   45,   41,   47,
  141,  262,   59,  125,   42,   43,   11,   45,  150,   47,
   72,   -1,   60,  262,   62,  262,  265,  125,  153,   -1,
  110,   93,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
  275,  275,  276,  277,  278,  279,   93,  275,  276,  277,
  278,  275,  276,  277,  278,  275,  276,  277,  278,  262,
  140,   -1,  265,  125,   -1,  145,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,  125,  262,
   -1,  262,  265,   -1,  265,   -1,   -1,   -1,  269,  270,
  271,  272,  273,  274,   -1,   32,   -1,   -1,   -1,   -1,
  262,   -1,   -1,  265,   41,   32,   -1,  269,  270,  271,
  272,  273,  274,   -1,   41,   -1,   -1,  262,   -1,   -1,
  265,   -1,   59,   -1,  269,  270,  271,  272,  273,  274,
   -1,   -1,   59,   -1,   -1,   -1,  262,   -1,   -1,  265,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,   -1,
  262,   -1,   -1,  265,   -1,   -1,   93,  269,  270,  271,
  272,  273,  274,   -1,  262,   -1,   93,  265,   32,   -1,
   -1,  269,  270,  271,  272,  273,  274,   41,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   42,   43,  125,   45,
   -1,   47,   32,   -1,   -1,   59,   59,   60,  125,   62,
  262,   41,   -1,  265,   60,   -1,   62,  269,  270,  271,
  272,  273,  274,   -1,   -1,  262,   -1,   -1,  265,   59,
   -1,   -1,  269,  270,  271,  272,  273,  274,   27,   93,
   93,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   57,   58,
   -1,  125,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,  265,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  273,  274,  265,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  273,  274,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  262,
   -1,  265,  265,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,   -1,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,  262,   -1,   -1,  265,
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
