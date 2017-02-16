/* TAD PilhaCh = pilha de caracteres */
/*
  Arquivo: TipoPilhaCh.h
  Autor: Eullen Silva
  Date: 28/09/16 09:24
  Descrição: Este programa implementa o tipo PilhaCh.
*/

#include "Booleano.h"
#define SINAL -1
#define Fantasma '@'

#define MaxCh 21
typedef struct {
      int topo;       // topo indica o local onde se encontra o último item colocado na pilha
      unsigned char tabela[MaxCh];
} PilhaCh;

/* interface */

PilhaCh criarPilhaChVazia();
unsigned char acessarTopo(PilhaCh);
bool verificarPilhaChVazia(PilhaCh);
bool verificarPilhaChCheia(PilhaCh);
PilhaCh pushPilhaCh(PilhaCh, unsigned char);
PilhaCh popPilhaCh(PilhaCh);

/* implementações */

PilhaCh criarPilhaChVazia(){
	PilhaCh p;
	p.topo = SINAL;
	return p;        
}

unsigned char acessarTopo(PilhaCh s){
	
	unsigned char item = Fantasma ;
	if (s.topo != SINAL ){ //pilha não é vazia 
		item = s.tabela[s.topo];
	}
	return item;
}     

bool verificarPilhaChVazia(PilhaCh s){
    bool vazia;
    vazia = FALSE;
    if (s.topo == SINAL){//é vazia
    	vazia = TRUE;
	}
	
	return vazia;
}

bool verificarPilhaChCheia(PilhaCh s){
    bool cheia;
    cheia = FALSE;
    if (s.topo == (MaxCh - 1)){//está cheia
    	cheia = TRUE;
	}
	
	return cheia;
}

PilhaCh pushPilhaCh(PilhaCh s, unsigned char ch){
       
    //verifica se pilha não está cheia
    if(s.topo <= (MaxCh-1)){ //pilha não está cheia
    	s.tabela[s.topo+1] = ch;
    	s.topo ++;
	}   
	
	return s;
}

PilhaCh popPilhaCh(PilhaCh s){
    //verifica se pilha não está vazia
    if(s.topo != (SINAL)){ //pilha não está vazia
       	s.topo --;
   	} 
    return s;   
}

