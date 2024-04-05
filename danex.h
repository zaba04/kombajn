#ifndef DANEX_H
#define DANEX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

struct DaneX{
    double x;
    struct DaneX *next;
};
struct DaneX *WczytajDaneX (FILE *strumien);
void WypiszDaneX (FILE *strumien, const struct DaneX *lista);
struct DaneX *DFT (const struct DaneX *lista);
struct DaneXY *Sortowanie (const struct DaneX *lista);

#endif