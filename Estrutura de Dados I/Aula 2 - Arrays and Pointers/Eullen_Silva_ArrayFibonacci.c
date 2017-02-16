/* Template - atividade

  Arquivo: Eullen_Silva_ArrayFibonacci.c
  Autor: Eullen Silva
  Date: 24/08/16 10:02
  Descrição: Exercícios da Aula 2 - Array Fibonacci .

*/

#include <stdio.h>
void fibonacci (int n, double arrayFib []);
double fibonacciRecursiva ( int n);

main(){
		int n = 10;
		double fibonacciArray[n];
		/*//chamando primeira função 
		fibonacci(n,fibonacciArray); 
		//imprimindo array
		int i;
		for(i=0;i<n;i++) printf("%.0f\n",fibonacciArray[i]);
		*/
		
		//usando recursividade
		int indice;
		for (indice=1;indice<=n;indice++){
			fibonacciArray[indice] = fibonacciRecursiva(indice);
		}
		//imprimindo array
		int i;
		for(i=0;i<n;i++) printf("%.0f\n",fibonacciArray[i]);
		
		system("PAUSE");
}

void fibonacci (int n,double arrayFib []){
	int contOperacoes = 0;
	arrayFib[0] = 1; //preenchendo primeiro valor
	if (n >= 2 )
	{
		arrayFib[1] = 1; //preenchendo segundo valor
		int indice;
		for(indice=2;indice < n;indice++)
		{
			arrayFib[indice] = arrayFib[indice-1] + arrayFib[indice-2];
			contOperacoes += 1;
		}
	}
	printf("Esse metodo realizou %d operacoes\n",contOperacoes);	
}

double fibonacciRecursiva ( int n){
	
	double f, contOperacoes = 0;
	if (n==1) f=1;
	else if (n==2) f=1;
	else f = (fibonacciRecursiva(n-1)) + (fibonacciRecursiva(n-2));
	return f;

}
