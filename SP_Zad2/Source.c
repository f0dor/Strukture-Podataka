#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedLists.h"
#define MAX_SIZE 50


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

	// PrintList(p->next);													maknuti komentar da se vidi stanje poslije
	
	return EXIT_SUCCESS;
}