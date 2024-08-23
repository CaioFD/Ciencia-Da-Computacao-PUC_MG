#include <stdio.h>

int main() {
    int n, i, j;
    int matriz[10][10];

    printf("Digite a dimensao da matriz quadrada (n): ");
    scanf("%d", &n);

    
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1 );
            scanf("%d", &matriz[i][j]);
        }
    }

    
    printf("\nMatriz digitada:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    int determinante = 1;
    for (i = 0; i < n; ++i) {
        determinante *= matriz[i][i];
    }
    printf("\nDeterminante: %d\n", determinante);


    printf("\nDiagonal Principal:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (i == j) {
                printf("%d\t", matriz[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }

    return 0;
}
