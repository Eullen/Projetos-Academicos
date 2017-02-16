#include <stdio.h>

//declarando funções
void lerFracao ( int n[], int d[]);

void exibirFracao ( int n, int d);

int mdc ( int a, int b);

int mmc ( int a , int b);

void somarFracao ( int nRes[], int dRes[] );

void subtrairFracao ( int nRes[], int dRes[] );

void multiplicarFracao ( int nRes[], int dRes[] );

void dividirFracao ( int nRes[], int dRes[] );

void inverterFracao ( int nRes[], int dRes[]);

void reduzirFracao ( int nRes[], int dRes[]);


int main(int argc, char** argv) {
	 
	int num[1], den[1]; //armazenar fração original
	int auxNum[1],auxDen[1];  // armazenar valores alterados da fração original
	int op;
	
	//escolhendo o que fazer com as frações
	
	printf(" Digite: \n 1 - Somar Fracoes\n 2 - Subtrair Fracoes\n 3 - Multiplicar Fracoes\n 4 - Dividir Fracoes\n 5 - Reduzir Fracao\n 6 - Inverter Fracao \n\n");
	scanf("%d", &op);
	
	switch (op)	{
		
		case 1:
			somarFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		case 2:
			subtrairFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		case 3:
			multiplicarFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		case 4:
			dividirFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		case 5:
			reduzirFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		case 6:
			inverterFracao(auxNum,auxDen);
			exibirFracao(auxNum[0],auxDen[0]);
			break;
		default:
			printf("\nOpcao invalida\n");	
			break;	
	};
	
	return 0;
}


//função para ler fração

void lerFracao ( int n[], int d[]){
	
	int aux;
	
	//recebe fração e verifica se o denominador é diferente de 0
	do {		
	printf(" Digite uma fracao. \n Numerador: ");
	scanf("%d",&n[0] );
	printf("Denominador: ");
	scanf("%d",&aux);
	
	if ( aux == 0 )
		printf( " \nDenominador invalido. Tente novamente \n");
	else 
		d[0] = aux;

	}while( aux == 0);
	
}

//função para exibir uma fração

void exibirFracao ( int n, int d){
	
	if ( n%d == 0) {
		printf("\n A fracao %d/%d pode ser dividida. Resultado: %d",n,d,(n/d));
	}
	else{
		printf( "\n Fracao: %d/%d",n,d);
	}
	
}

//função para encontar o mdc de dois numeros

int mdc ( int a, int b){
	
	while ( a != b ){
	
	if ( a > b )
		
		a = a - b;
	else
		b = b -a;	

	}
	
	return a;
	
}

//função para encontrar o mmc de dois números

int mmc ( int a , int b){
	
	// base teorica mmc(a,b) x mdc(a,b) = a x b;
	
	int maxdiv = mdc(a,b);	
	int mmc = (a*b)/maxdiv;

}


//função para somar frações

void somarFracao ( int nRes[], int dRes[] ){
	
		int num1[1], den1[1], num2[1],den2[1]; //armazenar numeradores e denominadores
		
		//recebendo primeia fração
		
		lerFracao(num1,den1);
		
		//recebendo segunda fração
		lerFracao(num2,den2);
		
		//somando 
		
		//verificando denominadores
		
		//iguais
		if ( den1[0] == den2[0]){
			
			nRes[0] = num1[0] + num2[0]; // numerador recebe a soma
			dRes[0] = den1[0];			//denominador recebe o da primeira fração

		}
		//diferentes
		else{
			
			// calculando mmc entre os denominadores
			int minMult = mmc(den1[0],den2[0]);
			//calculando numerador
			nRes[0] = (minMult/den1[0] * num1[0]) + (minMult/den2[0] * num2[0]);
			dRes[0] = minMult;
		}

}

//função para subtrair fração
void subtrairFracao ( int nRes[], int dRes[] ){
	
		int num1[1], den1[1], num2[1],den2[1]; //armazenar numeradores e denominadores
		
		//recebendo primeia fração
		
		lerFracao(num1,den1);
		
		//recebendo segunda fração
		lerFracao(num2,den2);
		
		//somando 
		
		//verificando denominadores
		
		//iguais
		if ( den1[0] == den2[0]){
			
			nRes[0] = num1[0] - num2[0]; // numerador recebe a soma
			dRes[0] = den1[0];			//denominador recebe o da primeira fração

		}
		//diferentes
		else{
			
			// calculando mmc entre os denominadores
			int minMult = mmc(den1[0],den2[0]);
			//calculando numerador
			nRes[0] = (minMult/den1[0] * num1[0]) - (minMult/den2[0] * num2[0]);
			dRes[0] = minMult;
		}

}

//funcao para multiplicar fracoes

void multiplicarFracao ( int nRes[], int dRes[] ){
	
		int num1[1], den1[1], num2[1],den2[1]; //armazenar numeradores e denominadores
		//recebendo primeia fração
		lerFracao(num1,den1);
		//recebendo segunda fração
		lerFracao(num2,den2);
		//multiplicando
		nRes[0] = num1[0] * num2[0];
		dRes[0] = den1[0] * den2[0];
		
}

//funcao para dividir fracoes
void dividirFracao ( int nRes[], int dRes[] ){
	
		int num1[1], den1[1], num2[1],den2[1]; //armazenar numeradores e denominadores
		//recebendo primeia fração
		lerFracao(num1,den1);
		//recebendo segunda fração
		lerFracao(num2,den2);
		//dividindo
		nRes[0] = num1[0] * den2[0];
		dRes[0] = den1[0] * num2[0];
		
}


//função para inverter fracao

void inverterFracao ( int nRes[], int dRes[]){
	
	int n[1], d[1]; // armazear denominador e numerador
	
	lerFracao(n,d); //recebendo fração
	//invertendo
	nRes[0] = d[0];
	dRes[0] = n[0];
	
}

//funcao para reduzir uma fracao

void reduzirFracao ( int nRes[], int dRes[]){
	
	//declarando variaveis
	int n[1], d[1];
	//recebendo fracao
	lerFracao(n,d);
	//calculando mdc
	int maxDiv = mdc(n[0],d[0]);
	//divindo numerador e denominador pelo mdc para reduzir a fracao
	nRes[0] = n[0]/maxDiv;
	dRes[0] = d[0]/maxDiv;
		
}
