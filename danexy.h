//
// Created by AkoAk on 15.03.2024.
//

#ifndef DaneXY_H
#define DANEXY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct DaneXY{
    double x;
    double y;
    struct DaneXY *next;
	struct DaneXY *previous;
};
struct DaneXY *WczytajDane (FILE *stream);
void WypiszDane (FILE *stream, const struct DaneXY *lista);
struct DaneXY *PoliczCalke (const struct DaneXY *lista);
struct DaneXY *PoliczPochodna (const struct DaneXY *lista);
struct DaneXY *WygladzDane (const struct DaneXY *lista);
void MNK (const struct DaneXY *lista, double *a, double *b);
#endif 
