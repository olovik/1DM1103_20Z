#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
     char * kod;
     char * nazwa;
     char * sem;

     struct _Przedmiot *nast;
 } Przedmiot;

 typedef struct _Ocena {
     char * nr_albumu;
     char * kod_przedmiotu;

     float ocena;
     char * komentarz;

     struct _Ocena *nast;
 } Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;



SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);

void dodaj_studenta(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);

int ile_ocen(SBaza *baza);

void zwolnij_liste_ocen(Ocena *s);
void zwolnij_liste_przedmiotow(Przedmiot *s);
Przedmiot * wczytaj_przedmioty(FILE *fin);
Ocena * wczytaj_oceny(FILE *fin);
void dodaj_przedmiot(SBaza *baza, char *kod, char *nazwa, char *sem);

#endif