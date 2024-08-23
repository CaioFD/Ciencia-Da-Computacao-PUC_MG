#include <stdio.h>
int main(){
    int dia = 0;

    printf("Digite um numero para saber o dia da semana: \n");
    scanf("%d",&dia);
    
    if((dia >= 1) || (dia <= 7))
    {
        switch (dia){

            case 1:
            printf("O dia eh Domingo\n");
            break;

            case 2: 
            printf("O dia eh Segunda\n");
            break;

            case 3: 
            printf("O dia eh Terca\n");
            break;

            case 4: 
            printf("O dia eh Quarta\n");
            break;

            case 5: 
            printf("O dia eh Quinta\n");
            break;

            case 6: 
            printf("O dia eh Sexta\n");
            break;

            case 7: 
            printf("O dia eh Sabado\n");
            break;
        }
    }else{
        printf("O numero nao eh um dia das semana\n");
    }
    return 0;
}