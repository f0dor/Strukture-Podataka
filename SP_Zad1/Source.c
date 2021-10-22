#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE (1024)
#define MAX_NAME (64)

typedef struct {
	char ime[MAX_NAME];
	char prezime[MAX_NAME];
	int bodovi;
}_student;

int procitajAlocirajIspisi(char* imeDatoteke);

/*Komentiran kod je kod kad bi za sve koristio zasebnu funkciju ( za citanje broja redaka, za alociranje memorije, za ispisivanje rezultata, itd.)
Prvo sam napisao ovo sto nije komentirano i radi kako treba, no onda nisam bio siguran je li bolje raditi ovako kako sam ja, ili sve zasebno, kao ovo u komentarima.

U funkciji int procitajAlocirajIspisi, koristio sam funkciju rewind(), da nakon sto izbrojim retke, vratim se na pocetak datoteke. Niste nista spominjali smijemo
li koristiti tu funkciju ili ne, pa sam je ja koristio. LP, Marko.*/

/* int procitaj(char *imeDatoteke*); */
/* _student* alociraj(int n); */
/* void ispisi(int n, _student *s, char *imeDatoteke); */

int main()
{
	char file[30] = { 0 };
	/* _student *stud = NULL; */
	/* int n = 0; */

	printf("Unesite ime datoteke: \n");
	scanf(" %s", file);

	procitajAlocirajIspisi(file);

	/* n = procitaj(file); */
	/* stud = alociraj(n); */
	/* ispisi(n, stud, file); */

	return 0;
}

int procitajAlocirajIspisi(char* datoteka)
{
	FILE* f = NULL;
	_student* stud = NULL;
	int brojac = 0, i = 0;
	float max = 0.0;
	char buffer[MAX_LINE] = { 0 };
	f = fopen(datoteka, "r");

	if (!f) {
		return -1;
	}

	while (!feof(f)) {
		fgets(buffer, MAX_LINE, f);
		brojac++;
	}

	if (brojac <= 0) {
		printf("Prazna datoteka!\n");
		return -2;
	}

	rewind(f);

	stud = (_student*)malloc(brojac * sizeof(_student));

	for (i = 0; i < brojac; i++) {
		fscanf(f, " %s %s %d", stud[i].ime, stud[i].prezime, &stud[i].bodovi);
	}

	max = (float)stud[0].bodovi;
	for (i = 0; i < brojac; i++) {
		if (stud[i].bodovi >= max)
			max = (float)stud[i].bodovi;
	}

	printf("\n\tIME I PREZIME\t\tBODOVI ABS\tBODOVI REL\n");
	for (i = 0; i < brojac; i++) {
		printf("\t%s %s\t\t %d\t\t %.2f%%\n", stud[i].ime, stud[i].prezime, stud[i].bodovi, ((stud[i].bodovi / max) * 100));
	}

	fclose(f);
	return 0;
}

/*

int procitaj(char *imeDatoteke){
	FILE *f = NULL;
	int brojac = 0;
	char buffer[MAX_LINE] = { 0 };
	f = fopen(imeDatoteke, "r");

	if(!f){
		return -1;
	}

	while(!feof(f)){
		fgets(buffer, MAX_LINE, f);
		brojac++;
	}

	if(brojac <= 0){
		printf("Prazna datoteka!\n");
		return -2;
	}

	fclose(f);

	return brojac;
}

*/

/*

_student* alociraj(int n){
	_student *s = NULL;

	s = (_student*)malloc(n * sizeof(_student));

	return s;
}

*/

/*

void ispisi(int n, student *s, char *imeDatoteke){
	FILE *f = NULL;
	f = fopen(imeDatoteke, "r");
	int i = 0;
	float max = 0.0;

	for (i = 0; i < brojac; i++) {
		fscanf(f, " %s %s %d", stud[i].ime, stud[i].prezime, &stud[i].bodovi);
	}

	max = (float)stud[0].bodovi;
	for (i = 0; i < brojac; i++) {
		if (stud[i].bodovi >= max)
			max = (float)stud[i].bodovi;
	}

	printf("\n\tIME I PREZIME\t\tBODOVI ABS\tBODOVI REL\n");
	for (i = 0; i < brojac; i++) {
		printf("\t%s %s\t\t %d\t\t %.2f%%\n", stud[i].ime, stud[i].prezime, stud[i].bodovi, ((stud[i].bodovi / max) * 100));
	}

	fclose(f);
}

*/