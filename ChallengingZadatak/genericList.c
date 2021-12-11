#include "genericList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 256


ListP CreateElement(int type, int integer, char* character, double doub, char* string)
{
	ListP newElement = NULL;

	switch (type)
	{
	case 1:
		newElement = malloc(sizeof(List) + sizeof(int));
		if (!newElement) {
			return NULL;
		}
		break;
	case 2:
		newElement = malloc(sizeof(List) + sizeof(char));
		if (!newElement) {
			return NULL;
		}
		break;
	case 3:
		newElement = malloc(sizeof(List) + sizeof(double));
		if (!newElement) {
			return NULL;
		}
		break;
	case 4:
		newElement = malloc(sizeof(List) + (1 + strlen(string) * sizeof(char)));
		if (!newElement) {
			return NULL;
		}
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
		scanf(" %d", &r);
		i++;
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
	int flag = 0;

	printf("\nHow many elements do you want to input?\n");
	flag = scanf(" %d", &n);

	switch (type)
		{
		case 1:
			for (i = 0; i < n; i++) {
				printf("Input %d. element: ", i + 1);
				flag = scanf(" %d", &integer);
				newElement = CreateElement(type, integer, NULL, 0, NULL);
				InsertAfter(head, newElement);
			}
			break;
		case 2:
			for (i = 0; i < n; i++) {
				printf("Input %d. element: ", i + 1);
				flag = scanf(" %c", &character);
				newElement = CreateElement(type, 0, &character, 0, NULL);
				InsertAfter(head, newElement);
			}
			break;
		case 3:
			for (i = 0; i < n; i++) {
				printf("Input %d. element: ", i + 1);
				flag = scanf(" %lf", &doub);
				newElement = CreateElement(type, 0, NULL, doub, NULL);
				InsertAfter(head, newElement);
			}
			break;
		case 4:
			for (i = 0; i < n; i++) {
				printf("Input %d. element: ", i + 1);
				flag = scanf(" %s", string);
				newElement = CreateElement(type, 0, NULL, 0, string);
				InsertAfter(head, newElement);
			}
			break;
		default:
			break;
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

	switch (type)
	{
	case 1:
		while ( (temp->next != NULL) && (*((int*)(newElement->next + 4)) < *((int*)(newElement->next->next + 4))) ) {
			temp = temp->next;
		}
		InsertAfter(temp, newElement);
		return EXIT_SUCCESS;
	case 2:
		while ( (temp->next != NULL) && ( strcmp(*((char*)(newElement->next + 4)), *((char*)(newElement->next->next + 4)))) > 0 ){
			temp = temp->next;
		}
		InsertAfter(temp, newElement);
		return EXIT_SUCCESS;
	case 3:
		while ((temp->next != NULL) && (*((double*)(newElement->next + 4)) < *((double*)(newElement->next->next + 4)))) {
			temp = temp->next;
		}
		InsertAfter(temp, newElement);
		return EXIT_SUCCESS;
	case 4:
		while ((temp->next != NULL) && ( strcmp(*((char*)(newElement->next + 4)), *((char*)(newElement->next->next + 4)))) > 0 ) {
			temp = temp->next;
		}
		InsertAfter(temp, newElement);
		return EXIT_SUCCESS;
	default:
		break;
	}
	return EXIT_FAILURE;
}

int PrintList(ListP head, int type)
{
	ListP temp = head;

	switch (type)
	{
	case 1:
		while (temp->next != NULL) {
			printf(" %d ", *((int*)(temp + 4)));
			temp = temp->next;
		}
		break;
	case 2:
		while (temp->next != NULL) {
			printf(" %c ", *((char*)(temp + 4)));
			temp = temp->next;
		}
		break;
	case 3:
		while (temp->next != NULL) {
			printf(" %lf ", *((double*)(temp + 4)));
			temp = temp->next;
		}
		break;
	case 4:
		while (temp->next != NULL) {
			printf(" %s ", ((char*)(temp + 4)));
			temp = temp->next;
		}
		break;
	default:
		break;
	}

	return EXIT_SUCCESS;
}
