/* Tipo FilaCircular Dinâmico */
/*
  Arquivo: FilaCircular_Vs2.h
  Autor: Eullen Silva Viana
  Date: 26/10/16 09:55
  Descrição: Este programa implementa o tipo Fila Circular com ponteiro para tipo criado, com o objetivo de facilitar a "vida" do usuário.
*/

#include "Booleano.h"
#define SINAL -1
#define Fantasma -999	
#define MaxFila 8
typedef struct{
	int inicio;
	int fim;
	int item[MaxFila];
}c_Fila;
typedef c_Fila *ap_Fila;

//interface
ap_Fila criarFilaVazia();
int acessarFila(ap_Fila);
bool verificarFilaVazia(ap_Fila);
bool verificarFilaCheia(ap_Fila);
void push(ap_Fila,int);
void pop(ap_Fila);
void esvaziarFila(ap_Fila);

//implementacoes
ap_Fila criarFilaVazia(){
	
	ap_Fila fila;
	fila = (c_Fila*) malloc (sizeof(c_Fila));
	fila->inicio = SINAL;
	fila->fim = SINAL;
	return fila;
}

int acessarFila(ap_Fila fila){
	int item;
	if(fila->inicio == SINAL){
		//fila vazia
		item = Fantasma;
	}else{
		item = fila->item[fila->inicio];
	}
	
	return item;
}

bool verificarFilaVazia(ap_Fila fila){
	bool vazia;
	if(fila->inicio == SINAL){
		vazia = TRUE;
	}else{
		vazia = FALSE;
	}
	return vazia;
}

bool verificarFilaCheia(ap_Fila fila){
	bool cheia;
	if((fila->fim+1)%MaxFila == fila->inicio){
		cheia = TRUE;
	}else{
		cheia = FALSE;
	}
	
	return cheia;
}

void push(ap_Fila fila,int item){
	//verificando se não tá cheia
	if (((fila->fim+1)%MaxFila)!=fila->inicio){
		//colocando item
		fila->item[(fila->fim+1)%MaxFila] = item;
		fila->fim = (fila->fim+1)%MaxFila; //pq sinal eh -1 posso apenas somar 
		//atualizando se fila estava vazia
		if(fila->inicio == SINAL){
			fila->inicio = fila->fim;
		} 
	}	
}
void pop(ap_Fila fila){
	//verificando se não é vazia
	if(fila->inicio != SINAL){
		//verificando se vai esvaziar
		if (fila->inicio == fila->fim){
			fila->fim = SINAL;
			fila->inicio = SINAL;
		}else{
			//removendo item
			fila->inicio = ((fila->inicio+1)%MaxFila);				
		}
	}
}

void esvaziarFila(ap_Fila fila){
	fila->inicio = SINAL;
	fila->fim = SINAL;
}

void furaFila (ap_Fila fila, int newItem){
	//acrescenta um elemento no começo da fila
	if ((fila->fim+1)%MaxFila != fila->inicio ){ //fila não está cheia
		int pos;
		pos = fila->inicio-1;
		if ( pos == SINAL){ //fila começa no indice 0
			pos = MaxFila-1; 
		}
		fila->inicio = pos;
		fila->item[pos] = newItem;
	}	
}


