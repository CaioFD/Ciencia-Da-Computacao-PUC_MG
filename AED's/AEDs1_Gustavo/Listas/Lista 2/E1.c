#include <stdio.h>

int main(){

int num;

printf(" Digite um numero inteiro: ");
scanf("%d", &num);

if (num % 2 == 0)
{
    printf("O numero eh par\n");
}else{
    printf(" O numero eh impar\n");
}

return 0;
}