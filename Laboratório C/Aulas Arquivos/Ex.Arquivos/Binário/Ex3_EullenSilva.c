
//Eullen Silva Viana - Turma C - Exercício 3

#include <string.h>
#include <stdio.h>

	// Definição de tipo
typedef struct Ficha
	{
	 	char Cod[7];
	 	float Salario;
	} Tipo_Ficha;

//funçôes

void lerArquivo( Tipo_Ficha FC[ ] );
void exibirFichas( Tipo_Ficha FC[ ] );

void main(){
	
	float media, total=0;
	
	Tipo_Ficha oF[5];
	char cOp;
	int i;
	
	//lendo arquivo
	printf("\nLendo Arquivo!");
	lerArquivo(oF);
	printf("\nFichas:");
	exibirFichas(oF);
	
	//calculando media
	for(i=0; i<5;i++){
		total += oF[i].Salario;		
	}
	media = total/5;
	
	printf("\nA media dos salario e: %.2f",media);
	
}

void lerArquivo( Tipo_Ficha FC[ ] )
{
	 /*
	 Objetivo: Efetuar a leitura de 5 fichas gravadas no arquivo externo
	 lista.ddd armazenado em G:\ATV12 ou informar ocorrÛncia
	Laboratório de Programação 2
	 de êrro durante a leitura
	 Entrada : Implícita por meio do arquivo externo lista.ddd
	 Saída : FC
	 */
	 FILE *fArq;
	 int iQ;
	 fArq = fopen( "lista.ddd", "rb" );
	 iQ = fread( FC,sizeof( Tipo_Ficha ), 5, fArq );
	 fclose( fArq );
	 if ( iQ != 5 )
	 {
	 	printf("\nErro na leitura do arquivo");
	 }
	 else
	 {
	 	printf("\nTerminou leitura do arquivo");
	 }
	 getch();
	}

void exibirFichas( Tipo_Ficha FC[ ] )
{
 /*
 Objetivo: Exibir na tela as 5 fichas da lista FC
 Entrada : FC
 Saída : Layout
 */
 int iK;
 printf("Lista de 5 fichas da lista\n");
 for( iK = 0; iK < 5; iK++ )
 	{
 		printf("\n\nficha %d codigo : %s",iK+1,FC[iK].Cod);
 		printf("\n salário: %f",FC[ iK ].Salario);
 	}
 getch();
}
