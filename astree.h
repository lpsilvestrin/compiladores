#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher



#define AST_INITIAL 258
#define AST_GLOBAL_VAR_DEF 259
#define AST_GLOBAL_POINTER_DEF 260
#define AST_GLOBAL_VECTOR_DEF 261
#define AST_FUNCTION_DEF 262
#define AST_HEADER 263
#define AST_DEF_PARAM 264
#define AST_DEF_PARAM_T 265
#define AST_BLOCK 266
#define AST_COMMANDS_L 267
#define AST_VAR_AS 268
#define AST_VECTOR_AS 269
#define AST_READ 270
#define AST_PRINT 271
#define AST_RETURN 272
#define AST_NOT_EXP 273
#define AST_NEG_EXP 274
#define AST_PAR_EXP 275
#define AST_PLUS_EXP 276
#define AST_MINUS_EXP 277
#define AST_MUL_EXP 278
#define AST_DIV_EXP 279
#define AST_LESS_EXP 280
#define AST_GREAT_EXP 281
#define AST_LE_EXP 282
#define AST_GE_EXP 283
#define AST_EQ_EXP 284
#define AST_NE_EXP 285
#define AST_AND_EXP 286
#define AST_OR_EXP 287
#define AST_ID 288
#define AST_ID_POINTER 289
#define AST_ID_ADDRESS 290
#define AST_VECTOR_DEF 291
#define AST_VECTOR 304
#define AST_FUNCTION 292
#define AST_PARAM 293
#define AST_IF 294
#define AST_FOR 295
#define AST_WHILE 296
#define AST_INIT_VALUES 297
#define AST_INT_SYMBOL 298
#define AST_FLOAT_SYMBOL 299
#define AST_CHAR_SYMBOL 300
#define AST_INT 301
#define AST_REAL 302
#define AST_CHAR 303

#include "hashtable.h"

typedef struct astree {
    int type; 
    hashNode *id; //pointer for the info inside our hash
    struct astree *offspring[MAX_OFFSPRING];
} ASTree;

ASTree* astree_create(int type, hashNode *id, ASTree *offspring_0, ASTree *offspring_1, ASTree *offspring_2, ASTree *offspring_3);
void print_astnode(ASTree* node, int level);
int decompile_tree(ASTree* tree, FILE *prog);

#endif
