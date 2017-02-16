#include<stdio.h>
#include<stdlib.h>
#define TAM 10

// estrutura para armazenar dados dos produtos
typedef struct _propriedades{

 int codigo,quant;
 float valor;
} prop;

int main (){

//declaação de variáveis
int i,total=0;
float totalV=0.00f;
prop produto[TAM]; // vetor pára armazenar produtos e suas propriedades

//entrada de dados
for(i=0;i<TAM;i++){
    printf("insira o codigo do produto #%d: ",i+1);
    scanf("%d",&produto[i].codigo);
    printf("insira a quantidade disponivel: ");
    scanf("%d",&produto[i].quant);
    printf("insira o valor do produto: ");
    scanf("%f",&produto[i].valor);
    printf("\n");
    //cálculo dos totais
    total=total+produto[i].quant;
    totalV= totalV+produto[i].valor;
}
printf("Valor total dos produtos em estoque: %.2f \n",totalV);

for(i=0;i<TAM;i++){

    if(produto[i].quant< (total*0.05)){
        printf("O produto de codigo: %d esta com estoque abaixo de 5 por cento.\n",produto[i].codigo);
    }

}

}
