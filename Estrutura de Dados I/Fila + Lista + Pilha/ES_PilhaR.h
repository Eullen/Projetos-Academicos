/* Tipo PilhaCh = pilha de caracteres */
/*
  Arquivo: ES_PilhaC.h
  Autor: Eullen Silva Viana
  Date: 31/10/16 16:46
  Descrição: Este programa implementa o tipo PilhaC (Pilha de Caracteres).
*/

#include "Booleano.h"
#define SINAL -1
#define FantasmaPR -0.001 


#define Max 26
typedef struct {
      int topo;    // topo indica o local onde se encontra o último caractere colocado na pilha
      double tabela[Max];
} PilhaR;

/* interface */

void criarPilhaRVazia(PilhaR *);
double acessarTopoPilhaR(PilhaR *);
bool verificarPilhaRVazia(PilhaR *);
bool verificarPilhaRCheia(PilhaR *);
void pushPilhaR(PilhaR *, double);
void popPilhaR(PilhaR *);


/* implementações */

void criarPilhaRVazia(PilhaR *ap){
    ap->topo = SINAL;
}

double acessarTopoPilhaR(PilhaR *s){
    	
	double item;
	if (s->topo != SINAL ){ //pilha não é vazia 
		item = s->tabela[s->topo];
	}else{
		item = FantasmaPR;
	}
	return item;
}     

bool verificarPilhaRVazia(PilhaR *s){
    bool vazia;
    
    if (s->topo == SINAL){//é vazia
    	vazia = TRUE;
	}else{
		vazia = FALSE;
	}
	
	return vazia;
}

bool verificarPilhaRCheia(PilhaR *s){
	
	bool cheia;
	
	if (s->topo == (Max-1)){//está cheia
		cheia = TRUE;
	}else{
		cheia = FALSE;
	}
	
	return cheia;
}

void pushPilhaR(PilhaR *s, double item){
    //verificar se pilha não está cheia
    if(s->topo <= (Max-1)){
    	s->tabela[s->topo+1] = item;
    	s->topo++;
	}
}

void popPilhaR(PilhaR * s){
	//verificar se pilha não está vazia
	if( s->topo != SINAL){
		s->topo --;
	}	   
}

