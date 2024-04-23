//
// Created by AkoAk on 15.03.2024.
//
#include "danexy.h"

//przerób na wczytywanie ze strumienia
struct DaneXY *WczytajDane (FILE *stream){
	stream = fopen("ex.txt", "r");\
	int xs = 1;
	int ys = 1; //podstaw na wczytywane z pliku
	
	struct DaneXY *head = (struct DaneXY *)malloc(sizeof(struct DaneXY));
	head->x = xs;
	head->y = ys;
	head->next = NULL;
	
	struct DaneXY *final = NULL;
	final = head;
	
	while(! feof (stdin)){
		struct DaneXY* new = (struct DaneXY*)malloc(sizeof(struct DaneXY));
		new->x = xs;
		new->y = ys;
		new->next = head;
		head = new;
	}
	
	
	fclose(stream);
	return head;
}
void WypiszDane (FILE *stream1, const struct DaneXY *lista){
	stream1 = fopen("ex2.txt", "w");
	while(lista != NULL){
		fprintf(stream1, "%lg\t%lg\n", lista->x, lista->y);
		lista = lista->next;
	}
	fclose(stream1);
}
struct DaneXY *PoliczCalke (const struct DaneXY *lista){
	double xtmp, ytmp;
	double x1, x2;
	double y1, y2;
	double tmp = 0;
	
	struct DaneXY *lista1 = (struct DaneXY *)malloc(sizeof(struct DaneXY));
	x1 = lista->x;
	y1 = lista->y;
	
	struct DaneXY *final = NULL;
	final = lista1;

	while(lista != NULL){
		lista = lista->next;
		x2 = lista->x;
		y2 = lista->y;
		xtmp = (x2+x1)/2;
		ytmp = (y2+y1)*(x2-x1)/2;
		tmp = tmp + ytmp;
		x1 = x2;
		y1 = y2;
		struct DaneXY *new1 = (struct DaneXY *)malloc(sizeof(struct DaneXY));
		new1->x = xtmp;
		new1->y = ytmp; 
		lista1->next = new1;
		lista1 = new1;
	}
	return final;
}
struct DaneXY *PoliczPochodna (const struct DaneXY *lista){
	double xtmp, ytmp;
	double x1,x2;
	double y1,y2;
	double tmp = 0;

	struct DaneXY *lista1 = (struct DaneXY *)malloc(sizeof(struct DaneXY));
	x1 = lista->x;
	y1 = lista->y;

	struct DaneXY *final = NULL;
	final = lista1;

	while(lista != NULL){
		lista = lista->next;
		x2 = lista->x;
		y2 = lista->y;
		xtmp = (x1+x2)/2;
		ytmp = (y2-y1)/(x2-x1);
		lista1->x = x1;//dopracuj tworzenie tej nowej listy
		lista1->y = y1;
	}
	
	return final;
}
struct DaneXY *WygladzDane (const struct DaneXY *lista){
	double x0,x1,x2;
	double y0,y1,y2;
	double xtmp,ytmp;
	double W;
	//nie tworzę tu nigdzie nowej listy -- ogarnij to
	x0 = lista->x;
	y0 = lista->y;
	//wpisanie na x0 i y0 nowej listy
	lista = lista->next;
	x1 = lista->x;
	y1 = lista->y;
	while(lista != NULL){
		lista = lista->next;
		x2 = lista->x;
		y2 = lista->x;
		xtmp = W*(x0+x1+x2);
		ytmp = W*(y0+y1+y2);
		//tutaj wpisanie na x1 i y1 nowej listy
		x0 = x1;
		y0 = y1;
		x1 = x2;
		y1 = y2;
	}
	return lista;
}
void MNK (const struct DaneXY *lista, double *a, double *b){
//----------zrób to w końcu------------//
}
