/*Pilha de Char com Ponteiros*/
/*
	Arquivo: ES_PilhaChar.c
	Autor: Eullen Silva Viana
	Date: 28/09/16 09:44
	Descri��o: Testa implementa��es do tipo PilhaChar  com Ponteiros
*/

#include <stdio.h>
#include "PilhaCh.h"

void main(){
	//testandop fun��es
	//criando fun��o
	PilhaCh stack;
	criarPilhaChVazia(&stack);
	
	//colocando itens na pilha
	pushPilhaCh(&stack,'d');
	pushPilhaCh(&stack,'r');
	pushPilhaCh(&stack,'f');	
	
	//imprimindo topo
	unsigned char teste = acessarTopo(&stack);
	printf("\n Topo: %c",teste);
	
	//retirar itens da pilha
	popPilhaCh(&stack);
	popPilhaCh(&stack);
	popPilhaCh(&stack);
	
	//verificar se est� cheia ou vazia
	bool tst = verificarPilhaChVazia(&stack);
	printf("\nVazia: %d",tst);
	tst = verificarPilhaChCheia(&stack);
	printf("\nCheia: %d",tst);
	
	
	
	
	
	
	
}
