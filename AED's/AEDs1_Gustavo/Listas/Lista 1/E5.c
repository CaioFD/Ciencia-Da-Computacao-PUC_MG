#include <stdio.h>

int main() {

    char cor[2]; 
    int vermelho, verde, azul; 

    
    for (int i = 0; i < 6; i += 2) {
        printf("Digite a cor #%d (formato hexadecimal): ", i / 2 + 1);
        scanf("%2s", cor);

        
        sscanf(cor, "%x", &vermelho);

        
        printf("Valor inteiro da cor #%d: %d\n", i / 2 + 1, vermelho);
    }

    return 0;
}   