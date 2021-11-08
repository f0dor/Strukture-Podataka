#include "Polinom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Position newPoly(int coef, int exp)
{
	Position NewPoly = NULL;

	NewPoly = (Position)malloc(sizeof(Polinom));

	if (!NewPoly) {
		perror("Can't allocate memory!\n");	
		return NULL;
	} 

	NewPoly->coef = coef;
	NewPoly->exp = exp;
	NewPoly->next = NULL;

	return NewPoly;
}

int SortedInput(Position head, Position newPoly)
{
	Position temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
		if (newPoly->exp > temp->next->exp) {
			InsertAfter(temp, newPoly);
			break;
		}
	}

	return EXIT_SUCCESS;
}

int InsertAfter(Position position, Position newPoly)
{
	newPoly->next = position->next;
	position->next = newPoly;

	return EXIT_SUCCESS;
}

int InsertBefore(Position head, Position position, Position newPoly)
{
	Position temp = head;

	while (temp->next != NULL && temp->next != position) {
		temp = temp->next;
	}

	newPoly->next = temp->next;
	temp->next = newPoly;

	return EXIT_SUCCESS;
}

int ReadFromFile(Position head1, Position head2)
{
	FILE* f = NULL;
	Position temp = NULL;
	char buffer[MAX_LINE] = { 0 };
	char fileName[MAX_SIZE] = { 0 };
	char* p = &buffer;
	int exp = 0, coef = 0;
	int flag = 0, n = 0;


	printf("Unesite naziv datoteke (npr. polinom.txt ): \n");
	if (flag = scanf(" %s", fileName) != 1) {
		printf("Unijeli ste neispravni naziv datoteke!\n");
		return EXIT_FAILURE;
	}
	
	f = fopen(fileName, "r");

	if (!f) {
		printf("Datoteka ne postoji!\n");
		return EXIT_FAILURE;
	}

	while (!feof(f)) {
		flag = fscanf(f, " %d %d", &coef, &exp);
		if (flag == 2) {
			n++;
		}
	}

	if (n <= 0) {
		printf("Prazna datoteka!\n");
		return EXIT_FAILURE;
	}

	rewind(f);

	temp = head1;
	while (!feof(f)) {
		fgets(buffer, MAX_LINE, f);
		while (strlen(buffer) > 0) {
			if (flag = sscanf(buffer, " %d %d %n", &coef, &exp, &n) != 2) {
				p += n;
				continue;
			} else {
				InsertAfter(temp, newPoly(coef, exp));
				p += n;
			}
		}
		temp = head2;
	}

	fclose(f);
	return EXIT_SUCCESS;
}

int PrintList(Position head)
{
	Position temp = head->next;

	while (temp != NULL) {
		printf("%dx^%d + ", temp->coef, temp->exp);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}

int CountList(Position head)
{
	Position temp = head;
	int n = 0;

	while (temp->next != NULL) {
		n++;
		temp = temp->next;
	}

	return n;
}
