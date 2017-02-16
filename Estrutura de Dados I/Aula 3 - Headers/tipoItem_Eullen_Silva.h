/* Exemplo - arquivo header - aula 2
  Arquivo: tipoItem_Eullen_Silva.h
  Autor: Eullen Silva Viana
  Date: 31/08/16 09:12
  Descrição: Este arquivo define um tipo chamado TipoItem
*/

#include<stdlib.h>


// definição do tipo TipoItem
typedef struct {
	int qtd;
	double custo;
} TipoItem;

// interface

TipoItem criarNovo(int,double);
void mostrarItem(TipoItem);
       

// implementações

TipoItem criarNovo(int q, double c){
	//criando item do Tipo definido
	TipoItem item;
	//preenchendo valores
	item.qtd = q;
	item.custo = c;
	return item;
}

void mostrarItem(TipoItem item){
	//mostrar item do tipo criado
	printf("Item  - Quantidade: %d Custo: %.2f \n\n",item.qtd,item.custo);
}
