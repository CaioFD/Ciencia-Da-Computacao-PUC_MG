#include <stdio.h>

bool cores(int vermelho, int verde, int azul){
    
    if (vermelho < 0 || vermelho > 255 || verde < 0 || verde > 255 || azul < 0 || azul > 255)
    {
        return true;
    }else{
        return false;
    }
    
}

int main() {

    int vermelho=0, azul=0, verde=0;

    printf("Digite o valor para o canal vermelho (0-255):");
    scanf("%d", &vermelho);
    printf("Digite o valor para o canal verde (0-255):");
    scanf("%d", &azul);
    printf("Digite o valor para o canal verde (0-255):");
    scanf("%d", &verde);
    
    

    if (cores(vermelho, verde, azul))
    {
        
        printf("valores nao estao dentro do espaco determinado\n");
        return 1; 
    }

    printf("O valor em hexadecimal para a cor vermelha é: %02X\n", vermelho);
    printf("O valor em hexadecimal para a cor verde é: %02X\n", verde);
    printf("O valor em hexadecimal para a cor azul é: %02X\n", azul);
    

    return 0;
}