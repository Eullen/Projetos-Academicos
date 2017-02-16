/* Lista de inteiros */
/*
  Arquivo: ListaInteiros_EullenSilva.c
  Autor: Eullen Silva	
  Date: 21/09/16 09:15
  Descrição: Testar o TAD ListaInt
*/

#include "TipoListaInteiro_EullenSilva.h"

main(){
	
	ListaInt a;
	int tamanho,valor,p,item;
	p=7;
	item = 250; 
	
	printf("TESTE com a lista a:\n");
	a = construirListaRam(8,1,999);
	mostrarLista(a);
	printf("\n");
	//tamanho da lista
	printf("tamanho da lista = %d\n",obterTamanho(a));
	printf("\n");
	//elemento da lista
	printf("elemento de ordem %d = %d\n",p,obterElemento(a,7));
	printf("\n");
	//inserir item
	printf("inserindo elemento %d no final da lista\n",item);
	a = inserirNoFim(a,item);
	mostrarLista(a);
	printf("\n");
	//Novo tamanho da lista
	printf("tamanho da lista = %d \n",obterTamanho(a));
	printf("\n");
	//ordenando itens
	printf("colocando em ordem crescente\n");
	a = sorting(a);
	mostrarLista(a);

	printf("\n\n");
	system("pause");
	
}
