#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#define SIZE 17

ListNodePosition LinkedList_Create(void)
{
	ListNodePosition head = NULL;
	head = (ListNodePosition)malloc(sizeof(ListNode));

	if (!head) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	head->letter = 0;
	head->next_index = NULL;
	head->next_letter = NULL;
	head->next_trieNode = NULL;

	return head;
}

ListNodePosition LinkedList_CreateListNode(wchar_t* letter)
{
	ListNodePosition newListNode = NULL;

	newListNode = (ListNodePosition)malloc(sizeof(ListNode));

	if (!newListNode) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	wcscpy(&(newListNode->letter), letter);
	newListNode->next_index = NULL;
	newListNode->next_letter = NULL;
	
	return newListNode;
}

int LinkedList_Destroy(ListNodePosition head)
{
	ListNodePosition temp = head;
	ListNodePosition q = NULL;

	if (head->next_index == NULL) {
		free(head);
		return 0;
	}

	while (temp->next_index != NULL) {
		q = temp->next_index;
		temp->next_index = q->next_index;
		free(q);
		temp = head;
	}

	free(head);
	return 0;
}

int LinkedList_SortedInputNextIndex(ListNodePosition head, wchar_t* letter, ListNodePosition* position)
{
	ListNodePosition temp = head;
	ListNodePosition p = NULL;

	while ((temp->next_index != NULL) && (wcscmp(letter, &(temp->next_index->letter)) > 0)) {
		temp = temp->next_index;
	}

	LinkedList_InsertAfterNextIndex(temp, p = LinkedList_CreateListNode(letter));

	*position = p;

	if (temp->next_index == NULL) {
		return 2;
	} else {
		return 1;
	}
}

int LinkedList_SortedInputNextLetter(ListNodePosition head, wchar_t* letter, ListNodePosition* position)
{
	ListNodePosition temp = head;
	ListNodePosition p = NULL;

	while ((temp->next_letter != NULL) && (wcscmp(letter, &(temp->next_letter->letter)) > 0)) {
		temp = temp->next_letter;
	}

	LinkedList_InsertAfterNextLetter(temp, p = LinkedList_CreateListNode(letter));

	*position = p;

	if (temp->next_letter == NULL) {
		return 2;
	}
	else {
		return 1;
	}
}

int LinkedList_CheckLetter(ListNodePosition head, wchar_t* letter, ListNodePosition* position)
{
	ListNodePosition temp = head;

	while (temp->next_index != NULL) {
		if (temp->letter == *letter) {
			position = &temp;
			return 1; // IF THE LETTER EXISTS IN THE LINKED LIST, RETURN 1
		}
		temp = temp->next_index;
	}

	return 0; // ELSE, RETURN 0!
}

int LinkedList_InsertAfterNextIndex(ListNodePosition position, ListNodePosition newListNode)
{
	newListNode->next_index = position->next_index;
	position->next_index = newListNode;

	return EXIT_SUCCESS;
}

int LinkedList_InsertAfterNextLetter(ListNodePosition position, ListNodePosition newListNode)
{
	newListNode->next_letter = position->next_letter;
	position->next_letter = newListNode;

	return EXIT_SUCCESS;
}

int LinkedList_InsertBefore(ListNodePosition head, ListNodePosition position, ListNodePosition newListNode)
{
	ListNodePosition temp = head;
	
	while ((temp->next_index != NULL) && (temp->next_index != position)) {
		temp = temp->next_index;
	}

	LinkedList_InsertAfterNextIndex(temp, newListNode);

	return EXIT_SUCCESS;
}