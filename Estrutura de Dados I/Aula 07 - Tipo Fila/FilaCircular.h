/* Tipo FilaCircular */
/*
  Arquivo: FilaCircular.h
  Autor: Eullen Silva Viana
  Date: 25/10/16 17:16
  Descrição: Este programa implementa o tipo Fila Circular.
*/

#include "Booleano.h"
#define SINAL -1
#define Fantasma -999	
#define MaxFila 8
typedef struct{
	int inicio;
	int fim;
	int item[MaxFila];
}FilaCircular;

//Interfaces
void criarFilaVazia (FilaCircular *);
int acessarInicio(FilaCircular *);
bool verificarFilaVazia (FilaCircular *);
bool verificarFilaCheia (FilaCircular *);
void push(FilaCircular *, int);
void pop(FilaCircular *);
void esvaziarFila(FilaCircular *);


//implementações
void criarFilaVazia (FilaCircular *fila){
	fila->inicio = SINAL;
	fila->fim = SINAL;
}
int acessarInicio(FilaCircular *fila){
	int item;
	if (fila->inicio == SINAL){
		item = Fantasma;
	}else{
		item = fila->item[fila->inicio];
	}
	return item;
}
bool verificarFilaVazia (FilaCircular *fila){
	bool vazia = FALSE;
	if (fila->inicio == SINAL){
		vazia=TRUE;
	}
	return vazia;
}
bool verificarFilaCheia (FilaCircular *fila){
	bool cheia = FALSE;
	if (((fila->fim+1)%MaxFila)==fila->inicio){
		cheia = TRUE;
	}
	return cheia;
}
void push(FilaCircular *fila, int newItem){
	//verificando se não tá cheia
	if (((fila->fim+1)%MaxFila)!=fila->inicio){
		//colocando item
		fila->item[(fila->fim+1)%MaxFila] = newItem;
		fila->fim = (fila->fim+1)%MaxFila; //pq sinal eh -1 posso apenas somar 
		//atualizando se fila estava vazia
		if(fila->inicio == SINAL){
			fila->inicio = fila->fim;
		} 
	}	
}
void pop(FilaCircular *fila){
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
void esvaziarFila(FilaCircular *fila){
	fila->inicio = SINAL;
	fila->fim = SINAL;
}


