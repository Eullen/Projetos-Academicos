#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define VIVO 1
#define MORTO 0

typedef struct coordMat{

	int linha;
	int coluna;

} tipo_coord;

//declarando fun��es
int gerarVizinhos (int tamMatriz, int lin, int col, tipo_coord viz[], int qtViz[]); //gerar vizinhos de um individuo
void nextG ( int tam, int tamV[], tipo_coord vivas[],int mat[tam][tam]); //gerar proxima geracao e armazena em um vetor
void zerarMat(int tam, int mat[tam][tam]);//zera matriz
void imprimirMat(int tam, int mat[tam][tam]); //imprime matriz
void preencherMat(int tam, int mat[tam][tam], tipo_coord vet[], int tamVetor); //preenche matriz de acordo com o vetor que contem os vivos

int main()
{

   int tamanho, vezes;

   //tamamho maximo do vetor dos mortos � tamMatrixz * (tamMAtriz + tamMAtriz - 2);

	tamanho = 10;
	int i,j;
	int a[tamanho][tamanho];
	int aux[tamanho][tamanho];

	//zerando matrizes
	zerarMat(tamanho,a);
	zerarMat(tamanho,aux);

	//preenchendo primeira gera��o
	a[3][4] = 1;
	a[4][4] = 1;
	a[5][4] = 1;
	a[6][4] = 1;	
	a[7][4] = 1;
	a[3][6] = 1;
	a[7][6] = 1;
	a[3][8] = 1;
	a[4][8] = 1;
	a[5][8] = 1;
	a[6][8] = 1;	
	a[7][8] = 1;			
	
	
	//declarando vari�veis que ser�o usadas nas fun��es
	int tamVetor[1];

	tipo_coord vivas[tamanho*tamanho];
	vivas[0].linha = 3; vivas[0].coluna = 4;
	vivas[1].linha = 4; vivas[1].coluna = 4;
	vivas[2].linha = 5; vivas[2].coluna = 4;
	vivas[3].linha = 6; vivas[3].coluna = 4;
	vivas[4].linha = 7; vivas[4].coluna = 4;
	vivas[5].linha = 3; vivas[5].coluna = 6;
	vivas[6].linha = 7; vivas[6].coluna = 6;
	vivas[7].linha = 3; vivas[7].coluna = 8;
	vivas[8].linha = 4; vivas[8].coluna = 8;
	vivas[9].linha = 5; vivas[9].coluna = 8;
	vivas[10].linha = 6; vivas[10].coluna = 8;
	vivas[11].linha = 7; vivas[11].coluna = 8;


	//Qtde de vivos
	tamVetor[0] = 12;

	//chamando fun��o pra gerar proxima gera��o
	nextG(tamanho,tamVetor,vivas,a);
	//zerando matriz
	zerarMat(tamanho,a);	
	//preenchendo matriz
	preencherMat(tamanho,a,vivas,tamVetor[0]);
	//imprimindo matriz
	imprimirMat(tamanho,a);
	
	//chamando fun��o pra gerar proxima gera��o
	nextG(tamanho,tamVetor,vivas,a);
	//zerando matriz
	zerarMat(tamanho,a);	
	//preenchendo matriz
	preencherMat(tamanho,a,vivas,tamVetor[0]);
	//imprimindo matriz
	imprimirMat(tamanho,a);
	
	//chamando fun��o pra gerar proxima gera��o
	nextG(tamanho,tamVetor,vivas,a);
	//zerando matriz
	zerarMat(tamanho,a);	
	//preenchendo matriz
	preencherMat(tamanho,a,vivas,tamVetor[0]);
	//imprimindo matriz
	imprimirMat(tamanho,a);
	
	//chamando fun��o pra gerar proxima gera��o
	nextG(tamanho,tamVetor,vivas,a);
	//zerando matriz
	zerarMat(tamanho,a);	
	//preenchendo matriz
	preencherMat(tamanho,a,vivas,tamVetor[0]);
	//imprimindo matriz
	imprimirMat(tamanho,a);
	
	//chamando fun��o pra gerar proxima gera��o
	nextG(tamanho,tamVetor,vivas,a);
	//zerando matriz
	zerarMat(tamanho,a);	
	//preenchendo matriz
	preencherMat(tamanho,a,vivas,tamVetor[0]);
	//imprimindo matriz
	imprimirMat(tamanho,a);

	//Lucas,m aqui eu usei o exemplo do exploder naquele simulador
	//d� certo pra outros que testei tbm


    return 0;




}


//fun��o verificar vizinhos

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
	//gerando vizinhos caso a linha seja a �ltima
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
	//gerando vizinhos pra colunas n�o finais
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

//fun��o para verifiar se o individuo sobrevive para a proxima( analizando toda a matriz )

void nextG ( int tam, int tamV[], tipo_coord vivas[],int mat[tam][tam]){


	int i, j, k;

	tipo_coord vizinhos[8];
	int tamMortos = tam * ( tam+tam-2);
	tipo_coord auxViz[tamMortos];
	int qtdeViz[1];
	int contMorto = 0;
	int contVivo = 0;
	int cursorViz = 0;
	int contador;
	tipo_coord Viz[tam*tam];

	//verificando vivos
	for ( i=0; i < tamV[0]; i++ ){
		//gerando vizinhos
		gerarVizinhos(tam,vivas[i].linha, vivas[i].coluna,vizinhos,qtdeViz);
		//armazenando os mortos em outro vetor e vivos que continuar�o vivos na matriz
		for ( j=0; j<qtdeViz[0];j++ ){
			//vendo se vizinho est�  morto
			if(mat[vizinhos[j].linha][vizinhos[j].coluna] == MORTO){
				//guardando morto
				auxViz[contMorto].linha = vizinhos[j].linha;
				auxViz[contMorto].coluna = vizinhos[j].coluna;
				contMorto++; //incrementando contador para saber a posi��o do vetor que guarda todos os vizinhos mortos
			}
			else{
				
				contVivo++;
            }
		}

		//se vivo sobrevive
		if((contVivo == 2)||(contVivo == 3)){
				//salvar no vetor de vivos para gera��o seguinte
				Viz[cursorViz].linha = vivas[i].linha;
				Viz[cursorViz].coluna = vivas[i].coluna;
				cursorViz++; //avan�ando cursor no vetor VIZ
		}

		//zerando contVivo
		contVivo = 0;

	}


	//VERIFICANDO QUAIS MORTOS TEM EXATAMENTE 3 VIZINHOS

	for ( k = 0; k < contMorto;k++){
		//mudar isso aqui, tem de comparar s� uma vez msm
		contador = 1;
		for ( i=k+1; i < contMorto; i++){
			//comparando com o resto
			if (( auxViz[k].linha == auxViz[i].linha) && (auxViz[k].coluna == auxViz[i].coluna)){
				auxViz[i].linha = -1; auxViz[i].coluna = -1;
				contador++;
			}
		}

		if (( contador == 3) && ( auxViz[k].linha != -1 ) ) {//esse cara vai nascer
            //salvar no vetor de vivos para gera��o seguinte ser calculada
            Viz[cursorViz].linha = auxViz[k].linha;
            Viz[cursorViz].coluna = auxViz[k].coluna;
            cursorViz++; //avan�ando cursor no vetor VIZ
		}

	}

	tamV[0] = cursorViz; //quantos vivos da proxima gera��o
	
	//copiando Viz em vivas

	for ( i = 0; i < tamV[0]; i++){
		vivas[i].linha = Viz[i].linha;
		vivas[i].coluna = Viz[i].coluna;
	}

}

//fun��o para copiar matriz auxiliar na matriz principal


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

void preencherMat(int tam, int mat[tam][tam], tipo_coord vet[], int tamVetor){

    int i;
    //preechendo vivos na matriz

    for(i=0; i < tamVetor; i++){
        mat[vet[i].linha][vet[i].coluna] = 1;
    }
}



