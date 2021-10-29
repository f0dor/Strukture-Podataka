#include "linkedLists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Input(Position head)
{
	int n = 0, i = 0;
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthYear = 0;
	Position p = head;

	printf("Koliko clanova liste zelite unijeti?\n");
	if ((scanf(" %d", &n)) != 1) {
		printf("\nBroj clanova liste mora biti prirodan broj!\n");
		return -5;
	}
	for (i = 0; i < n; i++) {
		printf("\nUnesite IME, PREZIME i GODINU RODJENJA: \n");
		if ((scanf(" %s %s %d", name, surname, &birthYear)) != 3) {
			printf("\nKrivo uneseni podatci!\n");
			return -10;
		}
		AppendList(p, name, surname, birthYear);
	}

	return EXIT_SUCCESS;
}

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
		printf("\n\tName: %s\n\tSurname: %s\n\tBirthyear: %d\n\n", temp->name, temp->surname, temp->birthYear);
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

int CountList(Position head)
{
	int n = 0;
	Position temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		n++;
	}
	return n;
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

int DeleteAfter(Position position)
{
	Position temp = position;
	Position q = NULL;

	if (temp->next == NULL) {
		return -2;
	}
	else {
		q = temp->next;
		temp->next = q->next;
		free(q);
		return EXIT_SUCCESS;
	}
}
