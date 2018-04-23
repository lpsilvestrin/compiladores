#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_REAL 2
#define SYMBOL_LIT_BOOL 3
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5
#define SYMBOL_IDENTIFIER 7

#define _KEYSIZE 256
#define _VALSIZE 256

typedef struct HashNode {
	char* id; //the id string
	int type; //the type 
	char* value; //some content
	struct HashNode* next;
} hashNode;

typedef struct HashTable {
	int size;
	struct HashNode** data;
} hashTable;

int getHash(char* key, hashTable *table, hashNode **entry);
unsigned long hashKey(unsigned char *str);
void initHash(hashTable **table, int size);
void initNode(hashNode **node);
hashNode* insertHash(hashNode *entry, hashTable *table);
void printHash(hashTable *table);

#endif //_HASHTABLE_H
