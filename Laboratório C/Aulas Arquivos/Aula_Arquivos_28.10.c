#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//estrutura de alunos
typedef struct Aluno {
	int RA;
	char nome[50];
	char email[40];
	
}tipo_aluno;

int gravarAlunosArquivo();
int lerArquivosAlunos();

void main(){
	int n;
	
	gravarAlunosArquivo();	
	
	n = lerArquivosAlunos();
	printf("Total de registros lidos: %d\n",n);
	
}

int gravarAlunosArquivo(){
	
	FILE *arq;
	tipo_aluno aln;
	int fim = FALSE;
	char opcao;
	int qtde = 0;
		
	do
	{
	
	arq = fopen("alunos.dta","wb");
	if ( arq == NULL){
		
		printf("Erro na abertura do arquivo!\n");
		exit(1);
		}
	
	printf(" \nDigite as informações do aluno.");
	printf(" \nRA: ");
	scanf("%d",&aln.RA);
	fflush(stdin);
	printf(" \nNome: ");
	fgets(aln.nome,50,stdin);
	printf(" \nEmail: ");
	fgets(aln.email,40,stdin);
	
	//gravando informações em um arquivo
	
	fwrite(&aln,sizeof(aln),1,arq); //(de onde , tamanho, qtos,onde salvar )
	
	
	//verificando se o usuario quer continuar
	printf(" \nDeseja continuar? s/n");
	scanf("%c",&opcao);
	if((opcao == 'N') || (opcao == 'n')) 
		fim = TRUE;
	}while(!fim);
	
	fclose(arq);
	
}

//função para ler arquivos

int lerArquivosAlunos() {
	
	tipo_aluno aln;
	int qtd = 0;
	//ponteiro para arquivo
	FILE *arq;
	//abrindo arquivo
	arq = fopen("alunos.dta","rb"); //rb = read binary archive
	if ( arq == NULL){
		
		printf("Erro na abertura do arquivo!\n");
		exit(1);
		}
	
	while(!feof(arq)) {
		
		fread(&aln,sizeof(aln),1,arq);
		if(!feof(arq)){
			
		printf("RA: %d\n",aln.RA);
		printf("Nome: %s\n",aln.nome);
		printf("Email: %s\n",aln.email);
		qtd++;
		}
	}
	fclose(arq);
	return qtd;
	
}
