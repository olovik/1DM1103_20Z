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
    struct _Student *poprz;
} Student;

typedef struct _Przedmiot {
     char * kod;
     char * nazwa;
     char * sem;

     struct _Przedmiot *nast;
     struct _Przedmiot *poprz;
 } Przedmiot;

 typedef struct _Ocena {
     char * nr_albumu;
     char * kod_przedmiotu;

     float ocena;
     char * komentarz;

     struct _Ocena *nast;
     struct _Ocena *poprz;
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

Student * ostatni(Student *glowa);
Student * usun(Student *glowa, Student *el);
Student * najwiekszy(Student *el);
Student * sortuj_rosnaco(Student *glowa);
Student * sortuj_malejaco(Student *glowa);
Student * najmniejszy(Student *el);


void listuj_przedmioty(SBaza *baza);
Przedmiot * ostatni_przed(Przedmiot *glowa);
Przedmiot * usun_przed(Przedmiot *glowa, Przedmiot *el);
Przedmiot * najwiekszy_przed_nazw(Przedmiot *el);
Przedmiot * najmniejszy_przed_nazw(Przedmiot *el);
Przedmiot * sortuj_przed_przez_wybieranie_mal_nazw(Przedmiot *glowa);
Przedmiot * sortuj_przed_przez_wybieranie_ros_nazw(Przedmiot *glowa);
Przedmiot * najwiekszy_przed_kod(Przedmiot *el);
Przedmiot * najmniejszy_przed_kod(Przedmiot *el);
Przedmiot * sortuj_przed_przez_wybieranie_ros_kod(Przedmiot *glowa);

void listuj_oceny(SBaza *baza);
Ocena * filtruj_przedmiot(Ocena * glowa, char *kod, SBaza *baza);
Ocena * ostatnia_ocena(Ocena *glowa);
void filtruj_nazwa(SBaza *baza,char*kod);

#endif