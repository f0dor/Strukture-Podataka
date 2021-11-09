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
	Polinom P3 = { .next = NULL, .coef = 0, .exp = 0 };
	Polinom P4 = { .next = NULL, .coef = 0, .exp = 0 };
	Position Head1 = &P1;
	Position Head2 = &P2;
	Position Head3 = &P3;
	Position Head4 = &P4;

	ReadFromFile(Head1, Head2);

	PrintList(Head1, "Polinom 1");
	PrintList(Head2, "Polinom 2");

	AddPoly(Head1, Head2, Head3);
	PrintList(Head3, "Zbroj polinoma P1 i P2");

	MultiplyPoly(Head1, Head2, Head4);
	PrintList(Head4, "Umnozak polinoma P1 i P2");

	return 0;
}