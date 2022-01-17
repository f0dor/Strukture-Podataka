#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"

TrieNodePosition Trie_Create(void)
{
	TrieNodePosition root = NULL;
	root = (TrieNodePosition)malloc(sizeof(TrieNode));

	if (!root) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	root->current_Letter = L"";
	*(root->hashMap) = HashTable_Create();

	return root;
}

TrieNodePosition Trie_CreateTrieNode(wchar_t *letter)
{
	TrieNodePosition newTrieNode = NULL;

	newTrieNode = (TrieNodePosition)malloc(sizeof(TrieNode));

	if (!newTrieNode) {
		perror("Can't allocate memory!\n");
		return NULL;
	}
	wcscpy(newTrieNode->current_Letter, letter);
	*(newTrieNode->hashMap) = HashTable_Create();

	return newTrieNode;
}

int Trie_InputPersonName(TrieNodePosition root, wchar_t* name_surname)
{
	TrieNodePosition temp = root;
	size_t string_length = wcslen(name_surname);
	unsigned int i = 0;
	name_surname = _wcsupr(name_surname);
	ListNodePosition* p = NULL;

	for (i; i < string_length; i++) {
		HashTable_InsertLetter(*(temp->hashMap), &(*(name_surname + i)), p);
		if (i++ >= string_length) { break; }
		i++; LinkedList_SortedInputNextLetter(*p, &(*(name_surname + i)), p);
		if (i++ >= string_length) { break; }
		i++; (*(p))->next_trieNode = Trie_CreateTrieNode(&(*(name_surname + i)));
	}

	return 0;
}