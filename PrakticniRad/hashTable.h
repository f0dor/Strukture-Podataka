#ifndef HASH_TABLE_
#define HASH_TABLE_
#define SIZE 17
#include "trie.h"

struct _HashTable;
typedef struct _HashTable* HashTablePosition;

#include "linkedList.h"

typedef struct _HashTable {
	ListNodePosition array[SIZE];
} HashTable;

int hashFunction(wchar_t letter);
HashTablePosition HashTableCreate(void);
int HashTableDestroy(HashTablePosition table);


#endif // !HASH_TABLE_

