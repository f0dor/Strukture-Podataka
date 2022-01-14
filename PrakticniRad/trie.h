#ifndef TRIES_
#define TRIES_
#define SIZE 17

struct _TrieNode;
typedef struct _TrieNode* TrieNodePosition;

#include "linkedList.h"
#include "hashTable.h"

typedef struct _TrieNode {
	wchar_t	current_Letter;
	HashTablePosition hashMap[SIZE];
} TrieNode;

TrieNodePosition Trie_Create(void);
TrieNodePosition Trie_Destroy(TrieNodePosition root);
#endif // !TRIES