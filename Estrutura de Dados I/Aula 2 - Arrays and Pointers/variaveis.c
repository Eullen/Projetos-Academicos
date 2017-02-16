/* Laboratório - aula inicial */
/*
  Arquivo: variaveis.c
  Autor: Lisbete Madsen Barbosa
  Date: 14/07/10 14:26

  Descrição: variáveis definidas e não inicializadas

*/
#include<stdio.h>

main(){
     
       float f;   // variável do tipo float sem inicialização
       int *s; //pointer para int
       int *p; //pointer para int	
       float *q; //pointer para float
       double *r; //pointer para double	
       int a,k;   // duas variáveis do tipo int sem inicialização
         int nf,nd;      
       p = &k;    // endereço de k
       q = &f;    // endereço de f
       s = &a; // endereço de a
       double d;  // variável do tipo double sem inicialização
       r = &d;  //endereço de d
       nf = sizeof(f); nd = sizeof(d); //tamanho de f e d
       printf("\n\n exercicio 11:\n"); 
       printf(" \n k = %d \n f = %f  \n d = %f ",k,f,d); 
       printf(" \n a = %d \n\n endereco a = %d  \n",a,s);
       printf(" \n endereco k = %d \n\n",p);
       printf("\n endereco f = %d  \n endereco d = %d  \n ",q,r);
       printf(" \n nf = %d \n  nd = %d \n ",nf,nd); 
 	   printf("\n\n");
	   system("PAUSE");
}
