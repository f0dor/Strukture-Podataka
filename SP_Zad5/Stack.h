#ifndef STACK
#define STACK

struct _StackElement;
typedef struct _StackElement* Position;
typedef struct _StackElement {
	double number;
	Position next;
} StackElement;

Position CreateStackElement(double number);
int InsertAfter(Position position, Position newStackElement);
int Push(Position head, double number);
int DeleteAfter(Position position);
int Pop(double* destination, Position head);
int PerformOperation(Position head, char operation);
int CalculatePostfix(double* destination, char* fileName);

#endif