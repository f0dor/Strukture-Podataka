#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedLists.h"
#define MAX_SIZE 50


int main() {

	Person Head = { .next = NULL, .name = {0}, .surname = {0}, .birthYear = 0 };
	Position p = &Head;
	
	Input(p);
	
	PrintList(p->next);
	
	return EXIT_SUCCESS;
}