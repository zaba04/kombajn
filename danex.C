#include "danex.h"


//przerób by final był wskaźnikiem na początek listy
struct DaneX *WczytajDaneX (FILE *strumien){
	strumien = fopen("ex.txt", "r");
	int xs = 2; //zmień na wczytywane z pliku
	
	struct DaneX *head = (struct DaneX*)malloc(sizeof(struct DaneX));
	head->x = xs;
	head->next = NULL;
	
	while(! feof (stdin)){
		struct DaneX *new = (struct DaneX*)malloc(sizeof(struct DaneX));
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
struct DaneX *DFT (const struct DaneX *lista){
	double N = 0;
	struct DaneX *listh = NULL;
	listh = lista;
	while (lista != NULL){
		N++;
		lista = lista->next;
	}	
        struct DaneX tmp2[1];
	for(int i = 0; i < count; i++){
		struct DaneX tmp3[i+1];
		for(int j = 0; j < i; j++){
			tmp3[j] = tmp2[j];
		}
		tmp3[i] = listh->x;
		listh->next;
	}
	double Xk[N];
	struct DaneX *flist = (struct DaneX *)malloc(sizeof(struct DaneX));
	for(int i = 0; i < N; i++){//k ze wzorów
		Xk[N] = 0;
		if(i == 1){
			for(int j = 0; j < N; j++){//n ze wzorów
				Xk[i] = Xk[i]+sqrt(((tmp3[j]*tmp3[j]*cos(2*3.14*i*j/N)*cos(2*3.14*I*J/N))-(tmp3[j]*tmp3[j]*sin(2*3.14*i*j/N)*sin(2*3.14*i*j/N))));
			}
			flist->x = Xk[i];
			flist->next = NULL;
		}
		for(int j = 0; j < N; j++){//n ze wzorów
			Xk[i] = Xk[i]+sqrt(((tmp3[j]*tmp3[j]*cos(2*3.14*i*j/N)*cos(2*3.14*I*J/N))-(tmp3[j]*tmp3[j]*sin(2*3.14*i*j/N)*sin(2*3.14*i*j/N))));
		}
		struct DaneX *new = (struct DaneX *)malloc(sizeof(struct DaneX));
		flist->next = new;
		new->x = Xk[i];
		new->next = NULL;
		flist = new;		
	}
	return flist;
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
