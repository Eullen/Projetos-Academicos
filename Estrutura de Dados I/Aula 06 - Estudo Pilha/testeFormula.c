/* TAD PilhaCh = pilha de simbolos */
/*
  Arquivo: TADPilhaCh.c
  Autor: Lisbete Madsen Barbosa
  Date: 18/09/12 12:48
  Descrição: Este programa é um verificador de erros de correspondencia entre os parênteses em uma formula. 
  Uma formula pode conter somente letras maiusculas, parenteses, sinais de operação (+,-,*,/) e termina 
  com um ponto e vírgula.  Não há espaços entre os caracteres. 
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

