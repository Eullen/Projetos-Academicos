/* Leitura e armazenamento de strings
/*
  Arquivo: testematrizString.c
  Autor: Lisbete Madsen Barbosa
  Date: 10/10/09 09:45
  Descri��o: Exemplo de leitura de diversas express�es infixas de um arquivo texto
  e armazenamento em um array de string. USO DA FUN��O fgets
*/

#include <stdio.h>  // aqui encontram-se as fun��es de io para arquivos e tamb�m o NULL
#include <string.h> // fun��es para processar string

main(){
	int i,n,lin,col,nlinhas,j;
	char linha[81];         
	char *line;
	char *infixa[10];       // assim cada cadeia � armazenada com o terminal '\0' 
	printf("\n");
	FILE *entrada;
	entrada = fopen("expInfixa.txt","r");
	if (entrada == NULL) {
                printf("\n nao encontrado \n");
                }
    else {
         printf("arquivo encontrado \n\n");
         lin = 0; nlinhas = 0;
         while(fgets(linha, 80, entrada)!=NULL){
                                       printf(" linha = %s \n", linha);
                                       nlinhas = nlinhas +1;
//                                       line = linha; 
                                       n = strlen(linha);
                                       for(j=0;j<=n-1;j++){printf(" %d",linha[j]);}
                                       printf("\n"); 
                                       lin = lin + 1;
                                       printf(" linha %d  tamanho da linha = %d \n",nlinhas, n);
                                       infixa[lin] = linha;
                                       printf("linha %d matriz infixa %s \n",lin,infixa[lin]);
                                       printf("\n\n");
                                       }
         fclose(entrada);
//         printf("numero de linhas = %d \n",nlinhas);
//   	     for(lin=1; lin <= nlinhas; lin++){
//               col = 0;
//               do {
//                   printf("%d   %c",col, infixa[1][col]);
//                   col = col+1;                   
//                   }
//               while (infixa[lin][col] != '\0');  //o �ltimo caractere � o '\0' porque � string
//               printf("\n");
//               }
//         printf("\n");      
         }
         
	system("PAUSE");	
}
