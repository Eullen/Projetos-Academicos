/*
  Name: primos.c
  Copyright: 
  Author: LISBETE MADSEN BARBOSA
  Date: 28/02/09 15:03
  Description: Determina os números primos menores que 1500.
*/

main(){
       int n,j,c,d;
       n = 2; printf(" %8d",n);
       n = 3; printf(" %8d",n);
       n = 5;
       c = 0;
       while (n < 1500){
                d = 3; 
                while ((d < sqrt(n)) && (c==0)){
                       j = n % d;;
                       if (j != 0) d = d + 2; else c = 1;
                       }
                if (c == 0) printf("  %8d",n); else c = 0;
                n = n + 2;
                }
       printf("\n\n");
       system("PAUSE");
       }
       
