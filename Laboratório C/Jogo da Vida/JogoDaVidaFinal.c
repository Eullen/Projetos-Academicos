#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Projeto Jogo da Vida
//Eullen Silva Viana
//Lucas Pratas Oliveira

//estrutura para armazenar coordenadas
typedef struct
{
	int linha;
	int coluna;
} tipo_coord;
//variaveis globais
int tamMat, Tvivas = 0;
////////////////////////////////////////////////////////////////////

//preenche vetor com os vivos e define os parametros do mundo
int CriarMat(tipo_coord vivas[])
{
	printf("\nInsira as coordenadas das celulas que comecam vivas.\n [Ex: 3,2 ( Linha 3 e coluna 2 ]\nDigite 0,0 para executar as proximas intrucoes.\n\n");
	//ler todas as celulas vivas e colocar num vetor
	int auxLin, auxCol,i,j;
	do
	{
		printf("Celula viva #%i: ", Tvivas+1);
		scanf("%i,%i", &auxLin, &auxCol);
		//validando e salvando informações recebidas
		if ( (auxLin <= tamMat && auxCol <= tamMat) && ( auxLin !=0) ) {
			vivas[Tvivas].linha = auxLin;
			vivas[Tvivas].coluna = auxCol;
			vivas[Tvivas].linha--;
			vivas[Tvivas].coluna--;
			Tvivas++;
		}
		else if ( auxLin!=0 )
			printf("\nCoordenadas não encontradas.\n");

	} while ((Tvivas < tamMat*tamMat) && ( auxLin != 0));
		
	return 0;
}

//resetar matriz
void zerarMat(int mat[][tamMat])
{
	int i, j;
	//preenchendo matriz com 0
	for ( i=0; i<tamMat; i++)
	{
		for(j=0; j<tamMat; j++)
		{
			mat[i][j] = 0;
		}
	}
}

//preenchendo matriz com vetor de vivos
void preencherMat(int mat[][tamMat], tipo_coord vet[])
{
	int i;
	//preechendo vivos na matriz
	for(i=0; i < Tvivas; i++)
	{
		mat[vet[i].linha][vet[i].coluna] = 1;
	}
}

//exibir matriz
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
				printf(" * "); //vivo
			}
            else
            {
				printf("   "); //morto
            }
		}
    printf("\n");
  }
	return 0;
}
//função usada para salvar mundo
void SMat(tipo_coord vivas[])
{
	FILE *MatF; //ponteiro para arquivo
	int iQ = 0, Tarq;
	char arq[56];

	printf("\nDigite o nome do arquivo a ser salvo.\n(Sem extensao e max. 50 caracteres): ");
	fflush(stdin);
	fgets(arq, 50, stdin);
	//remover \n no final de arq
	Tarq = strlen(arq);
	if (arq[Tarq-1] == '\n')
	{
		arq[Tarq-1] = '\0';
	}
	//adicionar extencao
	strcat (arq, ".mundo");

	MatF = fopen(arq, "w+b"); //abrindo arquivo
	iQ += fwrite(&tamMat, sizeof(int), 1, MatF); //salvando tamanho da matriz
	iQ += fwrite(&Tvivas, sizeof(int), 1, MatF); //salvando qtde de vivos na geração
	iQ += fwrite(vivas, sizeof(tipo_coord), Tvivas, MatF); //salvando coordenadas do ind. vivos
	fclose(MatF); //fechando arquivo
	if( iQ != Tvivas + 2) //verificando se o arq. foi gravado
	{
		printf("\nErro de gravacao.\n");
	}
	else
	{
		printf("\nGravacao efetuada com sucesso\n");
	}
}
//função para carregar mundo salvo 
void LMat(FILE* MatF, tipo_coord vivas[])
{
	fread(&Tvivas, sizeof(int), 1, MatF); //lendo  qtde de vivas do arquivo arquivo
	fread(vivas, sizeof(tipo_coord), Tvivas, MatF);
	char q;
	if ((q = fgetc(MatF)) == EOF)
	{
		printf("\nArquivo carregado com sucesso.\n");
	}
	else
	{
		printf("\nArquivo não encontrado. Verifique o nome e tente novamente.\n");
	}
	fclose(MatF);
}
//função para gerar os vizinhos
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

void nextG (tipo_coord vivas[], int Mat[][tamMat])
{
	int i, j;
	tipo_coord vizinhos[8]; //vetor para armazenar vizinhos gerados
	int qtdeViz[1];
	tipo_coord Mortos[tamMat*(tamMat+tamMat-2)]; //vetor de vizinhos mortos
	int contMorto = 0; //cursor de Mortos que estao perto dos vivos
	int vizVivos = 0; //contador de vizinhos vivos
	tipo_coord NewVivas[tamMat*tamMat]; //novo vetor de vivas
	int contNewVivas = 0; //cursor de NewVivas

	//fazer vetor de mortos e contador de vizinhos vivos
	for (i=0; i < Tvivas; i++)
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

	Tvivas = contNewVivas; //qtde de celuas vivas na proxima geração

	//copiando NewVivas em vivas
	for ( i = 0; i < Tvivas; i++)
	{
		vivas[i].linha = NewVivas[i].linha;
		vivas[i].coluna = NewVivas[i].coluna;
	}
}

int main()
{
	char o;
	int i,j;
	FILE *MatF;
	do
	{
		printf("Jogo da Vida\n\nInsira uma opcao:");

		do
		{
			printf("\n1 Criar um mundo.\n2 Carregar um mundo salvo.\n3 Fechar o programa.\n\nSelecao: ");
			fflush(stdin);
			scanf("%c", &o);

			//criar tamMat
			if (o == '1')
			{
				//recebendo tamanho base do mundo
				printf("\nInsira o tamanho do mundo (Ex: Insira 4 para um mundo 4x4): ");
				fflush(stdin);
				scanf("%i", &tamMat);
				
				//imprimindo mundo com cooordenadas
	
				for ( i =0 ; i < tamMat; i++){
					for(j=0; j<tamMat; j++){
						printf(" %d,%d ",i+1,j+1);
					}
					printf("\n");
				}
			}

			//carregar tamMat
			else if (o == '2')
			{
				char arq[56];
				printf("\nInsira o nome do arquivo: ( Sem extensao e max. 50 caracteres): ");
				fflush(stdin);
				fgets(arq, 50, stdin);
				//remover \n no final de arq
				char Tarq = strlen(arq);
				if (arq[Tarq-1] == '\n')
				{
					arq[Tarq-1] = '\0';
				}
				//adicionar extencao
				strcat (arq, ".mundo");
				//se abrir arquivo, continuar
				if ((MatF = fopen(arq, "rb")) != 0)
				{
					fread(&tamMat, sizeof(int), 1, MatF);
				}
				//se arquivo nao for aberto, loopar pro comeco
				else
				{
					printf("\nArquivo invalido.");
					o = '0';
				}
			}

			//sair
			else if (o == '3')
			{
				printf("\nPrograma finalizado.");
			}

			//erro
			else
			{
				printf("\nEntre uma opcao valida:");
			}
		} while((o != '1') && (o != '2') && ( o != '3' )); //repitir ate escolher uma opcao valida

		//continuacao
		tipo_coord vivas[tamMat*tamMat];
		//criar Tvivas e vivas
		if (o == '1')
		{
			CriarMat(vivas);
		}
		//carregar Tvivas e vivas
		else
		{
			LMat(MatF, vivas);
		}

		int Mat[tamMat][tamMat];
		//preenchendo matriz
		zerarMat(Mat);
		preencherMat(Mat, vivas);
		//exibindo primeira geração
		ExMat(Mat);

		//gerando gerações
		do
		{
			printf("\nDigite S se deseja criar a proxima geracao: ");
			fflush(stdin);
			scanf("%c", &o);
			if (( o == 'S') || (o == 's'))
			{
				//criando nova geração
				nextG(vivas,Mat);
				//zerar matriz e preencher
				zerarMat(Mat);
				preencherMat(Mat,vivas);
				//exibe
				ExMat(Mat);
			}
		} while (( o == 'S') || (o == 's'));

		//verificando se usuario quer salvar ultima geração
		printf("\nDigite S se deseja salvar a ultima geracao: ");
		fflush(stdin);
		scanf("%c",&o);
		if (( o == 'S') || (o == 's'))
		{
			SMat(vivas);
			printf(" \nPressione Enter para continuar.");
			getchar();
		}
		printf("\n----------------------------------------------------------\n\n");
	} while(o != '3');
	return 0;
}
