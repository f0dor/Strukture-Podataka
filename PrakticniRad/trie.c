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
	TrieNode p = { .current_Letter = "", .hashMap = NULL };
	TrieNodePosition Root = &p;

	return Root;
}

TrieNodePosition Trie_CreateTrieNode(wchar_t letter)
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

int Trie_InputPersonName(TrieNodePosition root, wchar_t* name_surname, ListNodePosition* position)
{
	TrieNodePosition temp = root;
	size_t string_length = wcslen(name_surname);
	ListNodePosition* position = NULL;
	int i = 0;

	

}