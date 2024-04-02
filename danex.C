#include "danex.h"


//przerób by final był wskaźnikiem na początek listy
struct DaneX *WczytajDaneX (FILE *strumien){
	strumien = fopen("ex.txt", "r");
	struct DaneX *head = NULL;
	struct DaneX *tail = NULL;
		if(head){
			int number = 10;
			head->x = number;
			head->previous = head->next = NULL;
			tail = head;
		}
	while(! feof (stdin)){
		struct DaneX *new = (struct DaneX *)malloc(sizeof(struct DaneX));
		scanf("%lg", &new->x);
		if(tail){
			tail->next = new;
			new->previous = tail;
			tail = new;
		}else{
			head = new;
			tail = new;
			head->previous = NULL;
		}
	}
	tail->next = NULL;
	return head;//mamy stworzony pierwszy element listy
	fclose(strumien);
}
void WypiszDaneX (FILE *strumien1, const struct DaneX *lista){
	strumien1 = fopen("ex3.txt", "w");
	while(! feof (stdin)){
		fprintf(strumien1, "%lg/n", lista->x);
		lista = lista->next;
	}
	fclose(strumien1);
}
struct DaneX *DFT (const struct DaneX *lista){//doczytaj to lepiej bo bardzo palcem po wodzie to pisane
	double A; //wartość transformaty
	double N = 103; //jakoś sprawdzić długość pliku
	struct DaneX *list = (struct DaneX *)malloc(sizeof(struct DaneX)); //ponieważ jak nie dałam to krzyczy z returnem wymyśl co z tym zrobić
	for(int i = 1; i < N; i++){
		struct DaneX *list = (struct DaneX *)malloc(sizeof(struct DaneX));
		for(int j = 1; j < N; j++){
			A = 0;
			A = A + (lista->x*exp(-j*i*2*3.14*I/N));
		}
		list->x = A;
		list = list->next;
	}
	return list;
}
struct DaneXY *Sortowanie (const struct DaneX *lista){
	
	
	return NULL;
}
