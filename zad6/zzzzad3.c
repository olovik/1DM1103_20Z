#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "zapis.h"
#include "dzialania.h"

int main(int argc, char* argv[]) {
	
	if (strcmp(argv[1], "sum") == 0) {
		if (argc == 4) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			struct macierz *suma;
			suma = dodaj(*mac, *mac2);
			wypisz(*suma);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(suma);
		}

		else if (argc == 5) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			FILE* fin3 = fopen(argv[4], "w");
			struct macierz *suma;
			suma = dodaj(*mac, *mac2);
			zapisz(fin3, *suma);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(suma);
		}
	}
	else if (strcmp(argv[1], "prod") == 0) {
		if (argc == 4) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			struct macierz *ilomac;
			ilomac = mnozenie(*mac, *mac2);
			wypisz(*ilomac);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(ilomac);
		}
		else if (argc == 5) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			FILE* fin3 = fopen(argv[4], "w");
			struct macierz *ilomac;
			ilomac = mnozenie(*mac, *mac2);
			zapisz(fin3,*ilomac);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(ilomac);
		}
	}
	else if (strcmp(argv[1], "subtract") == 0) {
		if (argc == 4) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			struct macierz *roznica;
			roznica = odejmij(*mac, *mac2);
			wypisz(*roznica);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(roznica);
		}
		else if (argc == 5) {
			struct macierz *mac;
			struct macierz *mac2;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin2 = fopen(argv[3], "r");
			mac2=wczytaj(fin2);
			fclose(fin2);

			FILE* fin3 = fopen(argv[4], "w");
			struct macierz *roznica;
			roznica = odejmij(*mac, *mac2);
			zapisz(fin3, *roznica);
			zwolnij(mac);
			zwolnij(mac2);
			zwolnij(roznica);
		}
	}
	else if (strcmp(argv[1], "multiply") == 0) {
		if (argc == 4) {
			struct macierz *mac;
			float a = atof(argv[3]);

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			struct macierz *iloczyn;
			iloczyn = pomnoz(*mac, a);
			wypisz(*iloczyn);
			zwolnij(mac);
			zwolnij(iloczyn);
		}
		else if (argc == 5) {
			struct macierz *mac;
			float a = atof(argv[3]);

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin3 = fopen(argv[4], "w");
			struct macierz *iloczyn;
			iloczyn = pomnoz(*mac, a);
			zapisz(fin3, *iloczyn);
			zwolnij(mac);
			zwolnij(iloczyn);
		}
	}
	else if (strcmp(argv[1], "norm") == 0) {
		if (argc == 3) {
			struct macierz *mac;

			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			norm(*mac);
			float s = norm(*mac);
			printf("%f\n", s);
			zwolnij(mac);
		}
		else if (argc == 4) {
			struct macierz *mac;
			
			FILE* fin = fopen(argv[2], "r");
			mac=wczytaj(fin);
			fclose(fin);

			FILE* fin3 = fopen(argv[3], "w");
			float s = norm(*mac);
			fprintf(fin3, "%f\n", s);
			printf("plik wyeksportowano pomyślnie!\n");
			zwolnij(mac);
		}

	}

	return 0;
}