#include <stdio.h>

int main(){
    int tamanho = 10, vetor[tamanho], Nvalor, count = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i+1);
        scanf("%d", &vetor[i]);
    }


    printf("Digite um novo numero: \n");
    scanf("%d", &Nvalor);

    printf("Posicoes em que este valor aparece:\n");
    for (int  i = 0; i < tamanho; i++)
    {
        if (vetor[i] == Nvalor)
        {
            count++;
            printf("%d ", i + 1);
        }
        
    }
    
            printf("\nO novo valor %d aparece %d vezes no vetor.\n", Nvalor, count);
}