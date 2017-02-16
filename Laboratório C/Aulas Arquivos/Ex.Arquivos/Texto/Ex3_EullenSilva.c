//Exercicio 2 - Eullen Silva Viana - Turma C
#include <string.h>
#include <stdio.h>
// Defini��o de tipo
typedef struct Ficha
{
	 char Cod[7];
	 float Salario;
	 int Idade;
} Tipo_Ficha;
// Declara��o dos prot�tipos das fun��es auxiliares
void lerArquivo( Tipo_Ficha FC[ ] );
void exibirFichas( Tipo_Ficha FC[ ] );

int main (void )
{
	 /*
	 Objetivo : Testar a manipula��o de arquivos.
	 Coment�rio : Sup�e criado o subdiret�rio G:\ATV12
	 Utiliza as fun��es vLerFicas(), ordenarFichas(),
	 gravarArquivo(), lerArquivo() e exibirFichas( )
	 */
	 Tipo_Ficha oF[5];
	 
	 //lendo arquivo
	 printf("\nLendo Arquivo!");
	 lerArquivo(oF);
	 printf("\nExibindo informa��es.");
	 exibirFichas(oF);
		

}




void lerArquivo( Tipo_Ficha Fc[ ] ) {
/*
 Objetivo: Efetuar a leitura de 5 fichas gravadas no arquivo externo lista.ddd armazenado em
C:\LP2 ou informar ocorr�ncia de erro durante a leitura.
 Entrada : Impl�cita por meio do arquivo externo lista.txt
 Sa�da : Fc
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
 Sa�da : Layout
 */
	 int iK;
	 printf("Lista de 5 fichas da lista\n");
	 for( iK = 0; iK < 5; iK++ )
	 {
		 printf("\n\nficha %d codigo : %s",iK+1,FC[iK].Cod);
		 printf("\n sal�rio: %f",FC[ iK ].Salario);
	 }
	 getch();
}
