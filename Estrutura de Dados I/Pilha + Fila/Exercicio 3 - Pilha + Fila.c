
#include<stdio.h>
#include "Exercicio 3 - Pilha + Fila.h"


main(){
	
// Exercicio a)------------------
	FilaCircular fila;
	criarFilaVazia(&fila);
	push(&fila,'A');
	push(&fila,'B');
	push(&fila,'C');
	
	inverterFila(&fila);
	//mostrar Fila Depois
	while(fila.inicio != SINALFILA){
		printf(" Item : %c ",acessarInicio(&fila));
		pop(&fila);
	}
//--------------------------------------------------------------
	//Exercicio B
	printf(" \n\n");
	PilhaCh pilha;
	criarPilhaChVazia(&pilha);
	pushPilhaCh(&pilha,'A');
	pushPilhaCh(&pilha,'B');
	pushPilhaCh(&pilha,'C');
	inverterPilha(&pilha);
	//imprimindo pilha invertida: A - B - C
	while(pilha.topo != SINAL){
		printf(" Item : %c ",acessarTopo(&pilha));
		popPilhaCh(&pilha);
	}
}


