#include <stdio.h>
#include <stdlib.h>

#define VIVO 1
#define MORTO 0

typedef struct coordMat{

	int linha;
	int coluna;

} tipo_coord;

int main()
{

   int tamanho, vezes;

   //tamamho maximo do vetor dos mortos é tamMatrixz * (tamMAtriz + tamMAtriz - 2);

	tamanho = 10;
	int i,j;
	int a[tamanho][tamanho];
	int aux[tamanho][tamanho];

	//zerando matrizes
	zerarMat(tamanho,a);
	zerarMat(tamanho,aux);

	//preenchendo primeira geração
	a[4][3] = 1;
	a[4][4] = 1;
	a[4][5] = 1;
	a[4][6] = 1;
	a[4][7] = 1;

	a[8][3] = 1;
	a[8][4] = 1;
	a[8][5] = 1;
	a[8][6] = 1;
	a[8][7] = 1;


	imprimirMat(tamanho,a);

	nextGen(tamanho,a,aux);
	copiarMat(tamanho,aux,a);	
	imprimirMat(tamanho,a);
	
	zerarMat(tamanho,aux);
	nextGen(tamanho,a,aux);
	copiarMat(tamanho,aux,a);	
	imprimirMat(tamanho,a);
	
	zerarMat(tamanho,aux);
	nextGen(tamanho,a,aux);
	copiarMat(tamanho,aux,a);	
	imprimirMat(tamanho,a);
	
	

    return 0;




}


//função verificar vizinhos

int gerarVizinhos (int tamMatriz, int lin, int col, tipo_coord viz[], int qtViz[]){

	//gerando vizinhos caso a linha seja a primeira
	if ( lin == 0 ){

		if ( col == 0){

			viz[0].linha = lin;
			viz[0].coluna = col+1;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin+1;
			viz[2].coluna = col+1;

			qtViz[0] = 3;
		}

		else if ( col == tamMatriz-1){

			viz[0].linha = lin;
			viz[0].coluna = col-1;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin+1;
			viz[2].coluna = col-1;

			qtViz[0] = 3;

		}
		else
		{

			viz[0].linha = lin;
			viz[0].coluna = col-1;

			viz[1].linha = lin;
			viz[1].coluna = col+1;

			viz[2].linha = lin+1;
			viz[2].coluna = col-1;

			viz[3].linha = lin+1;
			viz[3].coluna = col;

			viz[4].linha = lin+1;
			viz[4].coluna = col+1;

			qtViz[0] = 5;

		}

	}
	//gerando vizinhos caso a linha seja a última
	else if ( lin == tamMatriz-1){

		if ( col == 0){

			viz[0].linha = lin;
			viz[0].coluna = col+1;

			viz[1].linha = lin-1;
			viz[1].coluna = col;

			viz[2].linha = lin-1;
			viz[2].coluna = col+1;

			qtViz[0] = 3;
		}

		else if ( col == tamMatriz-1){

			viz[0].linha = lin;
			viz[0].coluna = col-1;

			viz[1].linha = lin-1;
			viz[1].coluna = col;

			viz[2].linha = lin-1;
			viz[2].coluna = col-1;

			qtViz[0] = 3;

		}
		else
		{

			viz[0].linha = lin;
			viz[0].coluna = col-1;

			viz[1].linha = lin;
			viz[1].coluna = col+1;

			viz[2].linha = lin-1;
			viz[2].coluna = col-1;

			viz[3].linha = lin-1;
			viz[3].coluna = col;

			viz[4].linha = lin-1;
			viz[4].coluna = col+1;

			qtViz[0] = 5;

		}

	}

	//gerando vizinhos para coluna 0
	else if ( (col == 0) && (lin != 0) && (lin != tamMatriz-1)){

			viz[0].linha = lin-1;
			viz[0].coluna = col;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin-1;
			viz[2].coluna = col+1;

			viz[3].linha = lin;
			viz[3].coluna = col+1;

			viz[4].linha = lin+1;
			viz[4].coluna = col+1;

			qtViz[0] = 5;

	}
	//gerando vizinhos para ultima coluna
	else if ( col == tamMatriz - 1){

			viz[0].linha = lin-1;
			viz[0].coluna = col;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin-1;
			viz[2].coluna = col-1;

			viz[3].linha = lin;
			viz[3].coluna = col-1;

			viz[4].linha = lin+1;
			viz[4].coluna = col-1;

			qtViz[0] = 5;


	}
	//gerando vizinhos pra colunas não finais
	else{

			viz[0].linha = lin+1;
			viz[0].coluna = col-1;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin+1;
			viz[2].coluna = col+1;

			viz[3].linha = lin;
			viz[3].coluna = col-1;

			viz[4].linha = lin;
			viz[4].coluna = col+1;

			viz[5].linha = lin-1;
			viz[5].coluna = col-1;

			viz[6].linha = lin-1;
			viz[6].coluna = col;

			viz[7].linha = lin-1;
			viz[7].coluna = col+1;


			qtViz[0] = 8;


	}

}

//função para verifiar se o individuo sobrevive para a proxima( analizando toda a matriz )

void nextGen(int tam, int mat[tam][tam], int auxMat[tam][tam]){

	int i, j, k;

	tipo_coord vizinhos[8];
	int qtdeViz[1];
	int cont = 0;

	//verificando a matriz
	for( i = 0; i < tam; i++){
		for( j=0; j <tam; j++){
			//gerando vizinhos
			gerarVizinhos(tam,i,j,vizinhos,qtdeViz);
			//printf("passou!");
			///verificando qtos vizinhos vivos esse individuo tem
			for (k=0; k < qtdeViz[0];k++){
				if( mat[vizinhos[k].linha][vizinhos[k].coluna] == VIVO){
				cont +=1;
				}
			}

			//individuo morto na geracao atual
			if (mat[i][j] == MORTO){

				//se tiver 3 vizinhos vive na proxima
				if(cont == 3)
					//salvando individuo na proxima geracao
					auxMat[i][j] = VIVO;
				else
					auxMat[i][j] = MORTO;
			}
			//individuo vivo na geracao atual
			else if ( mat[i][j] == VIVO){

				//se tiver 2 ou 3 vizinhos vive na proxima
				if((cont== 2)||(cont == 3))
					//salvando individuo na proxima geracao
					auxMat[i][j] = VIVO;

				else
					auxMat[i][j] = MORTO;

			}

			cont = 0;

		}

	}
	
}
//função para copiar matriz auxiliar na matriz principal

void copiarMat( int tam, int auxMat[tam][tam],int mat[tam][tam]) {

	int i, j;

	for ( i = 0; i < tam; i++){

		for ( j=0; j < tam; j++){
			mat[i][j] = auxMat[i][j];
		}

	}

}

void zerarMat(int tam, int mat[tam][tam]){

	int i, j;

	for ( i=0; i<tam; i++){
		for(j=0;j<tam;j++){

			mat[i][j] = 0;

		}
	}


}

void imprimirMat(int tam, int mat[tam][tam]){

	int i, j;

	for ( i=0; i<tam; i++){

		for(j=0;j<tam;j++){

			if ( mat[i][j] == 1)
				printf(" * ");
			else
				printf("   ");

		}
		printf("\n");
	}

	printf(" \n\n");
}





