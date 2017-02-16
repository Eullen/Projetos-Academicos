/*Pilha de Char com Ponteiros*/
/*
	Arquivo: ES_PilhaChar.c
	Autor: Eullen Silva Viana
	Date: 28/09/16 09:44
	Descrição: Testa implementações do tipo PilhaChar  com Ponteiros
*/

#include <stdio.h>
#include "PilhaCh.h"

void main(){
	//testandop funções
	//criando função
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
	
	//verificar se está cheia ou vazia
	bool tst = verificarPilhaChVazia(&stack);
	printf("\nVazia: %d",tst);
	tst = verificarPilhaChCheia(&stack);
	printf("\nCheia: %d",tst);
	
	
	
	
	
	
	
}
