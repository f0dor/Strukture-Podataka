#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedLists.h"
#define MAX_SIZE 50
#define MAX_LINE 1024


int main() {

	Person Head = { .next = NULL, .name = {0}, .surname = {0}, .birthYear = 0 };
	Position p = &Head;

	InputFromConsole(p);
	PrintList(p->next);

	return EXIT_SUCCESS;
}