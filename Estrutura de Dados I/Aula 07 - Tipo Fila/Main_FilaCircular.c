/* Testando - Tipo FilaCircular */
/*
  Arquivo: Main_FilaCircular.h
  Autor: Eullen Silva Viana
  Date: 26/10/16 09:11
  Descrição: Este programa testa a implementacao o tipo Fila Circular.
*/


#include <stdio.h>
#include "FilaCircular.h"

void main(){
	//testando funções
	
	FilaCircular fila;
	int item;
	//------------------------
	criarFilaVazia(&fila);
	item = acessarInicio(&fila);
	printf("\n\n");
	printf("Item: %d ", item);
	//-----------------------------
	bool teste = verificarFilaVazia(&fila);
	printf("\n\n");
	printf("\nFila vazia: %d ",teste);
	//-----------------------------
	push(&fila,100);
	push(&fila,15);
	item = acessarInicio(&fila);
	printf("\n\n");
	printf("Item: %d ", item);
	//-----------------------------------
	pop(&fila);
	item = acessarInicio(&fila);
	printf("\n\n");
	printf("Item: %d ", item);
	
	pop(&fila);
	item = acessarInicio(&fila);
	printf("\n\n");
	printf("Item: %d ", item);
	//-----------------------------------
	push(&fila,4545);
	push(&fila,452);
	pop(&fila);
	printf("\n\n");
	teste = verificarFilaCheia(&fila);
	printf("Fila cheia? %d",teste);
	//---------------------------------
	//ler todos os elementos
	push(&fila,4545);
	push(&fila,452);
	push(&fila,454);
	push(&fila,452);
	push(&fila,455);
	push(&fila,456);
	push(&fila,457);
	push(&fila,458);
	push(&fila,45455);
	push(&fila,452);
	
	teste = verificarFilaVazia(&fila);
	while(teste == FALSE){
		item = acessarInicio(&fila);
		printf("\n\n");
		printf("Item: %d ", item);
		pop(&fila);
		teste = verificarFilaVazia(&fila);
	}

	//------------------------------------
	push(&fila,4545);
	push(&fila,452);
	push(&fila,454);
	push(&fila,452);
	
	esvaziarFila(&fila);
	teste = verificarFilaVazia(&fila);
	printf("\n\n");
	printf("\nFila vazia: %d ",teste);
	
	//---------------------------------------
}
