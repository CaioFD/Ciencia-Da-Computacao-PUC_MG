#include <stdio.h> 

int isPar(int numero){
    if (numero % 2 == 0)
    {
        return 1;
    }
    return 0; 
}

int main() {

    int numero;
    printf("digite o numero: ");
    scanf("%d", &numero);

    if (isPar(numero))
    {
        printf("o numero e par\n");
    }else{
        printf("o numero e impar\n");
    }

    return 0;
}