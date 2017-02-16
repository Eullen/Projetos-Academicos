/* Funções para gerar números aleatórios
  Arquivo: listaAleatoria_B_Eullen_Silva.c
  Autor: Eullen Silva Viana
  Date: 14/09/16 09:47
  Descrição: Este programa mostra a geração de números pseudo-aleatórios usando formula de Lehmer 
*/

#include <stdlib.h>       // biblioteca que contem a função rand
#include <stdio.h>

#define semente 105
#define a 961  //primo 1
#define m 2 //primo 2

#define N 50       // tamanho da sequencia gerada

#define Maximo 1000   // tamanho máximo da lista = Maximo - 1
typedef struct{
  int elemento[Maximo];
} ListaInt;

// interface construtores
ListaInt criarListaVazia(); // cria uma lista vazia

ListaInt gerarListaAleatoria(int,int);
// tem por objetivo gerar uma lista aleatoria com N números inteiros positivos
// usando o algoritmo de Lehmer.

// interface acesso
void mostrarLista(ListaInt);          // mostra na tela os elementos da lista

main(){
       ListaInt A, C;
       A = criarListaVazia();
       printf(" \n Lista A \n");
       mostrarLista(A);
       C = gerarListaAleatoria(N,semente);
       printf(" \n\n Lista C \n");
       mostrarLista(C);
       printf("\n\n\n");    
       system("PAUSE");
}
    
   
ListaInt criarListaVazia(){  // a posição zero armazena o tamanho da lista
         ListaInt L;
         L.elemento[0] = 0;
         return L;
}
       
void mostrarLista(ListaInt L){
     int i,n;
     n = L.elemento[0]; 
     if (n != 0) {
         printf("\n"); 
         for (i=1; i<=n; i++) printf(" %d ",L.elemento[i]);
     } 
     else printf(" \n LISTA VAZIA \n");                
}
       
ListaInt gerarListaAleatoria(int M,int seed){
         
		 ListaInt L;
         L.elemento[0] = M; //guardando tamanho da sequência
         int termo = seed; //definindo primeiro termo
         int c = 1; //definindo c;
         int indice;
		 for(indice=1;indice<=M;indice++){
		 	termo = (a * termo + c)%m; //gerando termo
		 	L.elemento[indice] = termo; //armazenando termo na lista
		 }
         return L;
}
