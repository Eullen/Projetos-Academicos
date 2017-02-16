/* TAD ListaReais */
/*
  Arquivo: ES_ListaR.h
  Autor: Eullen Silva	
  Date: 26/10/16 10:16
  Descrição: Implementa o tipo ListaReais
*/

#include "Booleano.h"
#define Maximo 27
#define FantasmaR -999.1
typedef struct{
  int tamanho;
  double vetor[Maximo]; //posição zero não será utilizada
} ListaR;

//interface
void criarLista(ListaR *);
void inserirNoFim (ListaR *,double);
void inserir(ListaR *, double, int);
double obterElemento (ListaR *,int);
int obterTamanho (ListaR *);
bool verificarListaCheia(ListaR *);
bool verificarListaVazia(ListaR *);
void esvaziarLista(ListaR *);
int buscarElemento (ListaR *,double);
void removerLocal (ListaR*, int);

//implementacoes
void criarLista(ListaR *lista){
	lista->tamanho = 0;	

}
void inserirNoFim (ListaR *lista,double item){
	//pegando posição
	int posicao = lista->tamanho+1;
	if (posicao <Maximo){ //verificando se lista tem espaço para colocar novo item
		//colocando item na lista
		lista->vetor[posicao] = item;
		//atualizando tamanho
		lista->tamanho++;
	}	
}

void inserir(ListaR *lista, double item, int pos){
	//
	int cursor;
	if((lista->tamanho+1)<Maximo){ //cabe na +1 na lista
		if ((pos>=1)&&(pos<=(lista->tamanho+1))){ //pos é válida
			if(pos<=lista->tamanho){ //preciso deslocar
				for((cursor=lista->tamanho); cursor>=pos; cursor--){
					lista->vetor[cursor+1] = lista->vetor[cursor];
				}
			}
			lista->vetor[pos]=item;
			lista->tamanho++;
		}	
	}
	
}

double obterElemento(ListaR *lista,int pos){
	double item;	
	//verificando validade de posição
	if ((pos>=1)&&(pos<=lista->tamanho)){
		item = lista->vetor[pos];
	}else{
		item = FantasmaR;
	}	
	return item;
}

int obterTamanho (ListaR *lista){
	return lista->tamanho;
}
bool verificarListaCheia(ListaR *lista){
	bool cheia;
	if(lista->tamanho == (Maximo-1)){
		cheia = TRUE;
	}else{
		cheia =FALSE;
	}
	return cheia;
}

bool verificarListaVazia(ListaR *lista){
	bool vazia;
	if(lista->tamanho == 0){
		vazia = TRUE ;
	}else{
		vazia = FALSE;
	}
	return vazia;
}

void esvaziarLista(ListaR *lista){
	lista->tamanho = 0;
}
//localizar posição de um item passado
int buscarElemento (ListaR *lista,double item){
	int pos = 0, cursor;
	if (lista->tamanho!=0){
		cursor = 1;
		while((lista->vetor[cursor] != item)&&(cursor < lista->tamanho)){
			cursor++;
		}
		//verificando se achou item na lista
		if(lista->vetor[cursor]==item){
			pos = cursor;
		}
	}
	return pos;

}
void removerLocal (ListaR* lista, int pos){
	int cursor;
	if((pos>=1)&&(pos<=lista->tamanho)){
		if(pos<lista->tamanho){
			cursor = pos+1;
			for(cursor; cursor<=lista->tamanho;cursor++){
				lista->vetor[cursor-1] = lista->vetor[cursor];	
			}
		}
		lista->tamanho--;
		
	}
}
