#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

struct _Polinom;
typedef struct _Polinom* Position;
typedef struct _Polinom {
	int coef;
	int exp;
	Position next;
} Polinom;

Position Sum(Position P1, Position P2);
Position Product(Position P1, Position P2);
Position newPoly(int coef, int exp);
Position FindExponent(Position head, int exp);
int InsertAfter(Position position, Position newPoly);
int InsertBefore(Position head, Position position, Position newPoly);
int SortedInput(Position head, Position newPoly);
int ReadFromFile(Position head);
int PrintList(Position head);

int main()
{
	Polinom P1 = { .next = NULL, .coef = 0, .exp = 0 };
	Polinom P2 = { .next = NULL, .coef = 0, .exp = 0 };
	Position p1 = &P1;
	Position p2 = &P2;

	return 0;
}

Position Product(Position P1, Position P2) {
	
	Position tmp = NULL;
	Position P2tmp = P2;
	Position S = NULL;
	
	while (P1->next != NULL) {
		P2 = P2tmp;
		while (P2->next != NULL) {
			if (FindExponent(S, P1->next->exp + P2->next->exp) == NULL) {
				tmp = newPoly(P1->next->coef * P2->next->coef, P2->next->exp + P2->next->exp);
				SortedInput(S, tmp);
			} else {
				tmp = FindExponent(S, P1->next->exp + P2->next->exp);
				tmp->coef *= P1->next->coef * P2->next->coef;
				tmp->exp += P1->next->exp + P2->next->exp;
			}
			P2 = P2->next;
		}
		P1 = P1->next;
	}

	return S;
}

Position newPoly(int coef, int exp)
{
	Position newPoly = NULL;

	newPoly = (Position)malloc(sizeof(Polinom));
	if (!newPoly) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	newPoly->coef = coef;
	newPoly->exp = exp;
	newPoly->next = NULL;

	return newPoly;
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
	
	while ((temp->next != NULL) && (temp->next != position)) {
		temp = temp->next;
	}

	newPoly->next = temp->next;
	temp->next = newPoly;

	return EXIT_SUCCESS;
}

Position FindExponent(Position head, int exp)
{
	Position temp = head;

	while (temp->next != NULL && temp->next->exp != exp) {
		temp = temp->next;
	}

	if (temp->next == NULL) {
		return NULL;
	} else {
		return temp;
	}
}

int SortedInput(Position head, Position newPoly)
{
	Position temp = head;

	if (temp->next == NULL) {
		InsertAfter(head, newPoly);
	}
	else if (temp->next->next == NULL) {
		if (newPoly->exp < temp->next->exp) {
			InsertAfter(temp->next, newPoly);
		}
		else {
			InsertBefore(head, temp->next, newPoly);
		}
	}
	else {
		while (temp->next->next != NULL) {
			if (newPoly->exp  > temp->next->exp) {
				InsertBefore(head, temp->next, newPoly);
				break;
			} else if ((newPoly->exp < temp->next->exp) && (newPoly->exp > temp->next->next->exp)) {
				InsertAfter(temp->next, newPoly);
				break;
			}
			else {
				temp = temp->next;
			}
		}
	}

	return EXIT_SUCCESS;
}

int ReadFromFile(Position head)
{
	FILE* f = NULL;
	Position temp = head->next;
	Position NewPoly = NULL;
	char file[MAX_SIZE] = { 0 };

	int coef = 0, exp = 0;
	int flag = 0, n = 0;

	printf("Unesite ime datoteke (npr. polinom.txt): \n");
	flag = scanf(" %s", file);
	if (flag != 1) {
		return EXIT_FAILURE;
	}

	f = fopen(file, "r");
	if (!f) {
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

	while (!feof(f)) {
		flag = fscanf(f," %d %d", &coef, &exp);
		if (flag != 2) {
			continue;
		} else {
			NewPoly = newPoly(coef, exp);
			SortedInput(head, NewPoly);
		}
	}
}

int PrintList(Position head)
{
	Position temp = head->next;

	while (temp != NULL) {
		printf("\n\tKoeficijent: %d\n\tEksponent: %d\n\n", temp->coef, temp->exp);
		temp = temp->next;
	}

	return EXIT_SUCCESS;
}