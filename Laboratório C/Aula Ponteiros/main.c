#include <stdio.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void subtrair(int a, int b, int *p);

void trocar(int *p, int *py);


//struct com ponteiro

typedef struct _aluno{
	
	char nome[50];
	char ra[20];
	int idade;	
	
}Aluno;

void testeStruct(Aluno *pontA);

int main() {

	// Ponteiros
	
	int x=10, y=25;
	
	//declaracao de ponteiro
	
	int *px;  // criação de uma variável do tipo ponteiro
	int *py;
	
	px = &x; // atribuindo valor 
	py = &y;
		
	printf("\n x=%d",x); // imprimindo variável x
	printf("\n x=%d",*px); // imprimindo conteudo do ponteiro
	printf("\n End de x = %0xd", px); // imprimindo locação de memoria do ponteiro
	
	// subtraindo com ponteiros
	
	subtrair(x,y,px);
	printf("\n x=%d",*px); // imprimindo conteudo do ponteiro
	
	//trocando ponteiros
		
	trocar(px,py);
	printf("\n x=%d",*px); // imprimindo conteudo do ponteiro	x
	printf("\n y=%d\n\n\n",*py); // imprimindo conteudo do ponteiro	y
		
	//Parte 3	
		
	//usando o struct com ponteiros
	
	Aluno a;	//a do tipo Aluno
	Aluno *pa = NULL; //para evitar que o ponteiro use áres de memória que não deve . Aponta para posição zero
	pa = &a;			// apontando ponteiro para a
	
	//chamando a função que preenche os campos do struct	
	testeStruct(pa);
	
	//imprimindo
	printf(" \n\n IMP: \n");
	printf(" Aluno: %s ", pa->nome);	
	printf(" RA: %s ", pa->ra);
	printf(" Idade: %d", pa->idade);

	// criando novo aluno com alocação dinâmica
	
	Aluno *pb = NULL;
	//alocando dinamicamente
	pb = (Aluno*)malloc(sizeof(Aluno));
	
	testeStruct(pb);
	
	//imprimindo
	printf(" \n\n IMP 2: \n");
	printf(" Aluno 2: %s ", pb->nome);	
	printf(" RA 2: %s ", pb->ra);
	printf(" Idade 2: %d", pb->idade);
	
	//liberar memoria
	free(pb);
	
	return 0;	
	
}

void subtrair(int a,int b,int *p){
	
	*p = a - b; //acessando conteudo
		
}

// função para troc\r valores

void trocar(int *p, int *q){
	
	int aux = *p; //aux recebe cont. de p
	*p = *q;		//trocando valores dos pont.
	*q = aux;
	
	
}

void testeStruct (Aluno *pontA){
	
	scanf("%s",pontA->nome); //preenchendo a.nome
	scanf("%s",pontA->ra);  //preenchendo a.RA
	scanf("%d",&pontA->idade); //preenchendo a.idade
	printf("\n\n");
}
