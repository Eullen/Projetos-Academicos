/* TAD PilhaCh = pilha de simbolos */
/*
  Arquivo: TADPilhaCh.c
  Autor: Lisbete Madsen Barbosa
  Date: 18/09/12 12:48
  Descri��o: Este programa � um verificador de erros de correspondencia entre os par�nteses em uma formula. 
  Uma formula pode conter somente letras maiusculas, parenteses, sinais de opera��o (+,-,*,/) e termina 
  com um ponto e v�rgula.  N�o h� espa�os entre os caracteres. 
*/

#include "Booleano.h"
#include "TipoPilhaCh.h"

#define pv ';'
#define pE '('
#define pD ')'

main (){
     char * formula;
     bool ERRO;
     formula = "()(B+C)*A)(+D*B;";      printf(" formula = %s \n\n",formula);
     ERRO = FALSE;

     if (ERRO == TRUE) printf(" TEM ERRO \n"); else printf(" nao tem erro \n");
     printf("\n");
     system("PAUSE");
}

