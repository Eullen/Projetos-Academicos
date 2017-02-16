
#include "Booleano.h"

typedef struct Celula{
	int item;
	struct Celula *next;
}Celula;

typedef struct {
	Celula *inicio;
	int tamanho;
}Lista;

//interfaces
Lista criarListaVazia();
Lista inserirNoInicio(Lista *,int);
Lista mostrarTodos (Lista *);
Lista mostrarKPrimeiros(Lista *, int);
Lista InserirEspec ( Lista *, int, int);
int buscar(Lista listinha,int elemento);
//Implementações
Lista criarListaVazia(){
	
	Lista listinha;
	listinha.inicio = NULL;
	listinha.tamanho = 0;
	return listinha;

}
Lista inserirNoInicio(Lista *listinha,int elemento){
	
	Celula *novoItem;
	novoItem = (Celula*)malloc(sizeof(Celula));
	
	novoItem->item = elemento;
	novoItem->next = listinha->inicio;
		
	listinha->inicio = novoItem;
	listinha->tamanho += 1;
	
}
Lista mostrarTodos (Lista *listinha){
	Celula *ap;
	ap = listinha->inicio;
	
	if(ap==NULL){
		printf("\nVazia!\n");
	}else{
		//varrendo lista
		do{
			printf(" Item: %d \n",ap->item);
			ap=ap->next;
		}while(ap!=NULL);
	}
}
Lista mostrarKPrimeiros(Lista *listinha, int k){
	//verificando vallidade de k
	if((k>=1)&&(k<=listinha->tamanho)){
		Celula *ap;
		int cont;
		ap = listinha->inicio;
		cont = 1; 
		//primeiro item
		printf(" Item: %d \n",ap->item);
		//demais itens
		while(cont!=k){
			ap = ap->next;
			cont++;
			printf(" Item: %d \n",ap->item);
		}
	}
}
Lista InserirEspec ( Lista *listinha, int posInsercao, int newItem){
	//validando k
	Celula *novo, *ap,*ant;
	if((posInsercao>=1)&&(posInsercao<=listinha->tamanho+1)){
		//alocando memória para novo item[
		novo = (Celula*)malloc(sizeof(Celula));
		//preprando novo item
		novo->item = newItem;
		int pos; //cursor da lista
		pos = 1;
		ap= listinha->inicio;
		ant = NULL;
		while(pos!=posInsercao){
			//"andando" na lista com dois ponteiros
			pos++;
			ant = ap;
			ap = ap->next;
		}
		novo->next = ap;
		//colocando item na lista
		if (ant==NULL){//lista vazia
			listinha->inicio = novo;
		}else{
			ant->next = novo;
		}
		listinha->tamanho += 1;
	}	
}

int buscar(Lista listinha,int elemento){
	int pos, cursor;
	Celula *ap;
	pos=0;
	if(listinha.inicio !=NULL){
		ap = listinha.inicio; cursor = 1;
		do{//laço para varrer lista até encontrar ou acabar
			if(ap->item == elemento){
				pos = cursor;
			}else{
				cursor++;
				ap = ap->next;
			}
		}while((pos==0)&&(ap!=NULL));
		
	}
	return pos;
}

void inserirOrdenado ( Lista *listinha, int elemento){ //lista não descrescente
	int pos, cursor;
	Celula *ap, *ant;
	//preparando novo item
	Celula *novo = (Celula*)malloc(sizeof(Celula));
	novo->item = elemento;	
	//buscando posição
	ap=listinha->inicio; 
	ant=NULL;
	while((ap!=NULL)&&( ap->item <= elemento)){
		//buscando posição
		ant = ap; //aponta para atual
		ap = ap->next; //aponta para proximo
	}
	novo->next = ap;
	if (ant==NULL){//inserindo no começo da lista se for vazia ou se for o menor item
		listinha->inicio = novo;
	}else{
		ant->next = novo;	
	}
	listinha->tamanho +=1;		
}
