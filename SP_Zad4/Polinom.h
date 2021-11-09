#ifndef POLINOM
#define POLINOM
#define MAX_SIZE 50
#define MAX_LINE 1024

struct _Polinom;
typedef struct _Polinom* Position;
typedef struct _Polinom {
	int coef;
	int exp;
	Position next;
} Polinom;

Position newPoly(int coef, int exp);
int AddPoly(Position head1, Position head2, Position result);
int MultiplyPoly(Position head1, Position head2, Position result);
int MergeAfter(Position position, Position newPoly);
int SortedInput(Position head, Position newPoly);
int InsertAfter(Position position, Position newPoly);
int InsertBefore(Position head, Position position, Position newPoly);
int DeleteAfter(Position position);
int ReadFromFile(Position head1, Position head2);
int PrintList(Position head);
int CountList(Position head);

#endif
