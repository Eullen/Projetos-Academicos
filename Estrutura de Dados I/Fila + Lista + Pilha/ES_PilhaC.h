/* Tipo PilhaCh = pilha de caracteres */
/*
  Arquivo: ES_PilhaC.h
  Autor: Eullen Silva Viana
  Date: 29/10/16 16:56
  Descrição: Este programa implementa o tipo PilhaC (Pilha de Caracteres).
*/

#include "Booleano.h"
#define SINAL -1
#define FantasmaC '@' 

#define MaxCh 50
typedef struct {
      int topo;    // topo indica o local onde se encontra o último caractere colocado na pilha
      unsigned char tabela[MaxCh];
} PilhaCh;

/* interface */

void criarPilhaChVazia(PilhaCh *);
unsigned char acessarTopo(PilhaCh *);
bool verificarPilhaChVazia(PilhaCh *);
bool verificarPilhaChCheia(PilhaCh *);
void pushPilhaCh(PilhaCh *, unsigned char);
void popPilhaCh(PilhaCh *);


/* implementações */

void criarPilhaChVazia(PilhaCh *ap){
    ap->topo = SINAL;
}

unsigned char acessarTopo(PilhaCh * s){
    	
	unsigned char item;
	if (s->topo != SINAL ){ //se pilha não é vazia 
		item = s->tabela[s->topo];
	}else{
		item = FantasmaC;
	}
	return item;
}     

bool verificarPilhaChVazia(PilhaCh *s){
    bool vazia;
    
    if (s->topo == SINAL){//é vazia
    	vazia = TRUE;
	}else{
		vazia = FALSE;
	}
	
	return vazia;
}

bool verificarPilhaChCheia(PilhaCh *s){
	
	bool cheia;

	if (s->topo == (MaxCh-1)){//está cheia
		cheia = TRUE;
	}else{
		cheia = FALSE;
	}
	return cheia;
}

void pushPilhaCh(PilhaCh *s, unsigned char ch){
    //verificar se pilha não está cheia
    if(s->topo <= (MaxCh-1)){
    	s->tabela[s->topo+1] = ch;
    	s->topo ++;
	}
}

void popPilhaCh(PilhaCh * s){
	//verificar se pilha não está vazia
	if( s->topo != SINAL){
		s->topo --;
	}	   
}


