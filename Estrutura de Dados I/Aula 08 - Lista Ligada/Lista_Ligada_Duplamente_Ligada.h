/* Tipo Lista Duplamente Ligada*/
/*
  Arquivo: Lista_Ligada_Duplamente_Ligada.h
  Autor: Eullen Silva Viana
  Date: 11/11/16 16:49
  Descrição: Esta biblioteca implementa as funções do tipo LIsta duplamente ligada
*/

#include "Booleano.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	int item;
	struct Celula *next;
	struct Celula *previous;
}Celula;

typedef struct {
	Celula *inicio;
	Celula *fim;
	int tamanho;
}Lista;

//interfaces
Lista criarListaVazia();
Lista inserirNoInicio(Lista *,int);
Lista mostrarTodos (Lista *);
Lista mostrarKPrimeiros(Lista *, int);
Lista InserirEspec ( Lista *, int, int);
int buscar(Lista listinha,int elemento);
//Implementações
Lista criarListaVazia(){
	
	Lista ld;
	ld.inicio = NULL;
	ld.fim = NULL;
	ld.tamanho = 0;
	return ld;

}
Lista inserirNoInicio(Lista *ld,int elemento){
	Celula *novoItem;
	novoItem = (Celula*)malloc(sizeof(Celula));
	novoItem->item = elemento;
	novoItem->next = ld->inicio;
	novoItem->previous = NULL;
	//se lista vazia
	if ( ld->tamanho == 0){
		//atualiza o fim tbm
		ld->fim = novoItem;	
	}else{
		//nao é vazia, atualiza posterior
		ld->inicio->previous = novoItem;		
	}
	ld->inicio = novoItem;
	ld->tamanho += 1;

}
Lista mostrarTodos (Lista *ld){
	Celula *ap;
	ap = ld->inicio;
		
	if(ap==NULL){
		printf("\nVazia!\n");
	}else{
		//varrendo lista
		do{
			printf(" Item: %d \n",ap->item);
			ap=ap->next;
		}while(ap!=NULL);
	}
}
Lista mostrarKPrimeiros(Lista *ld, int k){
	//verificando vallidade de k
	if((k>=1)&&(k<=ld->tamanho)){
		Celula *ap;
		int cont;
		ap = ld->inicio;
		cont = 1; 
		//primeiro item
		printf(" Item: %d \n",ap->item);
		//demais itens
		while(cont!=k){
			ap = ap->next;
			cont++;
			printf(" Item: %d \n",ap->item);
		}
	}
}
Lista InserirEspec ( Lista *ld, int posInsercao, int newItem){
	//validando posInsercao
	if ((posInsercao>=1)&&(posInsercao<=ld->tamanho+1)){
		Celula *novo;
		novo = (Celula *)malloc(sizeof(Celula));
		novo->item = newItem;
		//verificando posição		
		Celula *ap;	int cursor;
		ap = ld->inicio; cursor=1;
		while ( ap!=NULL && cursor!=posInsercao){
			ap=ap->next;
			cursor++;
		}
		novo->next = ap;
		if (cursor == 1){ // inserir no começo
			if ( ld->tamanho == 0){
				ld->fim = novo;
			}else{
				ap->previous = novo;				
			}
			ld->inicio = novo;
			novo->previous = NULL;		
		}else{ 
			if (cursor == ld->tamanho+1 ){//inserindo no fim
				novo->previous = ld->fim;
				ld->fim = novo;
			}else{ //inserindo no meio
				novo->previous = ap->previous;
				ap->previous = novo;
			}
			//inserir no meio
			novo->previous->next = novo;
		}
		ld->tamanho++;
	}
}

int buscar(Lista ld,int elemento){
	int pos, cursor;
	Celula *ap;
	pos=0;
	if(ld.inicio !=NULL){//lista não é vazia
		ap = ld.inicio; cursor = 1;
		do{//laço para varrer lista até encontrar ou acabar
			if(ap->item == elemento){
				pos = cursor;
			}else{
				cursor++;
				ap = ap->next;
			}
		}while((pos==0)&&(ap!=NULL));
		
	}
	return pos;
}

