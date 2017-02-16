/* Tipo PilhaCh = pilha de caracteres */
/*
  Arquivo: PilhaCh.h
  Autor: Eullen Silva Viana
  Date: 28/09/16 09:24
  Descri��o: Este programa implementa o tipo PilhaCh.
*/

#include "Booleano.h"
#define SINAL -1
#define Fantasma '@' 

#define MaxCh 40
typedef struct {
      int topo;    // topo indica o local onde se encontra o �ltimo caractere colocado na pilha
      unsigned char tabela[MaxCh];
} PilhaCh;

/* interface */

void criarPilhaChVazia(PilhaCh *);
unsigned char acessarTopo(PilhaCh *);
bool verificarPilhaChVazia(PilhaCh *);
bool verificarPilhaChCheia(PilhaCh *);
void pushPilhaCh(PilhaCh *, unsigned char);
void popPilhaCh(PilhaCh *);


/* implementa��es */

void criarPilhaChVazia(PilhaCh *ap){
    ap->topo = SINAL;
}

unsigned char acessarTopo(PilhaCh * s){
    	
	unsigned char item = Fantasma ;
	if (s->topo != SINAL ){ //pilha n�o � vazia 
		item = s->tabela[s->topo];
	}
	return item;
    	
}     

bool verificarPilhaChVazia(PilhaCh *s){
    bool vazia;
    vazia = FALSE;
    if (s->topo == SINAL){//� vazia
    	vazia = TRUE;
	}
	
	return vazia;
}

bool verificarPilhaChCheia(PilhaCh *s){
	
	bool cheia;
	cheia = FALSE;
	if (s->topo == (MaxCh-1)){//est� cheia
		cheia = TRUE;
	}
	
	return cheia;
}

void pushPilhaCh(PilhaCh *s, unsigned char ch){
    //verificar se pilha n�o est� cheia
    if(s->topo <= (MaxCh-1)){
    	s->tabela[s->topo+1] = ch;
    	s->topo = s->topo + 1;
	}
}

void popPilhaCh(PilhaCh * s){
	//verificar se pilha n�o est� vazia
	if( s->topo != SINAL){
		s->topo --;
	}	   
}

