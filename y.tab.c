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
#define int_expression 281
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    4,    4,    5,    5,
    6,    6,    6,    8,    8,    7,    7,    7,    3,    9,
   11,   11,   11,   12,   12,   10,   13,   13,   14,   14,
   14,   14,   14,   14,   15,   15,   17,   18,   21,   21,
   21,   19,   23,   23,   23,   23,   23,   20,   20,   20,
   25,   25,   25,   26,   26,   22,   22,   22,   24,   24,
   24,   28,   28,   28,   28,   28,   28,   27,   27,   27,
   27,   16,   16,   16,   16,   29,   32,   30,   31,
};
static const YYINT yylen[] = {                            2,
    1,    0,    2,    2,    1,    1,    5,    6,    5,    7,
    1,    1,    1,    1,    3,    1,    1,    1,    2,    5,
    2,    1,    0,    4,    2,    3,    1,    3,    1,    1,
    1,    1,    1,    0,    3,    6,    2,    2,    2,    2,
    0,    2,    1,    4,    1,    2,    2,    1,    1,    4,
    1,    1,    0,    3,    1,    1,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    9,    5,    6,    8,
};
static const YYINT yydefred[] = {                         0,
   11,   12,   13,    0,    0,    1,    0,    0,    5,    6,
    0,    0,    0,    3,    4,    0,    0,    0,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   29,   30,   31,   32,   33,   72,   73,   74,
   75,    0,   17,   18,   16,    0,    0,    0,   22,    0,
    0,    0,    0,   37,    0,    0,    0,    0,    0,   45,
   42,   48,    0,   49,    0,    0,   38,    0,    0,    0,
    0,   26,    0,    0,    9,    7,    0,   20,    0,    0,
    0,    0,    0,    0,   46,    0,   47,    0,   60,   62,
   63,   64,   65,   66,   67,   68,   69,   70,   71,    0,
    0,   39,   40,   35,    0,   28,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,   52,   58,   57,   59,
    0,    0,   10,    0,   24,    0,   77,    0,   44,    0,
   50,    0,   15,    0,   78,    0,    0,    0,   54,   36,
    0,    0,   79,    0,   76,
};
static const YYINT yydgoto[] = {                          5,
    6,    7,    8,    9,   10,   11,   60,  108,   12,   19,
   48,   49,   31,   32,   33,   34,   35,   36,   37,   61,
   67,   62,   63,   64,  116,  117,  100,  101,   38,   39,
   40,   41,
};
static const YYINT yysindex[] = {                      -114,
    0,    0,    0,  -78,    0,    0, -114, -114,    0,    0,
  -34, -107, -241,    0,    0,  -23, -235,  -97,    0,  -31,
 -258, -153,  -16,   12,   25,   42, -205,  -33,   -1,  -40,
  -42,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -37,    0,    0,    0,   35, -176,   59,    0, -258,
  -33,  -33, -164,    0,  -28, -163,   15, -161,  -29,    0,
    0,    0,   29,    0,   26,   -1,    0,   -1,   47,  -33,
  -33,    0,  -97, -258,    0,    0,   74,    0,   60,   79,
   83,   64, -155,   19,    0,   87,    0,  -87,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   15,
  -29,    0,    0,    0,   36,    0,   73,   75, -153,    0,
 -129, -107,  -33,   53,   96,  107,    0,    0,    0,    0,
   91, -258,    0, -119,    0, -113,    0, -108,    0,   19,
    0,  -33,    0,   74,    0, -104,  -33,   96,    0,    0,
 -107,  118,    0, -107,    0,
};
static const YYINT yyrindex[] = {                       160,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -48,    0,    0,
    0,  123,    0,    0,    0,    0,    0,    0,  -56,    0,
    0,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   43,    0,    0,    0,    0,    0,
    0,    0,   17,    0,  -12,  -56,    0,  -56,    8,    0,
    0,    0,  -48,    0,    0,    0,  131,    0,    0,    0,
    0,    0,    0,  132,    0,    0,    0,   56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  115,    0,    0,    0,
    0,    0,    0,    0,  134,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -86,    0,    0,    0,    0,
    0,    0,    0,  136,    0,    0,    0,  138,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   71,    0,    0,    0,    0,  -14,   -6,   58,    0,   -3,
    0,   80,  117,   62,    0,    0,    0,    0,    0,  -10,
  -41,   30,    7,  -45,    0,   61,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 321
static const YYINT yytable[] = {                         59,
   17,   56,   41,   59,   58,   56,   57,   47,   58,   18,
   34,   84,   13,   89,   46,   18,   22,   43,   44,   45,
   70,   75,   43,   74,  102,   43,  103,   43,   43,   43,
   43,   43,   43,   56,   20,   69,   58,   21,   57,   23,
   80,   81,   56,   79,   50,   56,   43,   56,   56,   56,
   71,   51,   58,   56,   57,  120,   58,   56,   68,  104,
  105,   42,   83,   69,   52,   88,   56,  107,   41,   54,
   96,   98,   69,   99,   69,   56,   34,   14,   15,   43,
   43,   53,   72,   43,   43,   43,   86,   43,   96,   98,
  115,   99,   73,   76,  124,   68,   61,   68,   77,   78,
   56,   43,  128,    1,    2,    3,   69,   88,  127,   56,
   82,   85,   43,   87,   61,  107,   83,  109,  110,  111,
   97,  140,  135,  112,  113,  114,  142,  118,  121,  119,
  122,  126,   56,  123,   43,   43,  138,  143,   97,  130,
  145,   56,    1,    2,    3,  129,   24,  131,   61,   25,
   26,  132,   27,   28,   29,  134,  137,  141,  144,    2,
    4,   30,   24,   23,   27,   25,   26,   43,   27,   28,
   29,   21,   53,   14,   51,   34,   25,   30,   55,  133,
   61,   90,   91,   92,   93,   94,   95,  136,  125,  106,
  139,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   41,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   16,   55,   43,   44,   45,   65,   43,   44,   45,   43,
    0,    0,   43,    0,    0,    0,   43,   43,   43,   43,
   43,   43,   43,   43,   43,   43,   43,    0,    0,   56,
    0,    0,   56,   65,   43,   44,   45,   66,   56,    0,
    0,   56,   56,   56,   56,   56,   56,    0,    0,   65,
   43,   44,   45,   65,   43,   44,   45,   90,   91,   92,
   93,   94,   95,    0,   43,    0,    0,   43,    0,    0,
    0,   43,   43,   43,   43,   43,   43,   61,    0,    0,
   61,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   59,   33,   38,   35,   40,   22,   38,  123,
   59,   40,   91,   59,   21,  123,   40,  276,  277,  278,
   61,   59,   35,   61,   66,   38,   68,   40,   41,   42,
   43,   44,   45,   35,  276,   29,   38,   61,   40,  275,
   51,   52,   35,   50,   61,   38,   59,   40,   41,   35,
   91,   40,   38,   35,   40,  101,   38,   41,   29,   70,
   71,   93,   91,   57,   40,   59,   59,   74,  125,  275,
   42,   43,   66,   45,   68,   59,  125,    7,    8,   92,
   93,   40,  125,   41,   42,   43,   57,   45,   42,   43,
   84,   45,   59,   59,  109,   66,   41,   68,  275,   41,
   93,   59,  113,  257,  258,  259,  100,  101,  112,   93,
  275,  275,  125,  275,   59,  122,   91,   44,   59,   41,
   92,  132,  126,   41,   61,  281,  137,   41,   93,  100,
   58,  261,  125,   59,   92,   93,  130,  141,   92,   44,
  144,  125,  257,  258,  259,   93,  260,   41,   93,  263,
  264,   61,  266,  267,  268,  275,  265,  262,   41,    0,
  275,  275,  260,   41,  125,  263,  264,  125,  266,  267,
  268,   41,   41,   59,   41,  262,   41,  275,   41,  122,
  125,  269,  270,  271,  272,  273,  274,  126,  109,   73,
  130,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,  275,  276,  277,  278,  275,  276,  277,  278,  262,
   -1,   -1,  265,   -1,   -1,   -1,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,   -1,   -1,  262,
   -1,   -1,  265,  275,  276,  277,  278,  279,  262,   -1,
   -1,  265,  275,  276,  277,  278,  279,   -1,   -1,  275,
  276,  277,  278,  275,  276,  277,  278,  269,  270,  271,
  272,  273,  274,   -1,  262,   -1,   -1,  265,   -1,   -1,
   -1,  269,  270,  271,  272,  273,  274,  262,   -1,   -1,
  265,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 316
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,0,0,0,0,0,0,0,0,
0,0,0,"':'","';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'['","'\\\\'","']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_FLOAT","KW_IF",
"KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_TO","KW_READ","KW_RETURN",
"KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR","int_expression",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : instructions",
"program :",
"instructions : global_struct instructions",
"instructions : function instructions",
"global_struct : global_var",
"global_struct : global_vector",
"global_var : kw_type TK_IDENTIFIER '=' lit_value ';'",
"global_var : kw_type '#' TK_IDENTIFIER '=' lit_value ';'",
"global_vector : TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"global_vector : TK_IDENTIFIER '[' LIT_INTEGER ']' '=' lit_list ';'",
"kw_type : KW_CHAR",
"kw_type : KW_INT",
"kw_type : KW_FLOAT",
"lit_list : lit_value",
"lit_list : lit_value ':' lit_list",
"lit_value : LIT_CHAR",
"lit_value : LIT_INTEGER",
"lit_value : LIT_REAL",
"function : header block",
"header : kw_type TK_IDENTIFIER '(' def_params ')'",
"def_params : kw_type TK_IDENTIFIER",
"def_params : l_param",
"def_params :",
"l_param : kw_type TK_IDENTIFIER ',' l_param",
"l_param : kw_type TK_IDENTIFIER",
"block : '{' l_commands '}'",
"l_commands : command",
"l_commands : command ';' l_commands",
"command : atrib",
"command : flow_c",
"command : read",
"command : print",
"command : return",
"command :",
"atrib : TK_IDENTIFIER '=' expression",
"atrib : TK_IDENTIFIER '[' expression ']' '=' expression",
"read : KW_READ TK_IDENTIFIER",
"print : KW_PRINT l_print",
"l_print : LIT_STRING l_print",
"l_print : arit_expr l_print",
"l_print :",
"return : KW_RETURN expression",
"value : TK_IDENTIFIER",
"value : TK_IDENTIFIER '[' int_expression ']'",
"value : lit_value",
"value : '#' TK_IDENTIFIER",
"value : '&' TK_IDENTIFIER",
"expression : arit_expr",
"expression : bool_expr",
"expression : TK_IDENTIFIER '(' call_params ')'",
"call_params : value",
"call_params : l_value",
"call_params :",
"l_value : value ',' l_value",
"l_value : value",
"arit_expr : value",
"arit_expr : value aritmetic_op arit_expr",
"arit_expr : '(' arit_expr ')'",
"bool_expr : value relational_op bool_expr",
"bool_expr : '!' bool_expr",
"bool_expr : value",
"relational_op : OPERATOR_LE",
"relational_op : OPERATOR_GE",
"relational_op : OPERATOR_EQ",
"relational_op : OPERATOR_NE",
"relational_op : OPERATOR_AND",
"relational_op : OPERATOR_OR",
"aritmetic_op : '*'",
"aritmetic_op : '\\\\'",
"aritmetic_op : '+'",
"aritmetic_op : '-'",
"flow_c : for",
"flow_c : if",
"flow_c : ifthenelse",
"flow_c : while",
"for : KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' block",
"while : KW_WHILE '(' expression ')' block",
"if : KW_IF '(' expression ')' KW_THEN block",
"ifthenelse : KW_IF '(' expression ')' KW_THEN command KW_ELSE block",

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
