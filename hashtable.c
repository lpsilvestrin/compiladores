#include "hashtable.h"

unsigned long hashKey(unsigned char *str) { //generates the hash Key through the string
	unsigned long hash = 5381;
	int c = *str;
	while (c == *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash;
}

hashNode* insertHash(hashNode *entry, hashTable *table) {
	int size = table->size;
	hashNode **data = table->data;
	unsigned long key = hashKey((unsigned char *)entry->id) % size;
	// test if key is free
	if (data[key] == NULL) {
		data[key] = entry;
		return entry;
	}
	// otherwise iterate over the linked list
	hashNode *iterator = data[key];

	while (iterator->next != NULL) {
		if (strcmp(iterator->id, entry->id) == 0) { //if the id is the same
			//nothing to do, just return
			//printf("key %s in use\n", entry->id);
			return iterator;
		}
		iterator = iterator->next;
	}
	if (strcmp(iterator->id, entry->id) == 0) { //test the last one
		//printf("key %s in use\n", entry->id);
		return iterator;
	}
	// insert in the end of the list
	iterator->next = entry;
	return entry;
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

void printHash(hashTable *table) {
	hashNode* currNode = NULL;
	int size = table->size;
	for (int i = 0; i < size; i++) {
		currNode = table->data[i];
		while (currNode != NULL) {
			fprintf(stderr, "[HASH] entry %d = %s, type ", i, currNode->id);
			int type = currNode->type;
			switch(type) {
				case SYMBOL_LIT_INT: 
					fprintf(stderr, "int\n");
				break;
				case SYMBOL_LIT_FLOAT: 
					fprintf(stderr, "float\n");
				break;
				case SYMBOL_LIT_CHAR: 
					fprintf(stderr, "char\n");
				break;
				case SYMBOL_LIT_STRING: 
					fprintf(stderr, "string\n");
				break;
				case SYMBOL_IDENTIFIER: 
					fprintf(stderr, "NOT ASSIGNED\n");
				break;
				case SYMBOL_PTR_INT: 
					fprintf(stderr, "int pointer\n");
				break;
				case SYMBOL_PTR_FLOAT: 
					fprintf(stderr, "float pointer\n");
				break;
				case SYMBOL_PTR_CHAR: 
					fprintf(stderr, "char pointer\n");
				break;
				case SYMBOL_VEC_INT: 
					fprintf(stderr, "int vector\n");
				break;
				case SYMBOL_VEC_FLOAT: 
					fprintf(stderr, "float vector\n");
				break;
				case SYMBOL_VEC_CHAR: 
					fprintf(stderr, "char vector\n");
				break;
				case SYMBOL_FUN_INT: 
					fprintf(stderr, "int function\n");
				break;
				case SYMBOL_FUN_FLOAT: 
					fprintf(stderr, "float function\n");
				break;
				case SYMBOL_FUN_CHAR: 
					fprintf(stderr, "char function\n");
				break;
				case SYMBOL_LABEL:
					fprintf(stderr, "label\n");
					break;
				case SYMBOL_TEMP:
					fprintf(stderr, "temp\n");
					break;
				default: 
					fprintf(stderr, "UNKNOWN %d\n", type);
			}

			currNode = currNode->next;
		}
	}
}

void print_type(hashNode *entry) {
	int type = entry->type;
	switch(type){
		case SYMBOL_LIT_INT:
			fprintf(stderr, "[HASH] SYMBOL_LIT_INT\n");
			break;
		case SYMBOL_LIT_FLOAT:
			fprintf(stderr, "[HASH] SYMBOL_LIT_FLOAT\n");
			break;
		case SYMBOL_LIT_CHAR:
			fprintf(stderr, "[HASH] SYMBOL_LIT_CHAR\n");
			break;
		case SYMBOL_LIT_STRING:
			fprintf(stderr, "[HASH] SYMBOL_LIT_STRING\n");
			break;
		case SYMBOL_IDENTIFIER:
			fprintf(stderr, "[HASH] SYMBOL_IDENTIFIER\n");
			break;
		case SYMBOL_PTR_INT:
			fprintf(stderr, "[HASH] SYMBOL_PTR_INT\n");
			break;
		case SYMBOL_PTR_FLOAT:
			fprintf(stderr, "[HASH] SYMBOL_PTR_FLOAT\n");
			break;
		case SYMBOL_PTR_CHAR:
			fprintf(stderr, "[HASH] SYMBOL_PTR_CHAR\n");
			break;
		case SYMBOL_VEC_INT:
			fprintf(stderr, "[HASH] SYMBOL_VEC_INT\n");
			break;
		case SYMBOL_VEC_FLOAT:
			fprintf(stderr, "[HASH] SYMBOL_VEC_FLOAT\n");
			break;
		case SYMBOL_VEC_CHAR:
			fprintf(stderr, "[HASH] SYMBOL_VEC_CHAR\n");
			break;
		case SYMBOL_FUN_INT:
			fprintf(stderr, "[HASH] SYMBOL_FUN_INT\n");
			break;
		case SYMBOL_FUN_FLOAT:
			fprintf(stderr, "[HASH] SYMBOL_FUN_FLOAT\n");
			break;
		case SYMBOL_FUN_CHAR:
			fprintf(stderr, "[HASH] SYMBOL_FUN_CHAR\n");
			break;
		case SYMBOL_LABEL:
			fprintf(stderr, "[HASH] SYMBOL_LABEL\n");
			break;
		case SYMBOL_TEMP:
			fprintf(stderr, "[HASH] SYMBOL_TEMP\n");
			break;
		default:
			fprintf(stderr, "[HASH] ERROR!!\n");
	}
}

void set_param_list(hashNode *entry, ASTree *pointer) {
	entry->list_head = pointer;
}

hashNode* make_label(int next_label, hashTable *table) {
	char buffer[_KEYSIZE];
	sprintf(buffer, "_label%d", next_label);
	hashNode *n;
	initNode(&n); 		// inicializando área de memória e atribuindo pro ponteiro
	strcpy(n->id, buffer); // atribuindo identificador como key
	n->type = SYMBOL_LABEL;
	hashNode* res = insertHash(n, table); // inserindo na tabela
	if (res != n) {
		fprintf(stderr, "[HASH] ERRO: label já utilizado");
		free(n);
	}
	return res;
}

hashNode* make_temp(int next_temp, hashTable *table) {
	char buffer[_KEYSIZE];
	sprintf(buffer, "_temp%d", next_temp);
	hashNode *n;
	initNode(&n); 		// inicializando área de memória e atribuindo pro ponteiro
	strcpy(n->id, buffer); // atribuindo identificador como key
	n->type = SYMBOL_TEMP;
	hashNode* res = insertHash(n, table); // inserindo na tabela
	if (res != n) {
		fprintf(stderr, "[HASH] ERRO: temp já utilizado");
		free(n);
	}
	return res;
}

void create_lit_ids(hashTable *table) {
	int id_number = 0;
	char id[200];
	hashNode* currNode = NULL;
	int size = table->size;
	for (int i = 0; i < size; i++) {
		for (currNode=table->data[i]; currNode != NULL; currNode = currNode->next) {
			switch(currNode->type) {
				case SYMBOL_LIT_INT: 
				case SYMBOL_LIT_FLOAT:
				case SYMBOL_LIT_CHAR:
				case SYMBOL_LIT_STRING:
				case SYMBOL_LIT_BOOL:
					strcpy(currNode->value,currNode->id);
					sprintf(id, "_%d", id_number);
					strcpy(currNode->id, id);
					id_number++;
					break;
				default: break;
			}
		}
	}
}

// clear table with mem leak
void clearHash(hashTable *table) {
	int size = table->size;
	for (int i = 0; i < size; i++) {
		table->data[i] = NULL;
	}
}
