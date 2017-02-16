/* Exemplo teste de um arquivo header
  Arquivo: testeItem_Eullen_Silva.c
  Autor: Eullen Silva Viana	
  Date: 31/08/16 09:12
  Descrição: Este exemplo mostra um programa que serve para testar um arquivo header.
*/

# include <stdlib.h>
# include "tipoItem_Eullen_Silva.h"
        
main(){
       TipoItem p1,p2;
       p1 = criarNovo(56,1234.8);
       p2 = criarNovo(4,100.5);
       mostrarItem(p1);
       mostrarItem(p2);
       printf("\n\n");
       system("pause");
}
