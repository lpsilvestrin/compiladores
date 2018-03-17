#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _KEYSIZE 256
#define _VALSIZE 256

typedef struct HashNode {
	char* key;
	char* value;
	struct HashNode* next;
} hashNode;

typedef struct HashTable {
	int size;
	struct HashNode** data;
} hashTable;

unsigned long hashKey(unsigned char *str); 

void insertHash(hashNode *entry, hashTable *table);
int getHash(char* key, hashTable *table, hashNode **entry); 
void initHash(hashTable **table, int size);
void initNode(hashNode **node);

#endif //_HASHTABLE_H
