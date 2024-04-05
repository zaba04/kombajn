#include "danex.h"


//przerób by final był wskaźnikiem na początek listy
struct DaneX *WczytajDaneX (FILE *strumien){
	strumien = fopen("ex.txt", "r");
	int xs = 2; //zmień na wczytywane z pliku
	
	struct DaneX *head = NULL;
	*head = (struct DaneX*)malloc(sizeof(struct DaneX));
	head->x = xs;
	head->next = NULL;
	
	while(! feof (stdin)){
		struct DaneX* new = (struct DaneX*)malloc(sizeof(struct DaneX));
		new->x = xs;
		new->next = *head;
		*head = new;
	}
	return head;
	fclose(strumien);
}
void WypiszDaneX (FILE *strumien1, const struct DaneX *lista){
	strumien1 = fopen("ex3.txt", "w");
	while(lista != NULL){
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
    int count = 0;
    while (lista != NULL) {
        count++;
        lista = lista->next;
    }
    struct DaneX tmp1[1];
	for(int i = 0; i < count; i++){
		struct DaneX tmp2[i+1];
		for(int j = 0; j < i; j++){
			tmp2[j] = tmp1[j];
		}
		tmp1[i] = lista->x;
		lista->next;
	}
	for(int i = 0, i < count, i++){
		if(tmp1[i]>tmp[i+1]){
			int tmp = tmp1[i];
			tmp1[1] = tmp[i+1];
			tmp1[i+1] = tmp;
		}
	}
	struct DaneX *head1 = NULL;
	*head1 = (struct DaneX*)malloc(sizeof(struct DaneX));
	head1->x = tmp1[0];
	head1->next = NULL;
	
	for(int i = 0; i < count; i++){
		struct DaneX* new = (struct DaneX*)malloc(sizeof(struct DaneX));
		new->x = tmp[i+1];
		new->next = *head;
		*head = new;
	}
	return head;
}