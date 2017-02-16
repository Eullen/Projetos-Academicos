/* Fun��es para gerar n�meros aleat�rios
  Arquivo: listaAleatoria_A_Eullen_Silva.c
  Autor: Eullen Silva Viana
  Date: 14/09/16 09:19
  Descri��o: Este programa mostra a gera��o de n�meros pseudo-aleat�rios 
*/

#include <stdlib.h>        // biblioteca que contem a fun��o rand
#include <stdio.h>

#define low 100
#define high 556

#define N 50       // tamanho da sequencia gerada -> N <= Maximo

#define Maximo 1000   // tamanho m�ximo da lista = Maximo - 1
typedef struct{
  int elemento[Maximo];
} ListaInt;


// interface construtores
ListaInt criarListaVazia(); // cria uma lista vazia

ListaInt construirListaAleatoria(int,int,int);
// tem por objetivo construir uma lista aleatoria com N n�meros inteiros positivos
// pertencentes � faixa dada, usando a fun��o rand da biblioteca C.

// interface acesso
void mostrarLista(ListaInt);          // mostra na tela os elementos da lista

//fun��es particulares
int InteiroRandomico(int,int);  // gera um n�mero aleat�rio na faixa dada.

main(){
		//testa fun��es - n�o alterar
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
    
    
                
int InteiroRandomico(int lo, int hi){   // gera um n�mero aleat�rio na faixa [lo,hi]
    int r;
    double g;
    g = (double)rand()/((double)RAND_MAX + 1);
    r = g*(hi-lo+1) + lo;
    return r;
}
         

ListaInt criarListaVazia(){  // a posi��o zero armazena o tamanho da lista
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
        
ListaInt construirListaAleatoria(int M,int lo, int hi){ //gerar lista e devolver - Usar fun��o inteiro randomico
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
