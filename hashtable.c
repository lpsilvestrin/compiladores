#include "hashtable.h"

unsigned long hashKey(unsigned char *str) { //generates the hash Key through the string
	unsigned long hash = 5381;
	int c = *str;
	while (c == *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash;
}

void insertHash(hashNode *entry, hashTable *table) {
	int size = table->size;
	hashNode **data = table->data;
	unsigned long key = hashKey((unsigned char *)entry->id) % size;
	// test if key is free
	if (data[key] == NULL) {
		data[key] = entry;
		return;
	}
	// otherwise iterate over the linked list
	hashNode *iterator = data[key];

	while (iterator->next != NULL) {
		if (strcmp(iterator->id, entry->id) == 0) { //if the id is the same
			//nothing to do, just return
			//printf("key %s in use\n", entry->id);
			return;
		}
		iterator = iterator->next;
	}
	if (strcmp(iterator->id, entry->id) == 0) { //test the last one
		//printf("key %s in use\n", entry->id);
		return;
	}
	// insert in the end of the list
	iterator->next = entry;
}

// retreive node from hashtable
// return 1 if node was found, 0 otherwise
int getHash(char* key, hashTable *table, hashNode **entry) {
	int size = table->size;
	unsigned long index = hashKey((unsigned char *)key) % size;
	if (table->data[index] == NULL) {
		return 0;
	}
	hashNode* iterator = table->data[index];
	while (iterator->next != NULL) {
		if (strcmp(iterator->id, key) == 0) {
			//printf("found %s \n", key);
			*entry = iterator;
			return 1;
		}
		iterator = iterator->next;
	}
	if (strcmp(iterator->id, key) == 0) {
		//printf("found %s \n", key);
		*entry = iterator;
		return 1;
	}
	return 0;
}

void initHash(hashTable **table, int size) {
	hashTable *tmp = (hashTable*) malloc(sizeof(hashTable));
	tmp->size = size;
	tmp->data = (hashNode**) malloc(size*sizeof(hashNode*));
	*table = tmp;
}

void initNode(hashNode **node) {
	hashNode *tmp = (hashNode*) malloc(sizeof(hashNode));
	tmp->id = (char*) malloc(_KEYSIZE*sizeof(char));
	tmp->value = (char*) malloc(_VALSIZE*sizeof(char));
	tmp->next = NULL;
	*node = tmp;
}
