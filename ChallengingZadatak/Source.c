#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericList.h"


int main()
{
	List Head = { .next = NULL };
	ListP p = &Head;
	int r = InputType();

	InputFromConsole(p, r);


	return 0;
}