#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int main()
{
	double result = 0;

	CalculatePostfix(&result, "postfix.txt");

	printf("Calculated value of the postfix expression = %.1f\n", result);

	return EXIT_SUCCESS;
}