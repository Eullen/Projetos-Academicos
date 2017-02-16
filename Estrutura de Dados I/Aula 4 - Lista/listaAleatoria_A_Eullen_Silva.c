/* Funções para gerar números aleatórios
  Arquivo: listaAleatoria_A_Eullen_Silva.c
  Autor: Eullen Silva Viana
  Date: 14/09/16 09:19
  Descrição: Este programa mostra a geração de números pseudo-aleatórios 
*/

#include <stdlib.h>        // biblioteca que contem a função rand
#include <stdio.h>

#define low 100
#define high 556

#define N 50       // tamanho da sequencia gerada -> N <= Maximo

#define Maximo 1000   // tamanho máximo da lista = Maximo - 1
typedef struct{
  int elemento[Maximo];
} ListaInt;


// interface construtores
ListaInt criarListaVazia(); // cria uma lista vazia

ListaInt construirListaAleatoria(int,int,int);
// tem por objetivo construir uma lista aleatoria com N números inteiros positivos
// pertencentes à faixa dada, usando a função rand da biblioteca C.

// interface acesso
void mostrarLista(ListaInt);          // mostra na tela os elementos da lista

//funções particulares
int InteiroRandomico(int,int);  // gera um número aleatório na faixa dada.

main(){
		//testa funções - não alterar
       ListaInt A, B;
       A = criarListaVazia();
       printf(" \n Lista A \n");
       mostrarLista(A);
       B = construirListaAleatoria(N,low,high);
       printf(" \n\n Lista B \n");
       mostrarLista(B);
       printf("\n\n\n");    
       system("PAUSE");
}
    
    
                
int InteiroRandomico(int lo, int hi){   // gera um número aleatório na faixa [lo,hi]
    int r;
    double g;
    g = (double)rand()/((double)RAND_MAX + 1);
    r = g*(hi-lo+1) + lo;
    return r;
}
         

ListaInt criarListaVazia(){  // a posição zero armazena o tamanho da lista
         ListaInt L;
         L.elemento[0] = 0;
         return L;
}
       
void mostrarLista(ListaInt L){ //interface da lista
     int i,n;
     n = L.elemento[0]; 
     if (n != 0) {
         printf("\n"); 
         for (i=1; i<=n; i++) printf(" %d ",L.elemento[i]);
     } 
     else printf(" \n LISTA VAZIA \n");                
}
        
ListaInt construirListaAleatoria(int M,int lo, int hi){ //gerar lista e devolver - Usar função inteiro randomico
	if (M < Maximo){
		ListaInt L;
		L.elemento[0] = M; //guardando tamanho da lista
		srand((int) time(NULL));
		int indice;
		for (indice=1;indice<=M;indice++){
			L.elemento[indice] = InteiroRandomico(lo,hi); //gerando numero aleatorio e guardando na lista
		}
		return L;
	}
}
