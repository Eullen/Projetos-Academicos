/* Tipo FilaCircular */
/*
  Arquivo: FilaCircular.h
  Autor: Eullen Silva Viana
  Date: 25/10/16 17:16
  Descrição: Este programa implementa o tipo Fila Circular.
*/

#include "Booleano.h"
#define SINALFILA -1
#define Fantasma '@'	
#define MaxFila 8
typedef struct{
	int inicio;
	int fim;
	unsigned char item[MaxFila];
}FilaCircular;

//Interfaces
void criarFilaVazia (FilaCircular *);
unsigned char acessarInicio(FilaCircular *);
bool verificarFilaVazia (FilaCircular *);
bool verificarFilaCheia (FilaCircular *);
void push(FilaCircular *, unsigned char);
void pop(FilaCircular *);
void esvaziarFila(FilaCircular *);


//implementações
void criarFilaVazia (FilaCircular *fila){
	fila->inicio = SINALFILA;
	fila->fim = SINALFILA;
}
unsigned char acessarInicio(FilaCircular *fila){
	unsigned char item;
	if (fila->inicio == SINALFILA){
		item = Fantasma;
	}else{
		item = fila->item[fila->inicio];
	}
	return item;
}
bool verificarFilaVazia (FilaCircular *fila){
	bool vazia = FALSE;
	if (fila->inicio == SINALFILA){
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
void push(FilaCircular *fila, unsigned char newItem){
	//verificando se não tá cheia
	if (((fila->fim+1)%MaxFila)!=fila->inicio){
		//colocando item
		fila->item[(fila->fim+1)%MaxFila] = newItem;
		fila->fim = (fila->fim+1)%MaxFila; //pq sinal eh -1 posso apenas somar 
		//atualizando se fila estava vazia
		if(fila->inicio == SINALFILA){
			fila->inicio = fila->fim;
		} 
	}
		
}
void pop(FilaCircular *fila){
	//verificando se não é vazia
	if(fila->inicio != SINALFILA){
		//verificando se vai esvaziar
		if (fila->inicio == fila->fim){
			fila->fim = SINALFILA;
			fila->inicio = SINALFILA;
		}else{
			//removendo item
			fila->inicio = ((fila->inicio+1)%MaxFila);				
		}
	}
	
}
void esvaziarFila(FilaCircular *fila){
	fila->inicio = SINALFILA;
	fila->fim = SINALFILA;
}


