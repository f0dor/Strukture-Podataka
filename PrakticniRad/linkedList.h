#ifndef LINKED_LISTS_
#define LINKED_LISTS_
#define SIZE 17

struct _ListNode;
typedef struct _ListNode* ListNodePosition;

#include "trie.h"
#include "hashTable.h"

typedef struct _ListNode {
	wchar_t* letter;
	ListNodePosition next_index;
	ListNodePosition next_letter;
	TrieNodePosition next_trieNode;
} ListNode;

// CREATE AND DESTROY FUNCTIONS
ListNodePosition LinkedList_Create(void);
ListNodePosition LinkedList_CreateListNode(wchar_t* letter);
int LinkedList_Destroy(ListNodePosition head);

int LinkedList_SortedInputNextIndex(ListNodePosition head, wchar_t* letter, ListNodePosition* position);
int LinkedList_SortedInputNextLetter(ListNodePosition head, wchar_t* letter, ListNodePosition* position);
int LinkedList_CheckLetter(ListNodePosition head, wchar_t* letter, ListNodePosition* position);

// AUXILIARY FUNCTIONS

int LinkedList_InsertAfterNextIndex(ListNodePosition position, ListNodePosition newListNode);
int LinkedList_InsertAfterNextLetter(ListNodePosition position, ListNodePosition newListNode);
int LinkedList_InsertBefore(ListNodePosition head, ListNodePosition position, ListNodePosition newListNode);

#endif // !LINKED_LISTS_