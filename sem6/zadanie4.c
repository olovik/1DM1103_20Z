#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz(char *szukany_nr, char kod_przed[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod_przed, ile_znalazlem ) == -1) {
            strncpy(kod_przed[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najlatwiejszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod_przed[100][10];
    int ile_przedmiotow;
    char nazwa_przed[100][255];
    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);
    int pozycja;
    float suma_ocen[100];
    int ile_ocen[100];
    float srednia[pozycja];
    int najlepsza=0;
    int najlatwiejszy_przedmiot;
    int najgorsza=100;
    int najtrudniejszy_przedmiot;
    for(int m=0;m<ile_przedmiotow;m++)
    {
        suma_ocen[m]=0;
        ile_ocen[m]=0;
    }
    for(int i=0; i < ile_rekordow; i++) 
        {
            pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow );
            strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);
            ile_ocen[pozycja]++;
            suma_ocen[pozycja] += dane[i].ocena;
        }
    for(int j=0; j<ile_przedmiotow;j++)
    {
        srednia[j]=suma_ocen[j]/ile_ocen[j];
    }

     for (int k=0; k < ile_przedmiotow; k++) 
        {
            if (najlepsza < srednia[k])
                {
                    najlepsza = srednia[k];
                    najlatwiejszy_przedmiot = k;
                }
        }
    
    for (int l=0; l < ile_przedmiotow; l++) 
        {
            if (najgorsza > srednia[l])
                {
                    najgorsza = srednia[l];
                    najtrudniejszy_przedmiot = l;
                }
        }


        printf("Najlepsza średnia: ");
        printf("%s - %s: %3.2f \n", kod_przed[najlatwiejszy_przedmiot],
        nazwa_przed[najlatwiejszy_przedmiot],srednia[najlatwiejszy_przedmiot]);

        printf("Najgorsza średnia: ");
        printf("%s - %s: %3.2f \n", kod_przed[najtrudniejszy_przedmiot],
        nazwa_przed[najtrudniejszy_przedmiot],srednia[najtrudniejszy_przedmiot]);

        
}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    dane == &dane[0];
    ile = wczytaj(dane, argv[1]);
    //wypisz(dane, ile);

    najlatwiejszy_przedmiot(dane, ile);

    return 0;
}