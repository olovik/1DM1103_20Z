#ifndef _dzialania_h
#define _dzialania_h
#include "zapis.h"

struct macierz* dodaj(struct macierz a, struct macierz b);

struct macierz* odejmij(struct macierz a, struct macierz b);

struct macierz* mnozenie(struct macierz a, struct macierz b);

struct macierz* pomnoz(struct macierz m, float a);

float norm(struct macierz m);





#endif
