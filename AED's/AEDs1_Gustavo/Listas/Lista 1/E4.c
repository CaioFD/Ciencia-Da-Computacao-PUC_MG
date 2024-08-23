#include <stdio.h>
#define MAXLENGHT 80

int main() {


    int tamanho, contador=0;
    char nome[MAXLENGHT];

    printf("digite seu nome completo: ");
    fgets(nome, sizeof(nome), stdin); 

    tamanho = myStrlen(nome); 


    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] == ' ')
        {
           
        }else if (isLetter(nome[i]))
        {
            contador++;
        }
    }
    
    printf("%d\n", contador);


    return 0;
}