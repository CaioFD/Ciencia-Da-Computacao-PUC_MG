#include <stdio.h>

void Par_ou_Impar (int n){

    if (n % 2 == 0)
    {
        printf("O numero %d eh PAR\n", n);
    }else{
        printf("O numero %d eh IMPAR\n", n);
    }

}

int main(){
int n;

printf("Digite um numero inteiro: \n");
scanf("%d", &n);

Par_ou_Impar(n);

}