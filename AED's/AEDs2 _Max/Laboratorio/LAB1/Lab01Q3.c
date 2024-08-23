#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int CountMaiuscula(const char *string)
{
    int count = 0;

    int tamanho = strlen(string);

    for (int i = 0; i < tamanho + 1; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            // printf("%c\n", string[i]);
            count++;
        }
    }
    // printf("Numero de Maiusculas:%i \n", count);
    return count;
}

int main()
{
    char palavra[100];

    FILE *arqout = fopen("pub.out.txt", "wt");
   
    while (fgets(palavra, sizeof(palavra), stdin) != NULL)
    {
        if (strcmp(palavra, "FIM\n") == 0)
        {
            // printf("Função encerrada\n");
            break;
        }
        int i = CountMaiuscula(palavra);
        printf("%i\n", i);
        fprintf(arqout, "%i\n", i);
    }

    fclose(arqout);

    return 0;
}