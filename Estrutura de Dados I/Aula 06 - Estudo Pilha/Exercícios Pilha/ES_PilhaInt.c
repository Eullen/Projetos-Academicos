/*Pilha de Inteiros*/
/*
	Arquivo: ES_PilhaInt.c
	Autor: Eullen Silva Viana
	Date: 27/09/16 16:53
	Descrição: Testa implementações do tipo Pilha - Tópico 3
*/

#include <stdio.h>
#include "ES_PilhaInt.h"

void main(){
	
	 //criando pilha
	 Pilha stack ;
	 criarPilhaVazia(&stack);
	 
	 //inserindo itens na pilha
	 int cursor;
	 for (cursor = 2; cursor< 5; cursor++){
	 	push(&stack,(cursor*cursor));
	 }
	
	//mostrando topo da pilha
	printf("Item do topo: %d ",acessarTopo(stack));
	printf("\n\n");
	
	//verificando e pilha ta cheia
	boolean estado = verificarPilhaCheia(stack);
	printf(" Cheia: %d \n\n",estado);
	
	//retirando da pilha
	pop(&stack);
	//mostrando topo da pilha
	printf("Item do topo: %d ",acessarTopo(stack));
	printf("\n\n");
	
	//estragando pilha
	estragar(&stack,19);
	//mostrando topo da pilha
	printf("Item do topo: %d ",acessarTopo(stack));
	printf("\n\n");
	
	//esvaziando pilha
	esvaziarPilha(&stack);
	//verificando se está vazia
	estado = verificarPilhaVazia(stack);
	printf(" Vazia: %d \n\n",estado);

	
	
	
	
	
}
