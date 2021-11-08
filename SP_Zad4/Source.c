#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Polinom.h"
#define MAX_SIZE 50
#define MAX_LINE 1024

int main()
{
	Polinom P1 = { .next = NULL, .coef = 0, .exp = 0 };
	Polinom P2 = { .next = NULL, .coef = 0, .exp = 0 };
	Position Head1 = &P1;
	Position Head2 = &P2;

	ReadFromFile(Head1, Head2);

	PrintList(Head1);

	return 0;
}