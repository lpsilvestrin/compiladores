
typedef struct HashNode {
	char* key;
	char* value;
	struct HashNode* next;
} HashNode;

typedef struct HashTable {
	int size;
	HashNode** data;
} HashTable;

unsigned long hashKey(unsigned char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}
