#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    int inicio, fim;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    inicio = 0;
    fim = strlen(frase) - 1;

    while (fim > inicio) {
    
        while (!isalpha(frase[inicio]) && inicio < fim) {
            inicio++;
        }
        while (!isalpha(frase[fim]) && fim > inicio) {
            fim--;
        }

        if (tolower(frase[inicio]) != tolower(frase[fim])) {
            printf("A frase nao eh um palindromo.\n");
            return 0;
        }

        inicio++;
        fim--;
    }

    printf("A frase eh um palindromo.\n");

    return 0;
}
