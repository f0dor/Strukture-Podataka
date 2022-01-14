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

int HashFunction(wchar_t letter);
HashTablePosition HashTable_Create(void);
int HashTable_Destroy(HashTablePosition table);
int HashTable_InsertLetter(HashTablePosition table, wchar_t letter);


#endif // !HASH_TABLE_