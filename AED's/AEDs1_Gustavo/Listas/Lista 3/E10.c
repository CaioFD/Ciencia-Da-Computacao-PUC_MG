#include <stdio.h>

int main() {
    int n1, n2, menor, i, primos = 1;

    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &n2);

    
    menor = (n1 < n2) ? n1 : n2;

   
    for (i = 2; i <= menor; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            primos = 0; 
            break;
        }
    }

    if (primos) {
        printf("%d e %d sao numeros primos entre si.\n", n1, n2);
    } else {
        printf("%d e %d nao sao numeros primos entre si.\n", n1, n2);
    }

    return 0;
}
