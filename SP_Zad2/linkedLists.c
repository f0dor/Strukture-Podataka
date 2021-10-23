#include "linkedLists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int PrependList(Position head, char* name, char* surname, int birthYear)
{

	Position newPerson = NULL;

	newPerson = CreatePerson(name, surname, birthYear);
	if (!newPerson) {
		return -1;
	}

	InsertAfter(head, newPerson);

	return EXIT_SUCCESS;
}

int AppendList(Position head, char* name, char* surname, int birthYear)
{
	Position newPerson = NULL;
	Position last = NULL;

	newPerson = CreatePerson(name, surname, birthYear);
	if (!newPerson) {
		return -1;
	}

	last = FindLast(head);
	InsertAfter(last, newPerson);

	return EXIT_SUCCESS;
}

int PrintList(Position first)
{
	Position temp = first;

	while (temp != NULL) {
		printf("Name: %s\nSurname: %s\nBirthyear: %d\n\n", temp->name, temp->surname, temp->birthYear);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}

Position CreatePerson(char* name, char* surname, int birthYear)
{
	Position newPerson = NULL;

	newPerson = (Position)malloc(sizeof(Person));
	if (!newPerson) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	strcpy(newPerson->name, name);
	strcpy(newPerson->surname, surname);
	newPerson->birthYear = birthYear;
	newPerson->next = NULL;

	return newPerson;
}

int InsertAfter(Position position, Position newPerson)
{
	newPerson->next = position->next;
	position->next = newPerson;

	return EXIT_SUCCESS;
}

int InsertBefore(Position head, Position position, Position newPerson)
{
	Position temp = head;
	while ((temp->next != NULL) && (temp->next != position)) {
		temp = temp->next;
	}

	newPerson->next = temp->next;
	temp->next = newPerson;
	return EXIT_SUCCESS;;
}

Position FindLast(Position head)
{
	Position temp = head;

	if (temp->next == NULL) {
		return head;
	}

	while (temp->next) {
		temp = temp->next;
	}


	return temp;
}

Position FindBySurname(Position first, char* surname)
{
	Position temp = first;
	while (temp) {
		if (strcmp(temp->surname, surname) == 0) {
			return temp;
		}
	}
	return NULL;
}

Position FindBefore(Position first, Position position)
{
	Position temp = first;
	while ((temp->next != NULL) && (temp->next != position)) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		return NULL;
	}
	else {
		return temp;
	}
}

int DeleteAfter(Position head, Position position)
{
	Position temp = head;
	Position q;

	while ((temp->next) && (temp != position)) {
		temp = temp->next;
	}

	if (temp->next == NULL) {
		return -2;
	}
	else {
		q = temp->next;
		temp->next = (temp->next)->next;
		free(q);
		return EXIT_SUCCESS;
	}
}