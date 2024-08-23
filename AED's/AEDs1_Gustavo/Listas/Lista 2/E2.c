#include <stdio.h>
int main(){
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade < 16)
    {
        printf("Voce nao eh eleitor");

    }else if ((idade == 16) || (idade == 17))
    {
        printf("Voce eh um eleitor(a) facultativo menor de idade");

    }else if ((idade >= 18) && (idade <= 64))
    {
        printf("Voce eh um eleitor obrigatorio");

    }else  
    {
        printf("Voce eh um um eleitor facultativo maior de idade");
    }
    
    return 0;
}