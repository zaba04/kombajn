#include "danex.h"


//przerób by final był wskaźnikiem na początek listy, chyba ogarnięte
struct DaneX *WczytajDaneX (FILE *strumien){
	strumien = fopen("ex.txt", "r");
	int xs = 2; //zmień na wczytywane z pliku
	
	struct DaneX *head = (struct DaneX*)malloc(sizeof(struct DaneX));
	head->x = xs;
	head->next = NULL;

	struct DaneX *final = NULL;
        final = head;

	while(! feof (stdin)){
		struct DaneX *new1 = (struct DaneX*)malloc(sizeof(struct DaneX));
		new1->x = xs;
		new1->next = head;
		head = new1;
	}
	
	return final;
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
	const struct DaneX *listh = NULL;
	listh = lista;
	while (lista != NULL){
		N++;
		lista = lista->next;
	}	
        double tmp2[1];
	for(int i = 0; i < N; i++){
		double tmp3[i+1];
		for(int j = 0; j < i; j++){
			tmp3[j] = tmp2[j];
		}
		tmp3[i] = listh->x;
		listh->next;
	}
	int n = (int)N;
	double Xk[n];
	struct DaneX *flist = (struct DaneX *)malloc(sizeof(struct DaneX));
	for(int i = 0; i < N; i++){//k ze wzorów
		Xk[n] = 0;
		if(i == 1){
			for(int j = 0; j < N; j++){//n ze wzorów
				Xk[i] = Xk[i]+sqrt(((tmp2[j]*tmp2[j]*cos(2*3.14*i*j/N)*cos(2*3.14*i*j/N))-(tmp2[j]*tmp2[j]*sin(2*3.14*i*j/N)*sin(2*3.14*i*j/N))));
			}
			flist->x = Xk[i];
			flist->next = NULL;
		}
		for(int j = 0; j < N; j++){//n ze wzorów
			Xk[i] = Xk[i]+sqrt(((tmp2[j]*tmp2[j]*cos(2*3.14*i*j/N)*cos(2*3.14*i*j/N))-(tmp2[j]*tmp2[j]*sin(2*3.14*i*j/N)*sin(2*3.14*i*j/N))));
		}
		struct DaneX *new2 = (struct DaneX *)malloc(sizeof(struct DaneX));
		flist->next = new2;
		new2->x = Xk[i];
		new2->next = NULL;
		flist = new2;		
	}
	return flist;
}
struct DaneX* Sortowanie (const struct DaneX *lista){
    int count = 0;
    while (lista != NULL) {
        count++;
        lista = lista->next;
    }
    double tmp1[1];
	for(int i = 0; i < count; i++){
		double tmp2[i+1];
		for(int j = 0; j < i; j++){
			tmp2[j] = tmp1[j];
		}
		tmp1[i] = lista->x;
		lista->next;
	}
	for(int i = 0; i < count; i++){
		if(tmp1[i]>tmp1[i+1]){
			int tmp= tmp1[i];
			tmp1[i] = tmp1[i+1];
			tmp1[i+1] = tmp;
		}
	}
	struct DaneX *head1 = NULL;
	head1 = (struct DaneX*)malloc(sizeof(struct DaneX));
	head1->x = tmp1[0];
	head1->next = NULL;
	
	for(int i = 0; i < count; i++){
		struct DaneX* new3 = (struct DaneX*)malloc(sizeof(struct DaneX));
		new3->x = tmp1[i+1];
		new3->next = head1;
		head1 = new3;
	}
	struct DaneX *head2 = NULL;
	head2 = head1;
	return head2;//bo ma być struct sprawdź w zadaniu od Pietrzaka
}
