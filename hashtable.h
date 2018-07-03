#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 4
#define SYMBOL_LIT_STRING 5
#define SYMBOL_IDENTIFIER 7
#define SYMBOL_PTR_INT 8
#define SYMBOL_PTR_FLOAT 9
#define SYMBOL_PTR_CHAR 10
#define SYMBOL_LIT_BOOL 11
#define SYMBOL_VEC_INT 12
#define SYMBOL_VEC_FLOAT 13
#define SYMBOL_VEC_CHAR 14
#define SYMBOL_FUN_INT 15
#define SYMBOL_FUN_FLOAT 16
#define SYMBOL_FUN_CHAR 17
#define SYMBOL_LABEL 18
#define SYMBOL_TEMP 19

#define _KEYSIZE 256
#define _VALSIZE 256

typedef struct astree ASTree; //prototype

typedef struct HashNode {
	char* id; //the id string
	int type; //the type 
	int scan_type; // type defined during lexial analysis
	int param_order;
	char* value; //some content
	struct HashNode* next;
	ASTree *list_head; //pointer for list
} hashNode;

typedef struct HashTable {
	int size;
	struct HashNode** data;
} hashTable;

unsigned long hashKey(unsigned char *str);
void initHash(hashTable **table, int size);
void initNode(hashNode **node);
void printHash(hashTable *table);
int getHash(char* key, hashTable *table, hashNode **entry);
hashNode* insertHash(hashNode *entry, hashTable *table);
void print_type(hashNode *entry);
void set_param_list(hashNode *entry, ASTree *pointer);
hashNode* make_label(int next_label, hashTable *table);
hashNode* make_temp(int next_temp, hashTable *table);
void clearHash(hashTable*);
#endif //_HASHTABLE_H
