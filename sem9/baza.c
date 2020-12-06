#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_course = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_course == NULL)
            glowa = przed;
        else
            last_course->nast = przed;
        last_course = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod, s);

        s = strtok(NULL, ";");
        przed->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa, s);

        s = strtok(NULL, ";");
        przed->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->sem, s);
    }

    return glowa;
}

Ocena * wczytaj_oceny(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_note = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *oce = (Ocena*) malloc(sizeof(Ocena));
        oce->nast = NULL;

        if (last_note == NULL)
            glowa = oce;
        else
            last_note->nast = oce;
        last_note = oce;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        oce->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->nr_albumu, s);

        s = strtok(NULL, ";");
        oce->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        oce -> ocena=atof(s);

         s = strtok(NULL, ";");
        oce->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(oce->komentarz, s);
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) {
    FILE *fin = fopen(nazwa_pliku, "w+");
    Student *szapis = baza -> lista_studentow;
    Przedmiot *pzapis = baza -> lista_przedmiotow;
    Ocena *ozapis = baza -> lista_ocen;
    fprintf(fin, "%d\n", ile_studentow(baza));
    while(szapis!=NULL)
    {
    fprintf(fin, "%s; %s; %s; %s" , szapis->imie, szapis->nazwisko, szapis->nr_albumu, szapis->email);
    szapis=szapis->nast;
    }

    fprintf(fin, "\n %d\n", ile_przedmiotow(baza));

    while(pzapis!=NULL)
    {
    fprintf(fin, "%s; %s; %s" , pzapis->kod, pzapis->nazwa, pzapis->sem);
    pzapis=pzapis->nast;
    }

    fprintf(fin, "%d\n", ile_ocen(baza));

    while(ozapis!=NULL)
    {
    fprintf(fin, "%s; %s; %f; %s" , ozapis->nr_albumu, ozapis->kod_przedmiotu, ozapis->ocena, ozapis->komentarz);
    ozapis=ozapis->nast;
    }

    return NULL;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *s) {
    free(s->kod);
    free(s->nazwa);
    free(s->sem);
    free(s);
}

void zwolnij_ocena(Ocena *s) {
    free(s->nr_albumu);
    free(s->kod_przedmiotu);
    free(s->komentarz);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *s) {
    Przedmiot *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_liste_ocen(Ocena *s) {
    Ocena *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_ocena(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

void dodaj_studenta(SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email){
    Student *nowy=(Student*) malloc(sizeof(Student));
    Student *obecny=NULL;
    nowy->nast=NULL;
    nowy->imie = (char*) malloc(sizeof(char)*(strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc(sizeof(char)*(strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu=(char*) malloc(sizeof(char)*(strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc( sizeof(char)*(strlen(email) + 1));
    strcpy(nowy->email, email);
    obecny=baza->lista_studentow;
    if(ile_studentow(baza)==0)
    {
        baza->lista_studentow=nowy;   
    }
    else{
    for(int i=1;i<ile_studentow(baza);i++)
    {   
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}
}

void dodaj_przedmiot(SBaza *baza, char *kod, char *nazwa, char *sem){
    Przedmiot *nowy=(Przedmiot*) malloc(sizeof(Przedmiot));
    Przedmiot *obecny=NULL;
    nowy->nast=NULL;
    nowy->kod = (char*) malloc(sizeof(char)*(strlen(kod) + 1));
    strcpy(nowy->kod, kod);
    nowy->nazwa = (char*) malloc(sizeof(char)*(strlen(nazwa) + 1));
    strcpy(nowy->nazwa, nazwa);
    nowy->sem=(char*) malloc(sizeof(char)*(strlen(sem) + 1));
    strcpy(nowy->sem, sem);
    obecny=baza->lista_przedmiotow;
    if(ile_przedmiotow(baza)==0)
    {
        baza->lista_przedmiotow=nowy;   
    }
    else{
    for(int i=1;i<ile_przedmiotow(baza);i++)
    {   
        obecny=obecny->nast;
    }
    obecny->nast=nowy;}
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * przed = baza->lista_przedmiotow;
    while (przed != NULL) {
        n++;
        przed = przed->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}
