/* Testando - Tipo FilaCircular */
/*
  Arquivo: Main_FilaCircularV2.h
  Autor: Eullen Silva Viana
  Date: 06/11/16 13:39
  Descrição: Este programa testa a implementacao o tipo Fila Circular com ponteiro para tipo definido e alocação dinâmica.
*/


#include <stdio.h>
#include "FilaCircular_Vs2.h"

void main(){
	//testando funções
	
	ap_Fila fila;
	int item;
	//------------------------
	fila = criarFilaVazia();
	item = acessarFila(fila);
	printf("\n\n");
	printf("Item: %d ", item);
	//-----------------------------
	bool teste = verificarFilaVazia(fila);
	printf("\n\n");
	printf("\nFila vazia: %d ",teste);
	//-----------------------------
	push(fila,100);
	push(fila,15);
	item = acessarFila(fila);
	printf("\n\n");
	printf("Item inicio fila: %d ", item);
	//-----------------------------------
	pop(fila);
	item = acessarFila(fila);
	printf("\n\n");
	printf("Item do inicio depois do pop: %d ", item);
	
	pop(fila);
	item = acessarFila(fila);
	printf("\n\n");
	printf("Item do inicio depois do pop: %d ", item);
	//-----------------------------------
	push(fila,4545);
	push(fila,100000);
	pop(fila);
	printf("\n\n");
	teste = verificarFilaCheia(fila);
	printf("Fila cheia? %d",teste);
	//---------------------------------
	//ler todos os elementos
	push(fila,4545);
	push(fila,452);
	push(fila,454);
	push(fila,452);
	push(fila,455);
	push(fila,456);
	push(fila,457);
	push(fila,458);
	push(fila,45455);
	push(fila,452);
	teste = verificarFilaCheia(fila);
	printf("\n\nFila cheia? %d",teste);
	teste = verificarFilaVazia(fila);
	while(teste == FALSE){
		item = acessarFila(fila);
		printf("\n\n");
		printf("Item do começo da  FILA: %d ", item);
		pop(fila);
		teste = verificarFilaVazia(fila);
	}
	printf("\n\n\ Tirei todo mundo. Fila vazia? %d",teste);
	//------------------------------------
	push(fila,4545);
	push(fila,452);
	push(fila,454);
	push(fila,452);
	
	esvaziarFila(fila);
	teste = verificarFilaVazia(fila);
	printf("\n\n");
	printf("\nFila vazia depois de esvaziar?: %d ",teste);
	
	//---------------------------------------
	//testando furaFila
//	push(fila,4545);
//	push(fila,452);
//	push(fila,454);
	push(fila,452);
	furaFila(fila,13);
	printf("\n Primeiro : %d Posicao: %d",acessarFila(fila),fila->inicio);
}
