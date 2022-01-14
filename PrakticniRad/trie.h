#ifndef TRIES_
#define TRIES_
#define SIZE 17
#include "linkedList.h"
#include "hashTable.h"

struct _TrieNode;
typedef struct _TrieNode* TrieNodePosition;

typedef struct _TrieNode {
	wchar_t	current_Letter;
	HashTablePosition hashMap[SIZE];
} TrieNode;

TrieNodePosition TrieCreate(void);
#endif // !TRIES