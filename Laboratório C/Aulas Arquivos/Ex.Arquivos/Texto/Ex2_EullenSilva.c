//Exercicio 2 - Eullen Silva Viana - Turma C

#include <string.h>
#include <stdio.h>
// Definição de tipo
typedef struct Ficha
{
 	char Cod[7];
 	float Salario;
 	int Idade;
} Tipo_Ficha;
// Declaração dos protótipos das funções auxiliares
void lerFichas( Tipo_Ficha FC[ ] );
void ordenarFichas( Tipo_Ficha FC[ ] );
void gravarArquivo(Tipo_Ficha FC[ ] );
void lerArquivo( Tipo_Ficha FC[ ] );
void exibirFichas( Tipo_Ficha FC[ ] );

int main (void )
{
 /*
 Objetivo : Testar a manipulação de arquivos.
 Comentário : Supõe criado o subdiretório G:\ATV12
 Utiliza as funções vLerFicas(), ordenarFichas(),
 gravarArquivo(), lerArquivo() e exibirFichas( )
 */
 	Tipo_Ficha oF[5];
 	char cOp;
 	int iFlag = 0;

 	do
 	{
		 printf("Menu de opcoes\n\n");;
		 printf(" 1 - Leitura de 5 fichas, via teclado\n");
		 printf(" 2 - Gravar a lista de ficha em um arquivo\n");
		 printf(" 3 - Exibir as fichas da lista no monitor\n");
		 printf(" 4 - Ordenar as fichas da lista pela Idade\n");
		 printf(" 5 - Leitura das fichas da lista, via arquivo\n");
		 printf(" f - Finalizar");
		 printf("\n\nEscolha sua opcao: ");
		 cOp = getch();
		 switch( cOp )
		 {
			 case '1':
			 	lerFichas( oF );
			 	break;
			 case '2':
				 iFlag=1;
				 gravarArquivo( oF );
				 break;
			 case '3':
			 	exibirFichas( oF );
			 	break;
			 case '4':
				 ordenarFichas( oF ) ;
				 break;
			 case '5':
				 if (iFlag == 1 )
				 {
				 	lerArquivo( oF );
				 }
				 else
				 {
					 printf("\nArquivo inexistente");
					 getch();
				 }
		}
	} while( cOp != 'f' );
	 return 0;
}


void lerFichas( Tipo_Ficha FC[ ] )
{
 /*
 Objetivo: Efetua a leitura de 5 registros da lista FC
 Entrada : Via teclado
 Saída : FC
 */
	 int iK;
	 printf("Digite as fichas\n\n");
	 for( iK = 0; iK < 5; iK = iK + 1 )
	 {
		 printf("\nficha %d : codigo ?",iK + 1);
		 gets( FC[ iK ].Cod );
		 printf(" \nsalario ? ");
		 scanf("%f",&FC[ iK ].Salario);
		 printf("\nIdade: ");
		 scanf("%d",&FC[iK].Idade);
		 fflush(stdin);
	 }
}



void ordenarFichas( Tipo_Ficha FC[ ] )
{
 /*
 Objetivo: Ordenar os 5 registros da lista FC em ordem crescente
 de salário.
 Entrada : FC
 Saída : FC
 */
	 int iA, iB;
	 Tipo_Ficha oAux;
	 for( iA = 0; iA < 4; iA = iA + 1 )
	 {
	 	for( iB = iA + 1; iB < 5; iB++ )
	 	{
	 		if( FC[ iA ].Idade > FC[ iB ].Idade )
		 	{
	 			oAux = FC[ iA ];
			 	FC[ iA ] = FC[ iB ];
			 	FC[ iB ] = oAux;
	 		}
	 	}
	 }
	 printf("\nTerminou a ordenação");
	 getch();
}

void gravarArquivo ( Tipo_Ficha Fc[ ] ) {
/* Objetivo: Gravar 5 fichas de uma lista no arquivo C:\LP2\lista.txt
 Entrada : Fc
 Saída : Implícita através do arquivo externo lista.txt
*/
	 FILE* fArq;
	 int iC;
	 fArq = fopen( "lista.txt","w");
	 for( iC = 0; iC <= 4; iC = iC + 1 ) {
	
		 fprintf( fArq, "%s ", Fc[ iC ].Cod );
		 fprintf( fArq,"%f\n", Fc[ iC ].Salario ) ;
		 fprintf( fArq,"%d\n", Fc[iC].Idade);
	 }
	 printf("\n\n Gravação terminada");
	 getch();
	 fclose( fArq );
}


void lerArquivo( Tipo_Ficha Fc[ ] ) {
/*
 Objetivo: Efetuar a leitura de 5 fichas gravadas no arquivo externo lista.ddd armazenado em
C:\LP2 ou informar ocorrência de erro durante a leitura.
 Entrada : Implícita por meio do arquivo externo lista.txt
 Saída : Fc
*/
	 FILE *fArq;
	 int iC;
	 fArq = fopen( "lista.txt", "r" );
	 if( fArq == NULL ) {
	 	printf( "\n\nArquivo inexistente");
	 }
	 else {
		 for( iC = 0; iC <= 4; iC = iC + 1 ) {
			 fscanf( fArq, "%s ", &Fc[ iC ].Cod );
			 fscanf( fArq,"%f\n", &Fc[ iC ].Salario );
			 fscanf( fArq,"%d\n", &Fc[iC].Idade);
	}
	 fclose( fArq );
	 printf("\n\nTerminou leitura do arquivo");
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
		 printf("\n Idade: %d",FC[iK].Idade);
	 }
	 getch();
}
