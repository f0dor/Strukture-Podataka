#include "genericList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 256


ListP CreateElement(int type, int integer, char* character, double doub, char* string)
{
	ListP newElement = NULL;

	switch (type)
	{
	case '1':
		
		break;
	case '2':
		
		break;
	case '3':
		
		break;
	case '4':
		
		break;
	default:
		printf("\n :( Oops! Something went wrong! :(\n");
		break;
	}

	return newElement;
}

int InputType()
{
	int r = 0;
	int i = 0;
	printf("\n\t\tGENERIC LINKED LIST\n\n");
	printf("\t================================================");
	printf("\n\t1 - integers\n\t2 - characters\n\t3 - floating point numbers\n\t4 - strings \n");
	printf("\t================================================\n");

	printf("\nWhat data type do you want to use? (input format: <number of the data type>)\n\n");
	do
	{
		if (i > 0) {
			printf("Invalid input! Try again.\n");
		}
		i = scanf(" %d", &r);
	} while (r < 1 || r > 4);

	return r;
}

int InputFromConsole(ListP head, int type)
{
	ListP newElement = NULL;

	int integer = 0;
	double doub = 0.0;
	char character = '\0';
	char string[MAX_LENGTH] = { 0 };
	int n = 0, i = 0;

	printf("\nHow many elements do you want to input?\n");
	scanf(" %d", &n);

	for (i = 0; i < n; i++) {
		switch (type)
		{
		case '1':
			scanf(" %d", &integer);
			newElement = CreateElement(type, integer, NULL, 0, NULL);
			
			break;
		case '2':
			scanf(" %c", &character);
			newElement = CreateElement(type, 0, &character, 0, NULL);

			break;
		case '3':
			scanf(" %lf", &doub);
			newElement = CreateElement(type, 0, NULL, doub, NULL);

			break;
		case '4':
			scanf(" %s", string);
			newElement = CreateElement(type, 0, NULL, 0, string);

			break;
		default:
			break;
		}
	}
	return EXIT_SUCCESS;
}

int InsertAfter(ListP position, ListP newElement)
{
	newElement->next = position->next;
	position->next = newElement;

	return EXIT_SUCCESS;
}

int InsertBefore(ListP head, ListP position, ListP newElement)
{
	ListP temp = head;

	while ((temp->next != position) && (temp->next != NULL)) {
		temp = temp->next;
	}

	newElement->next = temp->next;
	temp->next = newElement;

	return EXIT_SUCCESS;

}

int SortedInput(ListP head, ListP newElement, int type)
{
	ListP temp = head;


	return 0;
}
