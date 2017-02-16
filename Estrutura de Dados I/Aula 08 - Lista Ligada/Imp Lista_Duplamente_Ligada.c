
#include <stdio.h>
#include <stdlib.h>
#include "Lista_Ligada_Duplamente_Ligada.h"

main(){
	Lista q;
	q = criarListaVazia();
//	inserirNoInicio(&q,25);
//	inserirNoInicio(&q,10);
	InserirEspec(&q,1,15);
	InserirEspec(&q,1,20);
	InserirEspec(&q,1,10);
	InserirEspec(&q,2,25);
	InserirEspec(&q,5,90);
	printf("\n\n");
//	mostrarKPrimeiros(&q,3);
//	int pos = buscar(q,56);
//	printf(" \n\n Posicao do item : %d",pos);	
	printf("\n\n");
	mostrarTodos(&q);

	
}


