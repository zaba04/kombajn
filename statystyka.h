#ifndef STATYSTYKA_H
#define STATYSTYKA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "danex.c"

struct ParametryStatystyczne{
	double srednia;
	double mediana;
	double eos; //estymator odchylenia standardowego
	double max; //wartość maksymalna
	double min; //wartość minimalna
};
struct ParametryStatystyczne AnalizaStatystyczna (const struct DaneX* lista);
#endif
