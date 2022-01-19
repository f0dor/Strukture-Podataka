#ifndef DICTIONARY_
#define DICTIONARY_
#define SIZE 17
#define MAX_SIZE 1024
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"

int InputFromFile(TrieNodePosition root, char* fileName);
void MeasureMemoryUsage();
long StartTimer();
void EndTimer(long a);

#endif // !DICTIONARY_