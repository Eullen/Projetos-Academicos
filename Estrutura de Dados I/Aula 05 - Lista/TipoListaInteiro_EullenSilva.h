/* TAD ListaInt */
/*
  Arquivo: TipoListaInteiro_EullenSilva.h
  Autor: Eullen Silva	
  Date: 21/09/16 09:15
  Descrição: Implementa o tipo ListaInt
*/

#include <stdlib.h>    
#include <stdio.h>
#include <time.h>

#define fantasma 0
#define Maximo 11   
typedef struct{
  int vetor[Maximo];
} ListaInt;

//Interfaces
// construtores
    ListaInt criarLista();                    // criar uma lista vazia
    ListaInt construirListaRam(int,int,int);  // construir uma lista aleatória com n itens na faixa [a,b]
//  acesso    
    void mostrarLista(ListaInt);              // mostra a lista 
    int obterTamanho(ListaInt);               // obter o tamanho da lista	
    int obterElemento(ListaInt, int);         // obter o item de ordem p		
// manipulação    
    ListaInt inserirNoFim(ListaInt,int);      // inserir um item no final da lista
    ListaInt sorting(ListaInt);               // ordena em ordem crescente			


//Implementações

ListaInt criarLista(){
         ListaInt listaA;
         listaA.vetor[0]= 0;
         return listaA;
}
       
ListaInt construirListaRam(int M,int lo, int hi){
	ListaInt listaRandom;
	listaRandom.vetor[0]= M; //guardando tamanho da lista

	if((M > 0)&&(M<Maximo)){
		int cursor,r;
		double g;
		//gerando semente
		srand((int) time(NULL));
		for(cursor = 1; cursor <= M;cursor++){
			//gerando numero aleatório
		   	g = (double)rand()/((double)RAND_MAX + 1);
	    	r = g*(hi-lo+1) + lo;
	    	//guardando numero em lista
	    	listaRandom.vetor[cursor] = r;
		}
	}	
	
	return listaRandom; //retornando lista de inteiros
}

void mostrarLista(ListaInt L){
     int k, n;
     n = L.vetor[0];
     if (n==0) printf(" \n lista vazia \n");
     else { 
            printf("\n"); 
            for(k=1;k<=n;k++)printf(" %d ", L.vetor[k]);
     }
     printf("\n");
}

int obterTamanho(ListaInt L){
	return L.vetor[0];//retorna tamnho que esta na pos 0
}

int obterElemento(ListaInt L, int p){
	//preparando retorno
	int item;	
	//verificando tamanho da lista
	int tamanho = L.vetor[0];
	//verificando validade de posição
	if ((p>=1)&&(p<=tamanho)){
		item = L.vetor[p];
	}else{
		item = fantasma;
	}	
	return item;
}

ListaInt inserirNoFim(ListaInt L,int y){
	//pegando posição
	int posicao = obterTamanho(L) + 1;
	if (posicao < Maximo){ //verificando se lista tem espaço para colocar novo item
		//colocando item na lista
		L.vetor[posicao] = y;
		//atualizando tamanho
		L.vetor[0] = posicao;
	}
	return L;	
}

ListaInt sorting(ListaInt L){
         int k,j,aux,u,p;
         u = L.vetor[0]; p = 1;
         for(k=1; k<=(u-p); k++)
                  for(j=p; j<=(u-k); j++)
                           if(L.vetor[j]>L.vetor[j+1]){
                           aux = L.vetor[j]; L.vetor[j] = L.vetor[j+1]; L.vetor[j+1] = aux;
                           }
         return L;
}     
