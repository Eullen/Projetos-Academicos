	//Eullen Silva Viana - Turma C - Exerc�cio 2
	
	#include <string.h>
	#include <stdio.h>
	
	#define MAX 50	
	
	// Defini��o de tipo
	typedef struct Ficha
	{
	 	char Cod[7];
	 	float Salario;
	} Tipo_Ficha;
	//declarando vari�vel global
	char nomeArquivo[50];
	
	// Declara��o dos prot�tipos das fun��es auxiliares
	void lerFichas( Tipo_Ficha FC[ ], int iN[] );
	void ordenarFichas( Tipo_Ficha FC[ ], int iN );
	void gravarArquivo(Tipo_Ficha FC[ ], char nomeArq[] );
	void lerArquivo( Tipo_Ficha FC[ ], char nomeArq[] );
	void exibirFichas( Tipo_Ficha FC[ ], int iN );

	
	
	
	int main (void )
	{
	 /*
	 Objetivo : Testar a manipula��o de arquivos.
	 Coment�rio : Sup�e criado o subdiret�rio G:\ATV12
	 Utiliza as fun��es vLerFicas(), ordenarFichas(),
	 gravarArquivo(), lerArquivo() e exibirFichas( )
	 */
		 Tipo_Ficha oF[MAX];
		 char cOp;
		 int iFlag = 0;
		 int iN[1];
	
	 do
	 {
	 	printf("Menu de opcoes\n\n");;
	 	printf(" 1 - Leitura de ate 50 fichas, via teclado\n");
	 	printf(" 2 - Gravar a lista de ficha em um arquivo\n");
	 	printf(" 3 - Exibir as fichas da lista no monitor\n");
	 	printf(" 4 - Ordenar as fichas da lista pelo salario\n");
	 	printf(" 5 - Leitura das fichas da lista, via arquivo\n");
	 	printf(" f - Finalizar");
	 	printf("\n\nEscolha sua opcao: ");
	 	cOp = getch();
	 	switch( cOp )
	 	{
	 		case '1':
	 		lerFichas( oF, iN );
	 		break;
	 		case '2':
	 			iFlag=1;
	 			printf("\nDigite o nome do arquivo: ");
	 			gets(nomeArquivo);
	 			gravarArquivo( oF, nomeArquivo);
	 			break;
		 case '3':
		 	exibirFichas( oF,iN[0] );
		 	break;
		 case '4':
			 ordenarFichas( oF, iN[0] ) ;
			 break;
		 case '5':
			 if (iFlag == 1 )
	 		{
	 			lerArquivo( oF, nomeArquivo );
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



	void lerFichas( Tipo_Ficha FC[ ], int iN[] )
	{
	 /*
	 Objetivo: Efetua a leitura de 50 registros da lista FC
	 Entrada : Via teclado
	 Sa�da : FC
	 */
	 int iK = 0;
	 int fim = 0;
	 printf("Digite as fichas.\n\n");
	 do{
	 	fflush(stdin);
		 printf("\nficha %d : codigo ?:",iK + 1);
	 	gets(FC[ iK ].Cod);
	 	printf(" \nsalario ?: ");
	 	scanf("%f",&FC[ iK ].Salario);
	 	fflush(stdin);
		iK++;
		
		printf("\nDeseja parar? 0-N / 1-S\n ");
		scanf("%d",&fim);
		fflush(stdin);
		
	} while ( !fim && iK < MAX);
	iN[0] = iK;
	}
	
	void ordenarFichas( Tipo_Ficha FC[ ], int iN )
	{
	 /*
	 Objetivo: Ordenar os iN registros da lista FC em ordem crescente
	 de sal�rio.
	 Entrada : FC
	 Sa�da : FC
	 */
	 int iA, iB;
	 Tipo_Ficha oAux;
	 for( iA = 0; iA < (iN-1); iA = iA + 1 )
	 	{
	 		for( iB = iA + 1; iB < iN ; iB++ )
	 		{
	 			if( FC[ iA ].Salario > FC[ iB ].Salario )
	 			{
	 			oAux = FC[ iA ];
	 			FC[ iA ] = FC[ iB ];
	 			FC[ iB ] = oAux;
	 			}
	 		}	
	 	}	
	 printf("\nTerminou a ordena��o");
	 getch();
	}



	void gravarArquivo( Tipo_Ficha FC[ ], char nomeArq[])
	{
	 /*
	 Objetivo: Gravar 5 itens da lista FC no arquivo lista.ddd armazenado
	 em G:\ATV12 ou informar ocorr�ncia de �rro na grava��o.
	 Entrada : FC
	 Sa�da : Impl�cita no arquivo externo lista.ddd
	 */
	 FILE* fArq;
	 int iQ;
	 
	 fArq = fopen( nomeArq, "wb" );
	 iQ = fwrite( FC, sizeof( Tipo_Ficha ), 5, fArq );
	 fclose( fArq );
	 if( iQ != 5 )
	 	{
		 printf("\n\nErro na grava��o");
		}
	 else
	 	{
	 	printf("\nTerminou grava��o");
	 	}
	 getch();
	} // Observe que o argumento de sizeof( ) � do tipo struct
	
	
	
	
	void lerArquivo( Tipo_Ficha FC[ ], char nomeArq[] )
	{
	 /*
	 Objetivo: Efetuar a leitura de 5 fichas gravadas no arquivo externo
	 lista.ddd armazenado em G:\ATV12 ou informar ocorr�ncia
	Laborat�rio de Programa��o 2
	 de �rro durante a leitura
	 Entrada : Impl�cita por meio do arquivo externo lista.ddd
	 Sa�da : FC
	 */
	 FILE *fArq;
	 int iQ;
	 fArq = fopen( nomeArq, "rb" );
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
	
	
	
	void exibirFichas( Tipo_Ficha FC[ ], int iN )
	{
	 /*
	 Objetivo: Exibir na tela as 5 fichas da lista FC
	 Entrada : FC
	 Sa�da : Layout
	 */
	 int iK;
	 printf("Lista de 5 fichas da lista\n");
	 for( iK = 0; iK < iN; iK++ )
	 	{
	 	printf("\n\nficha %d codigo : %s",iK+1,FC[iK].Cod);
	 	printf("\n sal�rio: %f",FC[ iK ].Salario);
	 	}
	 getch();
	}
