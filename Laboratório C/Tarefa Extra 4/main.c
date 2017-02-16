#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

//declarando que funÃ§Ãµes seram criadas
int entraData( int d[], int m[], int a[] );
int diasNoMes(int m, int a);
int dV(int dNasc, int mNasc, int aNasc );

void main(int argc, char** argv) {


	int dia[1], mes[1] , ano[1];
    //verificando data
    printf(" \nData de Nascimento: \n");
  	entraData(dia,mes,ano);

	//calculando

	diasNoMes(mes[0],ano[0]);

	dV(dia[0],mes[0],ano[0]);


}

//funÃ§Ã£o para calcular qtos dias tem o mÃªs
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


//funÃ§Ã£o para verificar data

int entraData( int d[], int m[], int a[] ){

		// variáveis

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
            if( a[0] >= 1000 && a[0] <= 2999 ) {

				 //verificando se o ano e biessexto
				if( (a[0]%4==0 && a[0]%100!=0) || (a[0]%400==0) )
					anoBissexto = TRUE	;
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

//dias passados no ano

int contDias(int d, int m, int a){
    int qdias, mesvar;
    qdias = d;
    for( mesvar = 1; mesvar < m ; mesvar ++){

		qdias = qdias + diasNoMes(mesvar,a);
    }
    return(qdias);
}

//função para calcular anos vividos

int dV(int dNasc, int mNasc, int aNasc ){

	//declaração de vari[aveis

	int i, diasVividos = 0, bissexto = 0, diasAno=365;
	//variável bissexto usada para somar +1 dia se o ano do nascimento foi bissexto

	//pegando data do sistema

	char dataAtual [9];

	_strdate ( dataAtual );

	// separando a data

	char diaAtual[3] = {dataAtual[3],dataAtual[4],0};

	char mesAtual[3] = {dataAtual[0],dataAtual[1],0};

	char anoAtual[5] = {dataAtual[6],dataAtual[7],dataAtual[8],dataAtual[9],0};

	// transformando char em int

	int dia = atoi ( diaAtual) ;

	int mes = atoi ( mesAtual);

	int ano = atoi ( anoAtual ) + 2000;

   // calculando dias passados do nascimento até o fim do ano de nascimento

    if ( (aNasc%4==0 && aNasc%100!=0) || (aNasc%400==0) ) bissexto=1; //se o ano do nascimento for bissexto, nele é incrementado +1 ida
	if ( aNasc == ano) diasAno = 0;

	//calculando dias passados no ano de nascimento

   	diasVividos = diasAno + bissexto - contDias(dNasc,mNasc,aNasc) ;

    //calculando dias dos anos ( depois do nascimento até um ano antes do atual )

   for( i = aNasc+1; i < ano; i++ ){

   		diasVividos += diasAno;

   		if( (i%4==0 && i%100!=0) || (i%400==0) ) diasVividos += 1;

    }

   //calculando dias passados do ano atual

   diasVividos += contDias(dia,mes,ano);


   printf("\n\n O individuo viveu: %d dias\n\n",diasVividos);

}
