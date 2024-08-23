#include <stdio.h>
#include <stdlib.h>

float* AlocarVet(int tam){

    float* vet = (float*)malloc(tam * sizeof(float));
        if(vet == NULL) {
            printf("ERRO");
        }   

        for (int i = 0; i < tam; i++)
        {
            vet[i] = 0.0;
        }
        return vet;
                
}

int main(){
    int tam;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);

    float* vet = AlocarVet(tam);
    free(vet);  

    return 0;
}