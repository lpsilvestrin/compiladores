#ifndef _TAC_H
#define _TAC_H

#include "hashtable.h"

typedef struct Tac {
	int type;
	hashNode *c0;
	hashNode *c1;
	hashNode *c2;
	struct Tac *prev;
	struct Tac *next;
} tac;


#endif
