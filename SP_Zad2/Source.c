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
int InsertBefore(Position head, Position position, Position newPerson);
Position FindLast(Position head);											// pronalaženje zadnjeg elementa
Position FindBySurname(Position first, char* surname);						// pronalaženje po prezimenu
Position FindBefore(Position first, Position position);						// pronalaženje prethodnog elementa zadanog elementa
int DeleteAfter(Position head, Position position);							// brisanje elementa nakon zadanog elementa



int main() {

	Person Head = { .next = NULL, .name = {0}, .surname = {0}, .birthYear = 0 };
	Position p = &Head;

	char ime[MAX_SIZE] = "Marko";
	char prezime[MAX_SIZE] = "Simic";
	int godina = 2000;

	char ime1[MAX_SIZE] = "Ante";
	char prezime1[MAX_SIZE] = "Petrovic";
	int godina1 = 2002;

	char ime2[MAX_SIZE] = "Sveto";
	char prezime2[MAX_SIZE] = "Karamatic";
	int godina2 = 1998;

	char ime3[MAX_SIZE] = "Josip";
	char prezime3[MAX_SIZE] = "Vukas";
	int godina3 = 1998;

	char ime4[MAX_SIZE] = "Petar";
	char prezime4[MAX_SIZE] = "Latinac";
	int godina4 = 1996;

	AppendList(p, ime, prezime, godina);
	AppendList(p, ime1, prezime1, godina1);
	AppendList(p, ime2, prezime2, godina2);
	
	PrintList(p->next);

	// DeleteAfter(p, p->next);												testiranje brise li uspjesno element
	// InsertAfter(p->next, CreatePerson(ime3, prezime3, godina3));			testiranje dodaje li uspjesno element nakon odreðenog elementa
	// InsertBefore(p, p->next, CreatePerson(ime4, prezime4, godina4));		testiranje dodaje li uspjesno element prije odreðenog elementa

	PrintList(p->next);
	
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
	} else {
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
		} else {
			q = temp->next;
			temp->next = (temp->next)->next;
			free(q);
			return EXIT_SUCCESS;
		}
}
