#ifndef _TAC_H
#define _TAC_H

#include "hashtable.h"

#define TAC_FUN_BEGIN 1
#define TAC_FUN_END 2
#define TAC_FUN_ARG 3
#define TAC_FUN_CALL 4
#define TAC_VAR_ASSIGN 5
#define TAC_VEC_ASSIGN 6
#define TAC_POINTER_ASSIGN 7
#define TAC_PRINT 8
#define TAC_READ 9
#define TAC_ADD 10
#define TAC_SUB 11
#define TAC_MUL 12
#define TAC_DIV 13
#define TAC_NEG 14
#define TAC_AND 15
#define TAC_OR 16
#define TAC_NOT 17
#define TAC_EQ 18
#define TAC_NEQ 19
#define TAC_LEQ 20
#define TAC_GEQ 21
#define TAC_JUMP 22
#define TAC_RETURN 23
#define TAC_SYMBOL 24

typedef struct Tac {
	int type;
	hashNode *result;
	hashNode *op1;
	hashNode *op2;
	struct Tac *prev;
	struct Tac *next;
} TAC;


#endif