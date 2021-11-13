#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Position CreateStackElement(double number)
{
	Position newElement = NULL;

	newElement = (Position)malloc(sizeof(StackElement));
	if (!newElement) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	newElement->number = number;
	newElement->next = NULL;

	return newElement;
}

int InsertAfter(Position position, Position newStackElement)
{
	newStackElement->next = position->next;
	position->next = newStackElement;

	return EXIT_SUCCESS;
}

int Push(Position head, double number)
{
	Position newElement = NULL;

	newElement = CreateStackElement(number);

	if (!newElement) {
		return -1;
	}

	InsertAfter(head, newElement);

	return EXIT_SUCCESS;
}

int DeleteAfter(Position position)
{
	Position temp = position->next;

	if (!temp) {
		return EXIT_SUCCESS;
	}

	position->next = temp->next;

	free(temp);

	return EXIT_SUCCESS;
}

int Pop(double* destination, Position head)
{
	Position first = head->next;

	if (!first) {
		perror("Postfix not valid! Check your file!\n");
		return -1;
	}

	*destination = first->number;

	DeleteAfter(head);

	return EXIT_SUCCESS;
}

int PerformOperation(Position head, char operation)
{
	double operand2 = 0;
	double operand1 = 0;
	int status1 = EXIT_SUCCESS;
	int status2 = EXIT_SUCCESS;
	double result = 0;

	status2 = Pop(&operand2, head);
	if (status2 != EXIT_SUCCESS) {
		return -1;
	}

	status1 = Pop(&operand1, head);
	if (status1 != EXIT_SUCCESS) {
		return -2;
	}

	switch (operation)
	{
	case '+':
	{
		result = operand1 + operand2;
		break;
	}
	case '-':
	{
		result = operand1 - operand2;
		break;
	}
	case '*':
	{
		result = operand1 * operand2;
		break;
	}
	case '/':
	{
		if (operand2 == 0) {
			printf("Cannot divide with zero!\n");
			return -3;
		}
		result = operand1 / operand2;
		break;
	}
	default:
		printf("This operation is not supported yet!\n");
		return -4;
	}

	Push(head, result);

	return EXIT_SUCCESS;
}

int CalculatePostfix(double* destination, char* fileName)
{
	FILE* file = NULL;
	size_t fileLength = 0;
	char* buffer = NULL;
	char* currentBuffer = NULL;
	int numBytes = 0;
	char operation = 0;
	double number = 0;
	int status = EXIT_SUCCESS;;
	StackElement head = { .number = 0, .next = NULL };

	file = fopen(fileName, "rb");
	if (!file) {
		perror("Can't open file!\n");
		return -1;
	}

	fseek(file, 0, SEEK_END);
	fileLength = ftell(file);

	buffer = (char*)calloc(fileLength + 1, sizeof(char));
	if (!buffer) {
		perror("Can't allocate memory!\n");
		return NULL;
	}

	fseek(file, 0, SEEK_SET);
	fread(buffer, sizeof(char), fileLength, file);
	printf("|%s|\n", buffer);
	fclose(file);

	currentBuffer = buffer;
	while (strlen(currentBuffer) > 0) {
		status = sscanf(currentBuffer, " %lf %n", &number, &numBytes);

		if (status == 1) {
			Push(&head, number);
			currentBuffer += numBytes;
		}
		else {
			sscanf(currentBuffer, " %c %n", &operation, &numBytes);
			status = PerformOperation(&head, operation);

			if (status != EXIT_SUCCESS) {
				free(buffer);
				while (head.next != NULL) {
					DeleteAfter(&head);
				}
				return -1;
			}
			currentBuffer += numBytes;
		}
	}

	*destination = head.next->number;

	free(buffer);
	return EXIT_SUCCESS;
}