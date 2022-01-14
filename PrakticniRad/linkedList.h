#ifndef LINKED_LISTS_
#define LINKED_LISTS_
#define SIZE 17
#include "trie.h"

struct _ListNode;
typedef struct _ListNode* ListNodePosition;

#include "hashTable.h"

typedef struct _ListNode {
	HashTablePosition hashMap[SIZE];
	wchar_t letter;
	ListNodePosition next;
} ListNode;

// CREATE AND DESTROY FUNCTIONS
ListNodePosition LinkedListCreate(void);
int LinkedListDestroy(ListNodePosition head);




#endif // !LINKED_LISTS_

