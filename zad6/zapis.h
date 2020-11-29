#ifndef _zapis_h
#define _zapis_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct macierz {
	int r;
	int c;
	float **tab;
};

struct macierz* wczytaj(FILE* fin);

void wypisz(struct macierz m);

void wypisz2(struct macierz a, struct macierz b, struct macierz x);

void zapisz(FILE* fin, struct macierz m);

void zapisz2(FILE* fin, struct macierz a, struct macierz b, struct macierz x);

void zwolnij(struct macierz *m);


#endif