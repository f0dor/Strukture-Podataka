#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#define SIZE 17

ListNodePosition LinkedListCreate(void)
{
	ListNode p = { .hashMap = NULL, .letter = 0, .next = NULL };
	ListNodePosition Head = &p;

	return Head;
}

int LinkedListDestroy(ListNodePosition head)
{
	ListNodePosition temp = head;
	ListNodePosition q = NULL;

	if (head->next == NULL) {
		free(head);
		return 0;
	}

	while (temp->next != NULL) {
		q = temp->next;
		temp->next = q->next;
		free(q);
		temp = head;
	}

	free(head);
	return 0;
}