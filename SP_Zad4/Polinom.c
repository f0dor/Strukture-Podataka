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

int AddPoly(Position head1, Position head2, Position result)
{
	Position temp1 = head1;
	Position temp2 = head2;
	int tmp = 0;
	int flag = 0;

	while (temp1->next != NULL) {
		while (temp2->next != NULL) {
			if (temp1->next->exp == temp2->next->exp) {
				tmp = temp1->next->coef + temp2->next->coef;
				SortedInput(result, newPoly(tmp, temp1->next->exp));
				temp2 = temp2->next;
				break;
			} else if (temp1->next->exp != temp2->next->exp) {
				flag = 1;
			} else {
				flag = 2;
			}
			temp2 = temp2->next;
		}
		if (flag == 1) {
			SortedInput(result, newPoly(temp1->next->coef, temp1->next->exp));
		}
		temp1 = temp1->next;
	}

	temp1 = head1;
	temp2 = head2;
	flag = 0;

	while (temp2->next != NULL) {
		while (temp1->next != NULL) {
			if (temp2->next->exp == temp1->next->exp) {
				temp1 = temp1->next;
				break;
			} else if (temp2->next->exp != temp1->next->exp) {
				flag = 1;
			}
			temp1 = temp1->next;
		}
		if (flag == 1) {
			SortedInput(result, newPoly(temp2->next->coef, temp2->next->exp));
		}
		temp2 = temp2->next;
	}

	return EXIT_SUCCESS;
}

int MultiplyPoly(Position head1, Position head2, Position result)
{
	Position temp1 = head1;
	Position temp2 = head2;
	int tmp1 = 0, tmp2 = 0;

	while (temp1->next != NULL) {
		while (temp2->next != NULL) {
			tmp1 = temp1->next->coef * temp2->next->coef;
			tmp2 = temp1->next->exp + temp2->next->exp;
			SortedInput(result, newPoly(tmp1, tmp2));
			temp2 = temp2->next;
		}
		temp2 = head2;
		temp1 = temp1->next;
	}
}

int MergeAfter(Position position, Position newPoly)
{
	if (position->next == NULL || position->next->exp != newPoly->exp) {
		InsertAfter(position, newPoly);
	} else {
		int tmp = newPoly->coef + position->next->coef;
		if (tmp == 0) {
			DeleteAfter(position);
		} else {
			position->next->coef = tmp;
		}
		free(newPoly);
	}

	return EXIT_SUCCESS;
}

int SortedInput(Position head, Position newPoly)
{
	Position temp = head;

	while (temp->next != NULL && newPoly->exp < temp->next->exp) {
		temp = temp->next;
	}

	MergeAfter(temp, newPoly);
	
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

int ReadFromFile(Position head1, Position head2)
{
	FILE* f = NULL;
	Position temp = NULL;
	char buffer[MAX_LINE] = { 0 };
	char fileName[MAX_SIZE] = { 0 };
	char* p = buffer;
	int exp = 0, coef = 0;
	int flag = 0, n = 0, i = 0;


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

	fgets(buffer, MAX_LINE, f);
	while (strlen(p) > 0) {
		if (flag = sscanf(p, " %d %d %n", &coef, &exp, &n) != 2) {
			p += n;
			continue;
		}

		SortedInput(head1, newPoly(coef, exp));
		p += n;
	}

	fgets(buffer, MAX_LINE, f);
	p = buffer;
	while (strlen(p) > 0) {
		if (flag = sscanf(p, " %d %d %n", &coef, &exp, &n) != 2) {
			p += n;
			continue;
		}

		SortedInput(head2, newPoly(coef, exp));
		p += n;
	}

	fclose(f);
	return EXIT_SUCCESS;
}

int PrintList(Position head, char* name)
{
	Position temp = head;
	Position p = temp->next;

	if (!p) {
		return EXIT_FAILURE;
	}

	printf("\n%s = ", name);

	while(p != NULL) {
		if (p->coef > 0 && p == head->next) {
			if (p->coef != 1) {
				printf("%dx^%d", p->coef, p->exp);
			}else {
				printf("x^%d", p->exp);
			}
		} else if (p->coef < 0 && p == head->next) {
			if (abs(p->coef) != 1) {
				printf("-%dx^%d", p->coef, p->exp);
			}
			else {
				printf("-x^%d", p->exp);
			}
		} else if (p->exp == 0 && p->coef < 0 && p == head->next) {
			if (abs(p->coef) != 1) {
				printf("-%d", abs(p->coef));
			} else {
				printf("-1");
			}
		} else if (p->exp == 0 && p->coef > 0 && p == head->next) {
			if (p->coef != 1) {
				printf("%d", p->coef);
			}
			else {
				printf("1");
			}
		} else if (p->exp == 0 && p->coef < 0 && p != head->next) {
			if (abs(p->coef) != 1) {
				printf(" - %d", abs(p->coef));
			}
			else {
				printf(" - 1");
			}
		} else if (p->exp == 0 && p->coef > 0 && p != head->next) {
			if (p->coef != 1) {
				printf(" + %d", p->coef);
			}
			else {
				printf(" + 1");
			}
		} else if (p->coef > 0 && p != head->next) {
			if (p->coef != 1) {
				printf(" + %dx^%d", p->coef, p->exp);
			}
			else {
				printf(" + x^%d", p->exp);
			}
		} else if (p->coef < 0 && p != head->next) {
			if (abs(p->coef) != 1) {
				printf(" - %dx^%d", abs(p->coef), p->exp);
			}
			else {
				printf(" - x^%d", p->exp);
			}
		}
		p = p->next;
	}
	printf("\n");
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
