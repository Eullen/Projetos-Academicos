#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//variaveis globais
typedef struct
{
	int linha;
	int coluna;
} tipo_coord;

int tamMat, Tvivas[1] = {0};
char arq[54];
////////////////////////////////////////////////////////////////////
//preenche vetor com os vivos
int CriarMat(tipo_coord vivas[])
{
	printf("\nInsira as coordenadas das celulas que comecam vivas(Ex: 3,2 para que a celula na coluna 3, linha 2 comecar viva), ou insira 0,0 para continuar:\n\n");
	//ler todas as celulas vivas e colocar num vetor
	int auxLin, auxCol;
	do
	{	
		printf("Celula viva #%i: ", Tvivas[0]+1);
		scanf("%i,%i", &auxLin, &auxCol);
		if ( (auxLin <= tamMat && auxCol <= tamMat) && ( auxLin !=0) ) {
			vivas[Tvivas[0]].linha = auxLin;
			vivas[Tvivas[0]].coluna = auxCol;
			vivas[Tvivas[0]].linha--;
			vivas[Tvivas[0]].coluna--;
			Tvivas[0]++;
		}
		else if ( auxLin!=0 )
			printf("\nCoordenadas não encontradas.\n");
			
	} while ((Tvivas[0] < tamMat*tamMat) && ( auxLin != 0));
	
	return 0;
}

//resetar matriz
void zerarMat(int mat[tamMat][tamMat]){

	int i, j;

	for ( i=0; i<tamMat; i++){
		for(j=0;j<tamMat;j++){

			mat[i][j] = 0;

		}
	}
}

//preenchendo matriz com vetor de vivos
void preencherMat(int mat[tamMat][tamMat], tipo_coord vet[]){

    int i;
    //preechendo vivos na matriz

    for(i=0; i < Tvivas[0]; i++){
        mat[vet[i].linha][vet[i].coluna] = 1;
    }
}

int ExMat(int Mat[][tamMat])
{
  printf("\nMundo:\n\n");
  int i, j;
  for (i = 0; i < tamMat; i++) //imprimir matriz
  {
		for (j = 0; j < tamMat; j++)
		{
            if (Mat[i][j] == 1)
			{
				printf(" * ");
			}
            else
            {
				printf("   ");
            }
		}
    printf("\n");
  }
	return 0;
}

void SMat(tipo_coord vivas[])
{
	FILE *MatF;
	int iQ; 
	/*printf("\nInsira o nome do arquivo a ser salvo (max. 50 caracteres): ");
	fflush(stdin);
	fgets(arq, 50, stdin);
	strcat (arq, ".mat");*/
		
	MatF = fopen("teste", "wb");
	
	
	
	/*int re = 0;
	if (MatF == 0)
	{
		re = 1;
	}*/
	
	iQ = fwrite(vivas, sizeof(tipo_coord), Tvivas[0], MatF);
	fclose(MatF);
	printf("\n\n %d",iQ);
	 if( iQ != Tvivas[0])
	 	{
		 printf("\n\nErro na gravacao");
		}
	 else
	 	{
	 	printf("\nTerminou gravação");
	 	}

}

int LMat(int Mat[][tamMat], tipo_coord vivas[], FILE *MatF)
{
	fread(Mat, sizeof(int), tamMat*tamMat, MatF);
	fread(vivas, sizeof(tipo_coord), Tvivas[0], MatF);
	fread(Tvivas[0], sizeof(int), 1, MatF);
	fclose(MatF);
	return 0;
}

void nextG (tipo_coord vivas[], int Mat[][tamMat])
{
	int i, j;
	tipo_coord vizinhos[8];
	int qtdeViz[1];
	tipo_coord Mortos[tamMat*(tamMat+tamMat-2)]; //vetor de vizinhos mortos
	int contMorto = 0; //cursor de Mortos que estao perto dos vivos
	int vizVivos = 0; //contador de vizinhos vivos
	tipo_coord NewVivas[tamMat*tamMat]; //novo vetor de vivas
	int contNewVivas = 0; //cursor de NewVivas

	//fazer vetor de mortos e contador de vizinhos vivos
	for (i=0; i < Tvivas[0]; i++)
	{
		//gerar vizinhos
		gerarVizinhos(vivas[i].linha, vivas[i].coluna, vizinhos, qtdeViz);

		//verificar todos vizinhos
		for (j=0; j < qtdeViz[0]; j++)
		{
			//se vizinho está morto
			if(Mat[vizinhos[j].linha][vizinhos[j].coluna] == 0)
			{
				//guarda o vizinho
				Mortos[contMorto].linha = vizinhos[j].linha;
				Mortos[contMorto].coluna = vizinhos[j].coluna;
				contMorto++; //avanca cursor
			}
			//se vizinho esta vivo, subir vizVivos
			else
			{
				vizVivos++;
			}
		}

		//verificando se vivo sobrevive
		if((vizVivos == 2) || (vizVivos == 3)){
				//copiar no NewVivas para geração seguinte
				NewVivas[contNewVivas].linha = vivas[i].linha;
				NewVivas[contNewVivas].coluna = vivas[i].coluna;
				contNewVivas++; //avança cursor
		}

		//zerando vizVivos para proxima celula
		vizVivos = 0;
	}

	//verificando quais mortos vao nascer
	int contador;
	for ( i = 0; i < contMorto-1; i++)
	{
		//comecar o contador com 1 pra cada morto
		contador = 1;
		//pular se ja for repitido
		if (Mortos[i].linha != -1)
		{
			for ( j=i+1; j < contMorto; j++)
			{
				//comparando com o resto
				if (( Mortos[i].linha == Mortos[j].linha) && (Mortos[i].coluna == Mortos[j].coluna))
				{
					//marcar como repitido, subir contador
					Mortos[j].linha = -1;
					contador++;
				}
			}
		}

		//nascer se contou 3 repitidos e se nao eh um repitido
		if (( contador == 3) && ( Mortos[i].linha != -1 ))
		{
			//copiar no NewVivas para geração seguinte
			NewVivas[contNewVivas].linha = Mortos[i].linha;
			NewVivas[contNewVivas].coluna = Mortos[i].coluna;
			contNewVivas++; //avançando cursor
		}

	}

	Tvivas[0] = contNewVivas; //quantos vivos da proxima geração

	//copiando NewVivas em vivas
	for ( i = 0; i < Tvivas[0]; i++)
	{
		vivas[i].linha = NewVivas[i].linha;
		vivas[i].coluna = NewVivas[i].coluna;
	}
}

int gerarVizinhos (int lin, int col, tipo_coord viz[], int qtViz[])
{
	//gerando vizinhos caso a linha seja a primeira
	if ( lin == 0 )
	{
		if ( col == 0)
		{

			viz[0].linha = lin;
			viz[0].coluna = col+1;

			viz[1].linha = lin+1;
			viz[1].coluna = col;

			viz[2].linha = lin+1;
			viz[2].coluna = col+1;

			qtViz[0] = 3;
		}
		else if ( col == tamMat-1)
		{
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
	else if ( lin == tamMat-1)
	{
		if ( col == 0)
		{
			viz[0].linha = lin;
			viz[0].coluna = col+1;

			viz[1].linha = lin-1;
			viz[1].coluna = col;

			viz[2].linha = lin-1;
			viz[2].coluna = col+1;

			qtViz[0] = 3;
		}
		else if ( col == tamMat-1)
		{
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
	else if ( (col == 0) && (lin != 0) && (lin != tamMat-1))
	{
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
	else if ( col == tamMat - 1)
	{
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
	else
	{
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

	return 0;
}

int main()
{
	int o,i;
	char opcao;
	
	printf("Jogo da Vida\n\nInsira uma opcao:\n1 para criar um mundo.\n2 para carregar um mundo salvo.\n\nSelecao: ");
	scanf("%i", &o);

	//criar mundo
	if (o == 1)
	{
    printf("\nInsira o tamanho do mundo (Ex: Insira 4 para um mundo 4x4): ");
		scanf("%i", &tamMat);
	}
	//carregar mundo
	else if (o == 2)
	{
		FILE *MatF;
		printf("Insira o nome do arquivo para carregar (max. 50 caracteres): ");
		char arq[50];
		fgets(arq, 50, stdin);
		MatF = fopen(arq, "rb");
		fread(tamMat, sizeof(int), 1, MatF);
		int Mat[tamMat][tamMat];
		tipo_coord vivas[tamMat*tamMat];
		LMat(Mat, vivas, MatF);
		ExMat(Mat);
	}

	//erro
	else
	{
		printf("Entrada invalida.");
		return 0;
	}
	
	int Mat[tamMat][tamMat];
	tipo_coord vivas[tamMat*tamMat];
	
	//primeira geração
	CriarMat(vivas);
	//preenchendo matriz
	zerarMat(Mat);
	preencherMat(Mat,vivas);
	//exibindo matriz
	ExMat(Mat);
	
	//gerando gerações
	do {	
		
		printf("\n Criar nova geracao? Digite S para sim. ");
		fflush(stdin);
		scanf("%c",&opcao);
		if ( opcao == 'S' || opcao == 's' ) {
			//criando nova geração
			nextG(vivas,Mat);
			//zerar matriz e preencher
			zerarMat(Mat);
			preencherMat(Mat,vivas);
			//exibe
			ExMat(Mat);	
		}	
		
	}while ( opcao == 'S' || opcao == 's');
	
	//verificando se usuario quer salvar ultima geração
	printf("\n Deseja salvar a ultima geracao? S/N");
	fflush(stdin);
	scanf("%c",&opcao);
	if ( opcao == 'S' || opcao == 's' ) {
		SMat(vivas);
	}
	
	  


	return 0;
}
