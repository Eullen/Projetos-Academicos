#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

//declarando que funções seram criadas
int entraData( int d[], int m[], int a[] );
int diasNoMes(int m, int a);
int diasFimAno( int d, int m, int a);

void main(){
	
	int dia[1], mes[1] , ano[1];
    
    //verificando data
    printf(" \nData de Nascimento: \n");
  	entraData(dia,mes,ano);
	
	/*
    //chamando função
    diasNoMes(mes, ano);
	
	//calculando dias restantes para o fim do ano
    int diasRestantes = diasFimAno(dia[0], mes[0], ano[0]);
    printf("Dias restantes do ano de %d: %d",ano[0], diasRestantes);
*/
}

//função para calcular qtos dias tem o mês
int diasNoMes(int m, int a){
    int qdias;
    switch(m){
        case 2:
            if( (a%4==0 && a%100!=0) || (a%400==0) )
                qdias=29;
            else
                qdias=28;
            break;
        case 4: case 6: case 9:
        case 11: qdias=30;
            break;
        default: qdias=31;
    }
    return(qdias);
}


//função para verificar data

int entraData( int d[], int m[], int a[] ){
		
		// vari�veis 
		
		int dataOk = FALSE;
		int anoBissexto = FALSE;
		
		//entrada dos dados
		
		do {
			
		printf("\nDigite o dia: ");
		scanf("%d",&d[0]);
		printf("\nDigite o mes: ");
		scanf("%d",&m[0]);
		printf("\nDigite o ano: ");
		scanf("%d",&a[0]);

		//vericando ano
            if( a[0] >= 1000 && a[0] <= 9999 ) {
			     
				 //verificando se o ano e biessexto
				if( (a[0]%4==0 && a[0]%100!=0) || (a[0]%400==0) )
					anoBissexto = TRUE;
            	//verificando mes
				if (m[0] >= 1 && m[0] <= 12) {
					
					//verificando dia
					//verificando meses com 31 dias
					if(m[0] == 1 || m[0] == 3 || m[0] == 5 || m[0] == 7 || m[0] == 8 || m[0] == 10 || m[0] == 12 ) {

                		if ( d[0] > 0 && d[0] <= 31)
	                    	dataOk = TRUE;
                	}
					//verifiando fevereiro
            		else if ( m[0] == 2) {

                		if( d[0] > 0 && d[0] <= 28)
                    		dataOk = TRUE;

                		if ( anoBissexto == TRUE && d[0] == 29)
                    		dataOk = TRUE;
            		}
					//demais meses
           			else {

              			if ( d[0] > 0 && d[0] <= 30)
                    		dataOk = TRUE;

            		}
			
			}

		} 
		
		//imprimindo msg de erro
		if(dataOk == FALSE)		
			printf("\n Data Invalida. Digite novamente.\n ");
		
		
	}while(dataOk == FALSE);
		
		printf(" \n\nData Valida \n");

}


//fun��o para calcular anos vividos

int diasVividos(int anoAnterior){
	
	int anoAtual = DateTime.Now;
	
	
	
	
	
	
}
