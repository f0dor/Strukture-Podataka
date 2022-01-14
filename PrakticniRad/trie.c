#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#define SIZE 17

TrieNodePosition TrieCreate(void)
{
	TrieNode p = { .current_Letter = "", .hashMap = NULL };
	TrieNodePosition Root = &p;

	return Root;
}
