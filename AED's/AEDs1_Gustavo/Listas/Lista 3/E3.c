#include <stdio.h>

int main(){

    int n, soma = 0, Ndigitados = 0;
    float media;

     printf("Aperte ZERO(0) apos colocar a quantidade de numeros a serem contados!\n");
     
    while (1)
    {
        printf("Digite os numeros a serem contados: \n");
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        soma = (float)soma + n;
        Ndigitados++;
    }
    
        if (Ndigitados == 0 )
        {
            printf("Encerrando o programa...\n");
        }else{
            media = soma/Ndigitados;
             printf("A media dos numeros digitados eh de: %.2f\n", media);
        }
        
}