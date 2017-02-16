/* Leitura e armazenamento de cadeias de caracteres em uma matriz
/*
  Arquivo: matrizInfixa.c
  Autor: Lisbete Madsen Barbosa
  Date: 10/10/09 09:45
  Descrição: Exemplo de leitura de diversas expressões infixas de um arquivo texto
  e armazenamento em uma matriz de caracteres.
*/

#define pv ';'
#include <stdio.h>       // aqui encontram-se as funções de io para arquivos e também o NULL
#include <string.h>      // aqui estão as funções para processar strings

// PROTÓTIPOS
int LerDoArquivo(unsigned char m[21][81]);
void mostrarMatriz(unsigned char m[21][81],int);

main(){
    unsigned char infixa[21][81];    // a matriz infixa armazena até 20 cadeias de caracteres
    int n;			     // ocupando a partir da linha 1, coluna 1
    n = LerDoArquivo(infixa);
    mostrarMatriz(infixa,n);
    printf("\n");
    system("PAUSE");	
}

// IMPLEMENTAÇÕES
int LerDoArquivo(unsigned char matrizInfixa[21][81]){
    int i,n,lin,nlinhas;
    nlinhas = 0;
    unsigned char linha[81];
    FILE *entrada;
    entrada = fopen("expInfixa.txt","r");  // o arquivo expInfixa.txt pode conter até 10 expressões
    if (entrada == NULL) printf("\n arquivo de dados inexistente \n\n");
    else {
         lin = 0; 
         while(fscanf(entrada, "%80s", linha)==1){// lê até 80 caracteres e guarda na string linha
                   nlinhas = nlinhas +1;// conta o número de linhas lidas no arquivo
                   n = strlen(linha);   // n = comprimento da linha 
                   lin = lin + 1;       // na matriz infixa, a primeira cadeia vai para a linha 1
                   for(i=0;i<=n-1;i++){ // cada caractere da string será copiado na coluna i+1 da matriz
                       matrizInfixa[lin][i+1]=linha[i];
                   }
                   matrizInfixa[lin][n+1]= pv;        // acrescenta o terminal da infixa
         }
    	 fclose(entrada);
    }  
    return nlinhas;
}     
     

void mostrarMatriz(unsigned char matriz[21][81],int m){
     int lin,col;
     printf("\n");
     for(lin=1; lin <= m; lin++){
               col = 0;
               printf(" %4d)  ",lin);
               do {
                   col = col+1;
                   printf("%c",matriz[lin][col]);
               }
               while (matriz[lin][col] != pv);
               printf("\n");
      }
      printf("\n");      
}

