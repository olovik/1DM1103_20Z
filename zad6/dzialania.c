#include "dzialania.h"


struct macierz* dodaj(struct macierz a, struct macierz b)
{
    	int i, j;
	struct macierz *suma;
    suma = (struct macierz*) malloc(sizeof(struct macierz));
    suma->r=a.r;
    suma->c=a.c;
    suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for (i=0;i<suma->r;i++) {
        suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
        for (j=0;j< suma->c; j++)
            suma->tab[i][j] = j+1+i;
    }

	float s;
	if ((a.r != b.r) || (a.c != b.c)) {
		printf("Obie macierze muszą być tego samego rozmiaru!\n");
	}
	else {
		for (i = 0; i < a.r; i++) {
			for (j = 0; j < a.c; j++) {
				s = 0;
				s += a.tab[i][j] + b.tab[i][j];
				suma->tab[i][j] = s;
			}
		}		
	}
	return suma;
}

struct macierz* odejmij(struct macierz a, struct macierz b)
{
    	int i, j;
    struct macierz *roznica;
    roznica = (struct macierz*) malloc(sizeof(struct macierz));
    roznica->r=a.r;
    roznica->c=a.c;
    roznica->tab = (float**) malloc(sizeof(float*) * roznica->r);
    for (i=0;i<roznica->r;i++) {
        roznica->tab[i] = (float*) malloc(sizeof(float) * roznica->c);
        for (j=0;j< roznica->c; j++)
            roznica->tab[i][j] = j+1+i;
    }


	float s;
	if ((a.r != b.r) || (a.c != b.c)) {
		printf("Obie macierze muszą być tego samego rozmiaru!\n");
	}
	else {
		for (i = 0; i < a.r; i++) {
			for (j = 0; j < a.c; j++) {
				s = 0;
				s += a.tab[i][j] - b.tab[i][j];
				roznica->tab[i][j] = s;
			}
		}
	}
	return roznica;
}


struct macierz* mnozenie(struct macierz a, struct macierz b)
{
    	int i, j;
    struct macierz *ilomac;
    ilomac = (struct macierz*) malloc(sizeof(struct macierz));
    ilomac->r=a.r;
    ilomac->c=b.c;
    ilomac->tab = (float**) malloc(sizeof(float*) * ilomac->r);
    for (i=0;i<ilomac->r;i++) {
        ilomac->tab[i] = (float*) malloc(sizeof(float) * ilomac->c);
        for (j=0;j< ilomac->c; j++)
            ilomac->tab[i][j] = j+1+i;
    }


	for (int w = 0; w < a.r; w++)
	{
		for (int k = 0; k < b.c; k++)
		{
			float ilo = 0;
			for (int x = 0; x < a.c; x++)
			{
				ilo += (a.tab[w][x] * b.tab[x][k]);
			}
			ilomac->tab[w][k] = ilo;
		}
	}
	return ilomac;
}

struct macierz* pomnoz(struct macierz m, float a)
{
    int i, j;
    struct macierz *iloczyn;
    iloczyn = (struct macierz*) malloc(sizeof(struct macierz));
    iloczyn->r=m.r;
    iloczyn->c=m.c;
    iloczyn->tab = (float**) malloc(sizeof(float*) * iloczyn->r);
    for (i=0;i<iloczyn->r;i++) {
        iloczyn->tab[i] = (float*) malloc(sizeof(float) * iloczyn->c);
        for (j=0;j< iloczyn->c; j++)
            iloczyn->tab[i][j] = j+1+i;
    }


	float s;
	for (int i = 0; i < m.r; i++) {
		for (int j = 0; j < m.c; j++) {
			s = 0;
			s += m.tab[i][j] * a;
			iloczyn->tab[i][j] = s;
		}
	}
	return iloczyn;
}

float norm(struct macierz m) {
	float s = 0;
	int i, j;

	for (i = 0; i < m.r; i++) {
		for (j = 0; j < m.c; j++) {
			s += m.tab[i][j] * m.tab[i][j];
		}
	}
	return sqrt(s);
};

