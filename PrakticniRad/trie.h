#ifndef TRIES_
#define TRIES_
#define SIZE 17

struct _TrieNode;
typedef struct _TrieNode* TrieNodePosition;

#include "linkedList.h"
#include "hashTable.h"

typedef struct _TrieNode {
	wchar_t* current_Letter;
	HashTablePosition hashMap[SIZE];
} TrieNode;

TrieNodePosition Trie_Create(void);
TrieNodePosition Trie_Destroy(TrieNodePosition root);

TrieNodePosition Trie_CreateTrieNode(wchar_t* letter);

int Trie_InputPersonName(TrieNodePosition root, wchar_t* name_surname, ListNodePosition* position);
#endif // !TRIES