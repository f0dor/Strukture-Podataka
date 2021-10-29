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
	if (((scanf(" %d", &n)) != 1)) {
		printf("\nBroj clanova liste mora biti samo jedan prirodan broj!\n");
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

int isSorted(Position head)
{
	Position temp = head;
	Position q = temp->next;
	int n = CountList(head);
	int br = 0;

	while (!q) {
		if ((q == NULL) || (q->next == NULL)) {
			return EXIT_FAILURE;
		}
		if (strcmp(q->surname, q->next->surname) > 0) {
			br++;
		}
		q = q->next;;
	}

	if (br == n - 1) {
		return 0;
	} else {
		return -1;
	}
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

int SortBySurname(Position head)
{
	Position temp = head;
	Position p = NULL;
	Position q = NULL;
	if ((temp->next == NULL) || ((temp->next)->next == NULL)) {
		printf("Lista je ili prazna ili ima samo jedan element!\n\n");
		return EXIT_FAILURE;
	}

	while (isSorted != 0) {
		temp = head;
		p = temp->next;
		q = p->next;
		while (p != NULL) {
			if (p == NULL) {
				printf("NULL pointer!\n");
				return EXIT_FAILURE;
			}
			if (strcmp(p->surname, q->surname) < 0) {
				temp->next = p->next;
				p->next = q->next;
				q->next = p;
			}
			q = q->next;
			p = p->next;
		}
	}
	return EXIT_SUCCESS;
}

int ReadFromFile(Position head)
{
	FILE* f = NULL;
	Position temp = head->next;
	char file[MAX_SIZE] = { 0 };
	char name[MAX_SIZE] = { 0 };
	char surname[MAX_SIZE] = { 0 };
	int birthYear = 0;
	int n = 0;
	int flag = 0;

	printf("Unesite ime datoteke (npr. lista.txt): \n\n");
	flag = scanf(" %s", file);
	if (flag != 1) {
		return EXIT_FAILURE;
	}
	
	f = fopen(file, "r");
	if (!f) {
		return EXIT_FAILURE;
	}

	while (!feof(f)) {
		flag = fscanf(f," %s %s %d", name, surname, &birthYear);
		if (flag == 3) {
			n++;
		}
	}

	if (n <= 0) {
		printf("Prazna datoteka!\n");
		return EXIT_FAILURE;
	}

	rewind(f);

	while (!feof(f)) {
		flag = fscanf(f," %s %s %d", name, surname, &birthYear);
		if (flag != 3) {
			continue;
		} else {
			AppendList(head, name, surname, birthYear);
		}
	}
	return EXIT_SUCCESS;
}

int WriteToFile(Position head)
{
	FILE* f = NULL;
	Position temp = head->next;
	int flag = 0;
	char file[MAX_SIZE] = { 0 };

	printf("Kako zelite nazvati datoteku? (npr. list.txt): \n\n");
	flag = scanf(" %s", file);
	if (flag != 1) {
		return EXIT_FAILURE;
	}
	f = fopen(file, "w");

	if (!f || !temp) {
		return EXIT_FAILURE;
	}
	
	while (temp != NULL) {
		fprintf(f, "Name: %s\nSurname: %s\nBirthyear: %d\n\n", temp->name, temp->surname, temp->birthYear);
		temp = temp->next;
	}
	return EXIT_SUCCESS;
}
