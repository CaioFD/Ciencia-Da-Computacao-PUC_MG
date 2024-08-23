#include <stdio.h>

int main() {
    int tamanho = 10, vetor[tamanho];
    
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    
    
    printf("O maior numero armazenado no vetor eh: %d\n", maior);

    return 0;
}
