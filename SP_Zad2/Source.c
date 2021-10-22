#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

struct _Person;
typedef struct _Person* Position;
typedef struct _Person {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear;
	Position next;
}Person;

int PrependList(Position head, char* name, char* surname, int birthYear);	// dodavanje elemenata na pocetak liste
int AppendList(Position head, char* name, char* surname, int birthYear);	// dodavanje elemenata na kraj liste
int PrintList(Position first);												// ispisivanje liste
Position CreatePerson(char* name, char* surname, int birthYear);			// stvaranje novih elemenata
int InsertAfter(Position position, Position newPerson);						// dodavanje elemenata nakon zadanog elementa
Position FindLast(Position head);											// pronalaženje zadnjeg elementa
Position FindBySurname(Position first, char* surname);						// pronalaženje po prezimenu
Position FindBefore(Position head, Position position);						// pronalaženje prethodnog elementa zadanog elementa
int DeleteAfter(Position first);											// brisanje elementa nakon zadanog elementa



int main(int argc, char** argv) {

	Person Head = { .next = NULL, .name = {0}, .surname = {0}, .birthYear = 0 };
	Position p = &Head;
	
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

	while (temp) {
		printf("Name: %s, surname: %s, birthyear: %d\n", temp->name, temp->surname, temp->birthYear);
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
		return -1;
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

Position FindLast(Position head)
{
	Position temp = head;

	while (temp->next) {}

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

Position FindBefore(Position head, Position position)
{
	Position temp = head;
	while (temp->next != position) {
		temp = temp->next;
	}
	return temp;
}

int DeleteAfter(Position first)
{
	Position temp = first->next;

	temp = temp->next;
	free(first->next);

	return EXIT_SUCCESS;
}
