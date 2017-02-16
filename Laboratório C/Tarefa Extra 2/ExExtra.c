#include <stdio.h>
#include <stdlib.h>
#define YEAR 2
#define MES 12

	typedef struct _inflacao {

		float indice[12]; //vetor para armazenar os dados da inflação de cada mes
		float ACUM;
	    float TRI[8]; // acumula a taxa de infalçao por trimestre
	
		}inflacao;

	int main(){

	inflacao ANO[2];
	int i,j,k=0, cont=0;
    char meses[12][20]={"JANEIRO  ","FEVEREIRO","MARCO    ","ABRIL    ","MAIO    ","JUNHO   ","JULHO   ","AGOSTO  ","SETEMBRO","OUTUBRO ","NOVEMBRO","DEZEMBRO"}; //declaração dos meses a serem impressos na tela



    printf("Digite para cada ano as inflacoes mensais:\n");

	for(i=0;i<YEAR;i++){
		printf("Ano %d\n",i+1);// Contagem do ano

		for(j=0;j<MES;j++){
			printf("Mes: %d ",j+1);
			scanf("%f",& ANO[i].indice[j]); //fazendo a leitura de dados de cada mes do respectivo ano
			}
		printf("\n");
	}

	for(i=0;i<YEAR;i++){
		ANO[i].ACUM=1;
		for(j=0;j<MES;j++){

			ANO[i].ACUM = ANO[i].ACUM*( 1 + ANO[i].indice[j]/100 );//calculando a inflação e acumulando na variável

            if((j+1)%3==0){
                    ANO[i].TRI[k]=(ANO[i].ACUM-1)*100; //este if zera a taxa de inflação a cada 3 meses
                    k++;
                    ANO[i].ACUM=1; // aqui é onde se zera a taxa de inflação
                    }
		}
		k=0; //variavel controladora do mês
	}

    printf("IGP\t\t\t2003\t\t2004\t\t\n\n");
	for(i=0;i<1;i++){
		for(j=0;j<MES;j++){
			printf("%s\t\t%.2f\t\t%.2f\t\t\n",meses[j],ANO[i].indice[j],ANO[i+1].indice[j]); // imprimi os meses e a taxa de inflação de cada mes dos 2 anos
		}
    printf("\n");
	}	

    for(i=0;i<YEAR;i++){
        for(k=0;k<4;k++) //a variavel k vai até 4 pois são as quantidades de trimestres anuais
            printf("Inflacao #%d trimestre / ano #%d: %.2f\n",k+1,i+1,ANO[i].TRI[k]); //imprimindo os valores de saída
        	
        printf("\n");
 	}
	return 0;
}

