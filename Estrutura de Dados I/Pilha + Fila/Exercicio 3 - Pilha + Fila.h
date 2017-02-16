/* Tipo FilaCircular + Tipo Pilha  ambos do tipo char para fins did�ticos*/
/*
  Arquivo: Exercicio 3.h
  Autor: Eullen Silva Viana
  Date: 10/11/16 16:49
  Descri��o: Este programa implementa a biblioteca para a resolu��o dos seguintes exercicios:
  	a) Implementar uma fun��o para inverter a ordem dos elementos de uma fila
  	b) Implementar uma fun��o para inverter a ordem dos elementos de uma pilha
  	c) Resolver o Problema de Josephus utilizando uma fila
*/

#include <stdio.h>
#include "FilaCircular.h"
#include "PilhaCh.h"
//interfaces
void inverterFila ( FilaCircular *);
void inverterPilha (PilhaCh *);
//implementa��es
void inverterFila ( FilaCircular *fila){
	PilhaCh pilha;
	criarPilhaChVazia(&pilha);
	unsigned char item;
	//colocando elementos da fila na pilha
	while ( fila->inicio != SINALFILA){
		item = acessarInicio(fila);
		pop(fila);
		pushPilhaCh(&pilha,item);
	}
	//colocando da pilha na fila
	while ( pilha.topo != SINAL){
		item = acessarTopo(&pilha);
		popPilhaCh(&pilha);
		push(fila,item);
	}
}

void inverterPilha (PilhaCh *pilha){
	FilaCircular fila;
	criarFilaVazia(&fila);
	unsigned char item;
	//colocando elementos da pilha na fila
	while ( pilha->topo != SINAL){
		item = acessarTopo(pilha);
		popPilhaCh(pilha);
		push(&fila,item);
	}
	//colocando da fila na pilha
	while (fila.inicio != SINALFILA){
		item = acessarInicio(&fila);
		pop(&fila);
		pushPilhaCh(pilha,item);
	}
}
