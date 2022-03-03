#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Fila {
	int capacidade;
	float *elementos;
	int primeiro ;
	int ultimo;
	int nItens;
};

void criarFila( struct Fila *f, int c ) {
	f->capacidade = c;
	f->elementos = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}

void inserir (struct Fila *f, int v){
	if (f->ultimo = f->capacidade -1)
	f->ultimo-1;	
	
	f->ultimo++;
	f->elementos[f->ultimo] = v; //todos que entram ficam no final da fila 
	f->nItens++;
}

int remove (struct Fila *f){
	int temp = f->elementos[f->primeiro++];// o primeiro sai e o proximo vira o primeiro
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
		
	f->nItens--;
	return temp;	
}

int estaVazia( struct Fila *f ) { 
	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna se a fila esta cheia
	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){ // faz a repeticao que passa no array

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->elementos[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n");

}

int main(){
	
	int capa, opcao;
	float valor;
	struct Fila umaFila;
	
	//criacao da fila
	printf("\n Quantos devem caber na fila?");
	scanf("%d",&capa);
	criarFila(&umaFila, capa); 
	
	//menu
	while ( 1 ) {
		
		printf("\n1- Colocar alguem na fila\n2-Tirar alguem da fila\n3- Mostrar quem esta na fila\n 0- Sair\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			
				case 1:
					if(estaCheia(&umaFila)){
						printf("\nNao cabe mais ninguem na fila");
					}
					else{
							printf("\nDigite o numero de quem sera inserido na fila: ");
							scanf("%f", &valor);
							inserir(&umaFila, valor);	
						}
						break;
				
		
				case 2: 
					if(estaVazia(&umaFila)){
						printf("\nNao tem ninguem na fila!");
					}
					else{
						valor = remove(&umaFila);
						printf("\n%1f Saiu da fila o", valor);
					}
					break;
					
				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nNao tem ninguem na fila!!\n\n");

					}
					else {

						printf("\nLista da fila: ");
						mostrarFila(&umaFila);
					}
					break;	
			}
		
	}

	
	
	return 0;
}
