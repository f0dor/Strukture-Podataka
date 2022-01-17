#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
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
		flag = fwscanf(file, L" %s %s", name, surname);
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
	
	fclose(file);

	return 0;
}