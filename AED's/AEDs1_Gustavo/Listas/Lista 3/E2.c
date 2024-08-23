#include <stdio.h>
#include <math.h>

int main(){

int n =0; 
float soma = 0;
printf("Digite o numero de termos n: ");
scanf("%d", &n);

for (int  i = 0 ; i <= n; i++)
{
    soma += 1/(pow(2,i));
}

printf("%f", soma);
    return 0;
}