/* Laborat�rio - aula inicial */
/*
  Arquivo: variaveis.c
  Autor: Lisbete Madsen Barbosa
  Date: 14/07/10 14:26

  Descri��o: vari�veis definidas e n�o inicializadas

*/
#include<stdio.h>

main(){
     
       float f;   // vari�vel do tipo float sem inicializa��o
       int *s; //pointer para int
       int *p; //pointer para int	
       float *q; //pointer para float
       double *r; //pointer para double	
       int a,k;   // duas vari�veis do tipo int sem inicializa��o
         int nf,nd;      
       p = &k;    // endere�o de k
       q = &f;    // endere�o de f
       s = &a; // endere�o de a
       double d;  // vari�vel do tipo double sem inicializa��o
       r = &d;  //endere�o de d
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
