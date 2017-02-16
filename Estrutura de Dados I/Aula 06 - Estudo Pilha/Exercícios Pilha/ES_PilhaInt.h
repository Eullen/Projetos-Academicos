/*Pilha de Inteiros*/
/*
	Arquivo: ES_PilhaINt.h
	Autor: Eullen Silva Viana
	Date: 26/09/16 17:20
	Descrição: Implementa o tipo Pilha - Tópico 3
*/
#include <stdio.h>
#include "Booleano.h"

#define SINAL -1
#define Fantasma -2
#define MaxPilha 10

typedef struct {
	int topo;
	int tabela[MaxPilha];
} Pilha; 

//construtores
void criarPilhaVazia(Pilha *);
Pilha criarPilha();

//acesso
int acessarTopo(Pilha);
boolean verificarPilhaVazia(Pilha);
boolean verificarPilhaCheia(Pilha);

//manipulação
void push(Pilha *,int);
void pop(Pilha *);
void esvaziarPilha(Pilha *);
void estragar(Pilha *, int);

//implementando funçoes

void criarPilhaVazia(Pilha *ap){
	ap->topo = 0;
};

Pilha criarPilha(){
	Pilha p;
	p.topo = 0;
	return p;
};
 
int acessarTopo(Pilha p){
	int item;
	if ( p.topo == SINAL){
		item = Fantasma;
	}else{
		item = p.tabela[p.topo];
	}
	return item;
};

boolean verificarPilhaVazia(Pilha p){
	boolean vazia;
	vazia = FALSE;
	if(p.topo == SINAL){
		vazia = TRUE;
	}
	return vazia;
};

boolean verificarPilhaCheia(Pilha p){
	boolean cheia;
	cheia = FALSE;
	if(p.topo == (MaxPilha - 1)){
		cheia = TRUE;
	}
	return cheia;
};

//manipulação
void push(Pilha *ap,int item){ //colocar coisas na pilha 
	if(ap->topo <= (MaxPilha - 1)){//pilha não está cheia
		ap->tabela [ap->topo+1] = item;//colocando item na pilha
		ap->topo ++; //atualizando topo
	}
};
void pop(Pilha *ap){
	if(ap->topo != SINAL){//pilha não está vazia
		ap->topo --;//atualizando topo
	}
};

void esvaziarPilha(Pilha *ap){
	ap->topo = SINAL;
}; 

void estragar(Pilha *ap, int x){
	if(ap->topo != SINAL){//pilha não é vazia
		ap->tabela[ap->topo] = x;
	}else{
		ap->tabela[0] = x;
		ap->topo = 0;
	}
}
