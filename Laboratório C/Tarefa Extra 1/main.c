#include <stdio.h>
#include <stdlib.h>

#define M 10

#define TRUE 1
#define FALSE 0

int main()
{
	//sentinela
	
	int fim = FALSE;
	
	 //declaraÃ§Ã£o de variveis
    int controle,N,K,i,j, somaMochila = 0, somaFora = 0;

    //entrada de dados N e K
    printf("\nDigite o valor de N: ");
    scanf("%d",&N);
    printf("\nDigite o valor de K (Decremento): ");
    scanf("%d",&K);

    //declarando vetores
    int mochila[M];
    int sequencia[N];

     // entrada dos dados especÃ­ficos
    // numeros da sequencia

    printf("\nElementos a serem colocados na mochila:");
	
	// imprimindo primeiro numero da sequencia que é N
	sequencia[0] = N ;
    printf(" %d ", sequencia[0]);
	
	// atribuindo valor ao contador
	i = 1;
	
	// determinando todos os termos positivos da sequência
	do	{
		//verificando se o numero ainda é positivo
		if( (i >= N) || ( sequencia[i-1] - K <= 0) )
			fim = TRUE ;
		else	{
			sequencia[i] = sequencia[i-1] - K;
			printf(" %d ", sequencia[i]);
			i++;
		}
	} while(!fim);
	
	// iniciando controle
	if ( i <= M ) controle = i;
	else controle = M;
    //elementos que entraram na mochila e que ficaram fora
    
    for(j=0; j < controle ; j++ ){
			//elementos que entraram na mochila
			mochila[j] = sequencia[j];
			printf("\nDentro da Mochila: %d ", mochila[j]);
			somaMochila += mochila[j];	
			
	}
	
	if ( i <= M){
			
		printf("\nSoma do que esta dentro da mochila: %d ", somaMochila);
					
	}
	else {
		
		//qtde de elementos fora da mochila
		int foraMochila[i - M];
		// elementos que não entraram na mochila
		
		for( j ; j < i  ; j++){
			
			foraMochila[j] = sequencia[j];
			printf(" \nFora da mochila: %d ", foraMochila[j]);
            somaFora += foraMochila[j];
			
		}
		//imprimindo somas
		printf("\nSoma do que esta dentro da mochila: %d ", somaMochila);
		printf("\nSoma do que esta fora da mochila: %d ", somaFora);
		
	}
}



