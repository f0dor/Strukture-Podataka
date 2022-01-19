#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <Windows.h>
#include "trie.h"
#include "hashTable.h"
#include "linkedList.h"
#include "dictionary.h"
#define SIZE 17
#define MAX_SIZE 1024

int InputFromFile(TrieNodePosition root, char* fileName)
{
	FILE* file = NULL;
	wchar_t name[MAX_SIZE] = { 0 };
	wchar_t surname[MAX_SIZE] = { 0 };
	wchar_t* name_surname = { 0 };
	int flag = 0;

	file = fopen(fileName, "r");

	if (!file) {
		printf("File couldn't open!\n");
		return -1;
	}

	while (!feof(file)) {
		flag = fwscanf(file, L" %ws %ws\n", name, surname);
		if (flag != 2) {
			printf("Corrupt file!\n");
			fclose(file);
			return -3;
		}

		name_surname = wcscat(name, L" ");
		name_surname = wcscat(name_surname, surname);
		
		//PUSH THE NAME AND SURNAME TO A TRIE INPUT FUNCTION

		Trie_InputPersonName(root, name_surname);
	}
	
	printf("All names successfully input!\n");
	fclose(file);

	return 0;
}

void MeasureMemoryUsage() {
	MEMORYSTATUSEX memInfo;
	unsigned int size = 0;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;
	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
	size = (unsigned int)totalPhysMem;
	size = size / 1024;
	printf("%d KB of used memory!\n", size);
	size = size / 1024;
	printf("%d MB of used memory!\n", size);
}

long StartTimer() {
	clock_t begin = clock();
	return begin;
}

void EndTimer(long a) {
	clock_t end = clock();
	double time_spent = (double)(end - a) / CLOCKS_PER_SEC;
	printf("Elapsed time = %lf miliseconds\n", time_spent);
}