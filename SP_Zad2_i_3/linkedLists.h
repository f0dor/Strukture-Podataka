#ifndef LINKED_LISTS_
#define LINKED_LISTS_
#define MAX_SIZE 50
#define MAX_LINE 1024

struct _Person;
typedef struct _Person* Position;
typedef struct _Person {
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	int birthYear;
	Position next;
}Person;

int InputFromConsole(Position head);
int PrependList(Position head, char* name, char* surname, int birthYear);	// dodavanje elemenata na pocetak liste
int AppendList(Position head, char* name, char* surname, int birthYear);	// dodavanje elemenata na kraj liste
int PrintList(Position first);												// ispisivanje liste
Position CreatePerson(char* name, char* surname, int birthYear);			// stvaranje novih elemenata
int InsertAfter(Position position, Position newPerson);						// dodavanje elementa nakon zadanog elementa
int InsertBefore(Position head, Position position, Position newPerson);		// dodavanje elementa prije zadanog elementa
Position FindLast(Position head);											// pronalaženje zadnjeg elementa
int CountList(Position head);												// pronadji broj clanova liste
Position FindBySurname(Position first, char* surname);						// pronalaženje po prezimenu
Position FindBefore(Position first, Position position);						// pronalaženje prethodnog elementa zadanog elementa
int DeleteAfter(Position position);											// brisanje elementa nakon zadanog elementa
int SortBySurname(Position head);
int SortedInput(Position head, Position newPerson);
int ReadFromFile(Position head);
int WriteToFile(Position head);

#endif