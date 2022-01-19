#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <Windows.h>
#include "trie.h"
#include "linkedList.h"
#include "hashTable.h"
#include "dictionary.h"
#define SIZE 17
#define MAX_SIZE 1024

int main()
{
	long time = 0;
	time = StartTimer();
	char* locale;
	locale = setlocale(LC_ALL, "");

	TrieNodePosition root = Trie_Create();
	InputFromFile(root, "ime_prezime.txt");

	MeasureMemoryUsage();
	EndTimer(time);
	return 0;
}