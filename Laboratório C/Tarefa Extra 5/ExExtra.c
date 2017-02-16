#include<stdio.h>
#include<stdlib.h>

void lerVetor(float v[],int cont[])
{
    float temp;
    cont[0]=-1; // para n�o come��o do 0
    int i = 0;

    printf("Digite as componentes do vetor: \n");
    printf("ou 0 para encerrar\n");

    do
    {
        printf("Valor #%d:", i+1);
        scanf("%f", &v[i]);
        cont[0]++;
        i++;

    }while( v[i-1]!=0 && cont[0] < 100 );
    printf("\n");
}

void exibirVetor( float v[ ], int tv )
{
    int k;
    for( k = 0; k < tv; k++ )
    {
        printf("%d: ",k+1);
        printf("componente:%.2f\n",v[ k ] );
    }
    printf("\n");
}

//Ordenação pelo método da Bolha
void ordenarVetor( float v[], int cont )
{
    int conta, j, t = cont-1;
    float temp;
    for( conta = 1; conta < cont; conta++ )
    {
        for( j = 0; j < t; j++ )
        {
            if( v[j] > v[j+1] )
            {
                temp = v[j]; v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
        t = t-1;
    }
}

void intercalarVetor(float v[],float v2[],float v3[], int cont,int cont2)
{
    int k=0,j=0,l=0,i,sentinela=-1; // sentinela é usada para para o loop while quando um dos vetores for varrido
    if(v[k]==0) sentinela=0;//checa se o vetor é vazio, se for ele não entra no laço while
    if(v2[j]==0) sentinela=1;//checa se o vetor é vazio, se for ele não entra no laço while
    while(sentinela!=0 && sentinela!=1)// o valor da sentinela deverá ser ou 0 ou 1 para depois varrer o vetor que ainda nao acabou de ser varrido
    //o loop verificará se um valor é maior, menor ou igual a posição do outro vetor e acumular até que algum vetor seja varrido completamente
    {

        if(v[k]<v2[j])
        {
            v3[l]=v[k];
            k++;//avançando o cursor do vetor 1

        } else if(v[k]==v2[j])
                {
                    v3[l]=v[k];
                    v3[l+1]=v2[j];
                    l++;//avançando o cursor do vetor 3, pois se há igualdade o vetor ocupará 2 posições
                    k++;//avançando o cursor do vetor 1
                    j++;//avançando o cursor do vetor 2

                }else if(v[k]>v2[j])
                    {
                        v3[l]=v2[j];
                        j++;//avançando o cursor do vetor 2
                    }
        // se o cursor for igual ao contador(que tem o numero de posições do vetor) significa que o vetor foi varrido completamente
        if(k==(cont)) sentinela=0;
        if(j==(cont2)) sentinela=1;

        l++;//avançando o cursor do vetor 3
    }

    if(sentinela==1)//Varrendo o vetor 1 pois o vetor 2 já foi varrido
    {
        for(i=l;i<=cont+cont2;i++)// a variável i é acumulada em 'l' pois é aonde o vetor 3 vai receber a próxima posição
        {
              v3[i]=v[k];
              k++;
        }
   }
   if(sentinela==0)//Varrendo o vetor 2 pois o vetor 1 já foi varrido
    {
        for(i=l;i<=cont+cont2;i++)// i deve ser menor que (cont+cont2) pois é o tamanho de alocação somando os vetores 1 e 2
        {
            v3[i]=v2[j];
            j++;
        }
    }


}


void main()
{

    float v[100],v2[100],v3[100+100];
    int cont[1],cont2[1];

    lerVetor(v,cont); //lendo primeiro vetor
    lerVetor(v2,cont2); //lendo segundo vetor
    ordenarVetor(v,cont[0]); //ordenando primeiro vetor
    ordenarVetor(v2,cont2[0]); //ordenando segundo vetor
    printf("\n");//pula linha
    intercalarVetor(v,v2,v3,cont[0],cont2[0]); //intercalando os vetores
    exibirVetor(v3,(cont[0]+cont2[0])); //exibindo vetor intercalado

}
