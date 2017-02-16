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
	 
	 //lendo arquivo
	 printf("\nLendo Arquivo!");
	 lerArquivo(oF);
	 printf("\nExibindo informações.");
	 exibirFichas(oF);
		

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
	 }
	 getch();
}
