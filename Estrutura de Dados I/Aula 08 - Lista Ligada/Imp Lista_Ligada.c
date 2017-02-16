
#include <stdio.h>
#include <stdlib.h>
#include "Lista_Ligada.h"
main(){
	Lista q;
	q = criarListaVazia();
//	inserirNoInicio(&q,25);
//	inserirNoInicio(&q,10);
//	InserirEspec(&q,2,15);
//	InserirEspec(&q,4,20);
//	mostrarKPrimeiros(&q,3);
//	int pos = buscar(q,25);
//	printf(" \n\n Posicao do item : %d",pos);	
//	printf("\n TAM: %d\n\n",q.tamanho);
	inserirOrdenado(&q,2);
	inserirOrdenado(&q,3);
	inserirOrdenado(&q,5);
	inserirOrdenado(&q,1);
	inserirOrdenado(&q,4);		
	mostrarTodos(&q);

	
}


