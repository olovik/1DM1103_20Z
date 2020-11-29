#include "zapis.h"


struct macierz* wczytaj(FILE* fin) {
	struct macierz *m;
    int i, j;
    m = (struct macierz*) malloc(sizeof(struct macierz));
	fscanf(fin, "%d", &m->r);
	fscanf(fin, "%d", &m->c);

    m->tab = (float**) malloc(sizeof(float*) * m->r);
    for (i=0;i<m->r;i++) {
        m->tab[i] = (float*) malloc(sizeof(float) * m->c);
        for (j=0;j< m->c; j++)
            m->tab[i][j] = j+1+i;
    }

	for (i = 0; i < m->r; i++) {
		for (j = 0; j < m->c; j++) {
			fscanf(fin, "%f", &m->tab[i][j]);
		}
	}
    return m;
}

void wypisz(struct macierz m) {
	int i, j;
	printf("[ ");
	for (i = 0; i < m.r; i++) {
		for (j = 0; j < m.c; j++) {
			printf("%5.1f ", m.tab[i][j]);
		}
		if (i < (m.r - 1))
			printf("\n  ");
	}
	printf("]\n");
}

void wypisz2(struct macierz a, struct macierz b, struct macierz x) {
	int i, j;
	printf("[ ");
	for (i = 0; i < a.r; i++) {
		for (j = 0; j < b.c; j++) {
			printf("%5.1f ", x.tab[i][j]);
		}
		if (i < (a.r - 1))
			printf("\n  ");
	}
	printf("]\n");
}

void zapisz(FILE* fin, struct macierz m) {
	int i, j;
	fprintf(fin, "[ ");
	for (i = 0; i < m.r; i++) {
		for (j = 0; j < m.c; j++) {
			fprintf(fin, "%5.1f ", m.tab[i][j]);
		}
		if (i < (m.r - 1))
			fprintf(fin, "\n  ");
	}
	fprintf(fin, "]\n");
	printf("plik wyeksportowano pomyślnie!\n");
}

void zapisz2(FILE* fin, struct macierz a, struct macierz b, struct macierz x) {
	int i, j;
	fprintf(fin, "[ ");
	for (i = 0; i < a.r; i++) {
		for (j = 0; j < b.c; j++) {
			fprintf(fin, "%5.1f ", x.tab[i][j]);
		}
		if (i < (a.r - 1))
			fprintf(fin, "\n  ");
	}
	fprintf(fin, "]\n");
	printf("plik wyeksportowano pomyślnie!\n");
}

void zwolnij(struct macierz *m)
{
    int i, j;
    for (i=0;i<m->r;i++) 
        free( m->tab[i] );
    free(m->tab);
    free(m);

}