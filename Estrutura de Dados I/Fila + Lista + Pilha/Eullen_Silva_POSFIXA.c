/* Conversão INFIXA->POSFIXA e avaliação de POSFIXA */
/*
  Arquivo: Eullen_Silva_POSFIXA.c
  Autor: Eullen Silva	
  Date: 31/10/16 20:55
  Descrição: Converte INFIXAs originárias de arquivo texto, avalia posfixas resultantes e calcula valores;
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ES_ListaR.h"
#include "ES_PilhaC.h"
#include "ES_PilhaR.h"

#define maxColuns 50
#define maxLines 10

//enumerando tokens e letras
typedef enum{PaE,PaD,OpA,OpM,Ident,TerM} TokenIn;
//interfaces
TokenIn obterToken(char);
int obterIdent(unsigned char);
int lerArquivo(unsigned char [][maxColuns]);
void converterInf_Pos(int,unsigned char[][maxColuns] , unsigned char [][maxColuns]);
void avaliarPos(int,unsigned char [][maxColuns], ListaR *, ListaR *);
void listarValores(ListaR *);
void imprimir(int,unsigned char[][maxColuns] , unsigned char [][maxColuns],ListaR *);


void main(){
	
	unsigned char inf[maxLines][maxColuns];
	int qtdeExp;
	unsigned char pos[maxLines][maxColuns];
	ListaR resultados,valores;
	//lendo arquivo texto e recuperando qtde expressoes
	qtdeExp = lerArquivo(inf);
	//conversão para posfixa
	converterInf_Pos(qtdeExp,inf,pos);
	//listas de reais com valores a serem substituidos e resultados
	criarLista(&resultados);
	criarLista(&valores);
	//preenchendo valores
	listarValores(&valores);
	//avaliando expressões
	avaliarPos(qtdeExp,pos,&valores,&resultados);
	//imprimindo dados
	imprimir(qtdeExp,inf,pos,&resultados);
	system("PAUSE");
}

//implementações
int lerArquivo(unsigned char matriz[maxLines][maxColuns]){
	//Função que lê expressões de um arquivo
	int lin=0, col,tamanhoLinha;
	unsigned char line[maxColuns];
	//arquivo
	FILE *entrada;
	entrada = fopen("INFIXA.txt","r"); //abrir arquivo - somente leitura
	if(entrada == NULL) { //arquivo não encontrado
		printf("\nArquivo não encontrado.\n");
	}
	else{ //ler arquivo
		//lendo arquivo
		while(fscanf(entrada,"%50s",line)==1){ //armazena em vetor
			for(col=0;col<=strlen(line);col++){ //transfere do vetor para matriz
				matriz[lin][col] = line[col];
			}
			lin++; //proxima linha	
		}
		fclose(entrada);
	}
	return lin;
}
TokenIn obterToken(char ch){ //obterToken do caractere passado
	
        TokenIn result;
        switch (ch){
              case '(': result = PaE;break;
              case ')': result = PaD;break;
              case ';': result = TerM;break;
              case '*': result = OpM;
              case '/': result = OpM;break;
              case '+': result = OpA;
              case '-': result = OpA;break;
              default: result = Ident;
              }
        return result;
}
int obterIdent (unsigned char ch){ //Obter posição associado ao identificador
	int res;
    switch (ch){
          case 'A': res = 1;break;
          case 'B': res = 2;break;
          case 'C' : res = 3;break;
          case 'D': res = 4;break;
          case 'E': res = 5;break;
          case 'F': res = 6;break;
          case 'G': res = 7;break;
          case 'H' : res = 8;break;
          case 'I': res = 9;break;
          case 'J': res = 10;break;
          case 'K' : res = 11;break;
          case 'L': res = 12;break;
          case 'M': res = 13;break;
          case 'N' : res = 14;break;
          case 'O': res = 15;break;
          case 'P': res = 16;break;
          case 'Q' : res = 17;break;
          case 'R': res = 18;break;
          case 'S': res = 19;break;
          case 'T' : res = 20;break;
          case 'U': res = 21;break;
          case 'V': res = 22;break;
          case 'W' : res = 23;break;
          case 'X' : res = 24;break;
          case 'Y' : res = 25;break;
          case 'Z' : res = 26;break;
          default: res = 0;
          }
        return res;
}
void converterInf_Pos(int qtde,unsigned char infixa [][maxColuns], unsigned char posfixa [][maxColuns]){
	//variáveis
	int cursor, linha,coluna, qtdeExp,colunaPos;
	bool pv,pilhaVazia,ok = FALSE;
	PilhaCh pilha;
	unsigned char chp,ch;
	TokenIn token;

	//criando pilha
	criarPilhaChVazia(&pilha);
	//conversão de infixa em pos fixa
	for (linha = 0; linha < qtde ; linha ++){
		coluna = 0;
		colunaPos = 0;
		pv = FALSE; 
		do{
			ch = infixa[linha][coluna];
			token = obterToken(ch);
			//aplicando algoritmo de conversão
			//para cada char 
			switch (token){
				case PaE : 
					pushPilhaCh(&pilha,ch);	
					break;
				case OpA :
					ok = FALSE;
					do{
						pilhaVazia = verificarPilhaChVazia(&pilha);
						if(pilhaVazia == TRUE){
							pushPilhaCh(&pilha,ch);
							ok = TRUE;
						}else{
							chp = acessarTopo(&pilha);
							token = obterToken(chp);
							if(token == PaE){
								pushPilhaCh(&pilha,ch);
								ok=TRUE;
							}else{
								//colocando na posFixa
								posfixa[linha][colunaPos] = chp;
								colunaPos++;
								popPilhaCh(&pilha);
							}
						}
					}while(ok!=TRUE);
					break;
				case OpM:
					ok = FALSE;
					do{
						pilhaVazia = verificarPilhaChVazia(&pilha);
						if(pilhaVazia == TRUE){
							pushPilhaCh(&pilha,ch);
							ok = TRUE;
						}else{
							chp = acessarTopo(&pilha);
							token = obterToken(chp);
							if((token == PaE)||(token == OpA)){
								pushPilhaCh(&pilha,ch);
								ok=TRUE;
							}else if ( token == OpM){
								//colocando na posFixa
								posfixa[linha][colunaPos] = chp;
								colunaPos++;
								popPilhaCh(&pilha);
							}
						}
					}while(ok!=TRUE);	
					break;
				case TerM:
					pilhaVazia = verificarPilhaChVazia(&pilha);
					while(pilhaVazia == FALSE){
						chp = acessarTopo(&pilha);
						popPilhaCh(&pilha);
						posfixa[linha][colunaPos] = chp;
						colunaPos++;	
						pilhaVazia = verificarPilhaChVazia(&pilha);						
					}
					//encerrando linha
					pv = TRUE;
					posfixa[linha][colunaPos] = ch;
					
					break;
				case PaD:
					pilhaVazia = verificarPilhaChVazia(&pilha);
					if(pilhaVazia == FALSE){
						ok=FALSE;
						do{
							chp = acessarTopo(&pilha);
							token = obterToken(chp);
							if (token == PaE){
								popPilhaCh(&pilha);
								ok = TRUE;
							}else{
								posfixa[linha][colunaPos] = chp;
								colunaPos++;
								popPilhaCh(&pilha);	
							}
						}while(ok!=TRUE);			
					}
					break;
				default:
					posfixa[linha][colunaPos] = ch;
					colunaPos++;
					break;		
			}
			coluna++;
		}while(pv == FALSE);
	}
}
void avaliarPos(int qtde,unsigned char posfixa[][maxColuns],ListaR *valores, ListaR *res){
	//variaveis
	double resultado,v1,v2,v,valor;
	int linha,coluna,pos;
	bool term;
	unsigned char ch;
	TokenIn chp;
	//criando pilha
	PilhaR pilha;
	criarPilhaRVazia(&pilha);
	
	for(linha=0;linha<qtde;linha++){
		term = FALSE;
		coluna = 0;
		do{//aplicando algoritmo			
			ch = posfixa[linha][coluna];
			chp = obterToken(ch);
			if(chp == Ident){
				//obtendo valor do identificador
				pos = obterIdent(ch);
				valor = obterElemento(valores,pos);
				//colocando valor na pilha
				pushPilhaR(&pilha,valor);
				coluna++;
			}else if(chp == TerM){
				//se achar indicador de termino da expressão
				term = TRUE;
			}else{
				//operador encontrado
				v1=acessarTopoPilhaR(&pilha);
				popPilhaR(&pilha);
				v2=acessarTopoPilhaR(&pilha);
				popPilhaR(&pilha);
				coluna++;
				//operando valores
				switch(chp){
					case OpA:			
						if(ch=='+'){
							v = v2 + v1;
						}else{
							v = v2 - v1;
						}
						break;
					default:
						if(ch=='*'){
							v = v2 * v1;	
						}else{
							v = v2/v1;
						}
						break;
				}		
				pushPilhaR(&pilha,v);
			}
		}while(term!=TRUE);
		//acessando resultado
		resultado = acessarTopoPilhaR(&pilha);
		//salvando resultado
		inserirNoFim(res,resultado);
	}
};
void listarValores(ListaR *l){//lista que atribui valores que serão utilizados pelos identificadores posteriormente na forma A=pos1, B=pos2 ,..., Z=pos26
	int cursor;
	double valor = 1.0;
	for(cursor=1;cursor<Maximo;cursor++){
		inserirNoFim(l,valor);
		valor++;		
	}
}
void imprimir(int qtde,unsigned char inf[][maxColuns] , unsigned char pos[][maxColuns],ListaR *res){
	int linha, colunaInf, colunaPos;
	bool ok = FALSE;
	unsigned char c;
	TokenIn token;
	//imprimindo
	for(linha=0;linha<qtde;linha++){
		colunaInf=0;
		colunaPos=0;
		printf("\nExpressao #%d",linha+1);
		//infixa
		printf("\nInfixa: ");
		ok = FALSE;
		do{
			c = inf[linha][colunaInf];
			token = obterToken(c);
			printf("%c",c);
			colunaInf++;
			if(token==TerM){
				ok = TRUE;
			}

		}while(ok!=TRUE);
		//posfixa
		printf("\nPosfixa: ");
		ok = FALSE;
		do{
			c = pos[linha][colunaPos];
			token = obterToken(c);
			if(token==TerM){
				//; é sinal de termino
				ok = TRUE;
			}else{
				printf("%c",c);
				colunaPos++;
			}		
		}while(ok!=TRUE);
		//resultado
		printf("\nResultado : %.4f",res->vetor[linha+1]);
		printf("\n");		
	}
}

