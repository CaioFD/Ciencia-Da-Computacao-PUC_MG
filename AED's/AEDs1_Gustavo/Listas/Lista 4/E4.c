#include <stdio.h>
#include <math.h>

int main() {
    int numeros[1000];  
    int tamanho = 0;
    int numero;
    double media = 0, mediana, moda, desvio_padrao = 0;

    
    do {
        printf("Digite um numero natural (0 para encerrar): ");
        scanf("%d", &numero);

        if (numero != 0) {
            numeros[tamanho] = numero;
            tamanho++;
            media = (media * (tamanho - 1) + numero) / tamanho;
        }
    } while (numero != 0);

    if (tamanho > 0) {
        
        for (int i = 0; i < tamanho - 1; i++) {
            for (int j = 0; j < tamanho - i - 1; j++) {
                if (numeros[j] > numeros[j + 1]) {
                    
                    int temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
        }

        
        if (tamanho % 2 == 0) {
            mediana = (numeros[tamanho / 2 - 1] + numeros[tamanho / 2]) / 2.0;
        } else {
            mediana = numeros[tamanho / 2];
        }

        
        int moda = numeros[0];
        int contagem_atual = 1;
        int contagem_max = 1;

        for (int i = 1; i < tamanho; i++) {
            if (numeros[i] == numeros[i - 1]) {
                contagem_atual++;
            } else {
                contagem_atual = 1;
            }

            if (contagem_atual > contagem_max) {
                contagem_max = contagem_atual;
                moda = numeros[i];
            }
        }

        for (int i = 0; i < tamanho; i++) {
            desvio_padrao += pow(numeros[i] - media, 2);
        }
        desvio_padrao = sqrt(desvio_padrao / tamanho);

        // Imprime os resultados
        printf("\nMedia: %.2f\n", media);
        printf("Mediana: %.2f\n", mediana);
        printf("Moda: %d\n", moda);
        printf("Desvio Padrao: %.2f\n", desvio_padrao);
    } else {
        printf("\nNenhum numero fornecido.\n");
    }

    return 0;
}
