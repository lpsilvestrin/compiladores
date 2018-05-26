#include "tac.h"

TAC * create(int type, hashNode result, hashNode op1, hashNode op2, TAC *prev, TAC *next) {
    TAC t = (TAC*)malloc(sizeof(TAC));
    t->type = type;
    t->result = result;
    t->op1 = op1;
    t->op2 = op2;
    t->prev = prev;
    t->next = next;
    return t;
}
