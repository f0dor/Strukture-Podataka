#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#define SIZE 17

int HashFunction(wchar_t letter)
{
	return letter % SIZE;
}

HashTablePosition HashTable_Create(void)
{
	HashTablePosition table = (HashTablePosition)malloc(sizeof(HashTable));
	int i = 0;

	if (!table) {
		return NULL;
	}

	for (i = 0; i < SIZE; i++) {
		*((table->array) + i) = LinkedList_Create();
	}

	return table;
}

int HashTable_Destroy(HashTablePosition table)
{
	int i = 0;

	for (i = 0; i < SIZE; i++) {
		LinkedList_Destroy(*(table->array) + i);
	}

	free(table);

	if (!table) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}

int HashTable_InsertLetter(HashTablePosition table, wchar_t letter)
{
	int index = HashFunction(letter);

	LinkedList_SortedInput(*(table->array + index), letter);

	return EXIT_SUCCESS;
}
