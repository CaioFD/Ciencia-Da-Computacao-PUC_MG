#include <stdio.h>

void Pescalar(float vet[], int tam, float escalar){

    for (int i = 0; i < tam; i++) {
        vet[i] *= escalar;
    }

     printf("Resultado do produto do vetor pelo escalar:\n");
    for (int i = 0; i < tam; i++) {
        printf("%.2f ", vet[i]);
    }
}

int main(){
    int tam;
    float escalar;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);

    if (tam <= 0 )
    {
        printf("Tamanho do vetor deve ser um numero natural (nao negativo).\n");
        return 1;
    }

    float vet[tam];
        printf("Digite os elemento dos vetor: \n");
        for (int i = 0; i < tam; i++)
        {
            printf("Elemento %d: ", i + 1);
            scanf("%f", &vet[i]);
        }

        printf("Digite o tamanho do escalar: \n");
        scanf("%f", &escalar);

        Pescalar(vet,tam,escalar);


return 0;
}
        