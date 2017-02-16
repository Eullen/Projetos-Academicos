/*Pilha de Char sem Ponteiros*/
/*
	Arquivo: ES_PilhaChar.c
	Autor: Eullen Silva Viana
	Date: 28/09/16 09:44
	Descri��o: Testa implementa��es do tipo PilhaChar  
*/

#include <stdio.h>
#include "TipoPilhaCh.h"

void main(){
	//testandop fun��es
	//criando fun��o
	PilhaCh stack = criarPilhaChVazia();
	
	//colocando itens na pilha
	stack = pushPilhaCh(stack,'d');
	stack = pushPilhaCh(stack,'r');
	stack = pushPilhaCh(stack,'#');	
	
	//imprimindo topo
	unsigned char teste = acessarTopo(stack);
	printf("\n Topo: %c",teste);
	
	//retirar itens da pilha
	stack = popPilhaCh(stack);
	stack = popPilhaCh(stack);
	stack = popPilhaCh(stack);
	
	//verificar se est� cheia ou vazia
	bool tst = verificarPilhaChVazia(stack);
	printf("\nVazia: %d",tst);
	tst = verificarPilhaChCheia(stack);
	printf("\nCheia: %d",tst);
	printf("\n Topo: %c",acessarTopo(stack));
	
	
	
	
	
	
	
}
