#include <stdio.h>

int main(){
       int n, i, j;
        
        printf("Digite um valor natural (n): \n");
        scanf("%d", &n);

        if (n <= 0) {
        printf("O valor nao pode ser um numero negativo \n");
        return 1;  
    }

     printf("Os primeiros %d numeros primos sao: \n", n);

    for (i = 2; n > 0; i++) {
        int primo = 1;  

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                primo = 0;  
                break;
            }
        }
            if (primo) {
             printf("%d ", i);
             n--;
                      }
    }


    return 0;
}