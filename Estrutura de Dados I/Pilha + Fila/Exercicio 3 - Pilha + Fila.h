/* Tipo FilaCircular + Tipo Pilha  ambos do tipo char para fins didáticos*/
/*
  Arquivo: Exercicio 3.h
  Autor: Eullen Silva Viana
  Date: 10/11/16 16:49
  Descrição: Este programa implementa a biblioteca para a resolução dos seguintes exercicios:
  	a) Implementar uma função para inverter a ordem dos elementos de uma fila
  	b) Implementar uma função para inverter a ordem dos elementos de uma pilha
  	c) Resolver o Problema de Josephus utilizando uma fila
*/

#include <stdio.h>
#include "FilaCircular.h"
#include "PilhaCh.h"
//interfaces
void inverterFila ( FilaCircular *);
void inverterPilha (PilhaCh *);
//implementações
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
