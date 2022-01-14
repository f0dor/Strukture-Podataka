#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#define SIZE 17

int hashFunction(wchar_t letter)
{
	return letter % SIZE;
}

HashTablePosition HashTableCreate(void)
{
	HashTablePosition table = (HashTablePosition)malloc(sizeof(HashTable));
	int i = 0;

	if (!table) {
		return NULL;
	}

	for (i = 0; i < SIZE; i++) {
		*((table->array) + i) = LinkedListCreate();
	}

	return table;
}

int HashTableDestroy(HashTablePosition table)
{
	int i = 0;

	for (i = 0; i < SIZE; i++) {
		LinkedListDestroy(*(table->array) + i);
	}

	free(table);

	if (!table) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
