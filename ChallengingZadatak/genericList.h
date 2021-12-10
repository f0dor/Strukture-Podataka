#ifndef GENERIC_LIST
#define GENERIC_LIST

struct _list;
typedef struct _list* ListP;
typedef struct _list {
	ListP next;
} List;


ListP CreateElement(int type, int integer, char* character, double doub, char* string);
int InputType();
int InputFromConsole(ListP head, int type);
int InsertAfter(ListP position, ListP newElement);
int InsertBefore(ListP head, ListP position, ListP newElement);
int SortedInput(ListP head, ListP newElement, int type);



#endif