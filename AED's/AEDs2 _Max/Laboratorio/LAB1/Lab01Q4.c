#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CountMaiuscula(const char *string, int index)
{
    
    if (string[index] == '\0')
        return 0;
    int isMaiuscula = (string[index] >= 'A' && string[index] <= 'Z');
    return isMaiuscula + CountMaiuscula(string, index + 1);
}

int main()
{
    char palavra[100];

    FILE *arqout = fopen("pub.out.txt", "wt");
   
    while (fgets(palavra, sizeof(palavra), stdin) != NULL)
    {
        if (strcmp(palavra, "FIM\n") == 0)
        {
            break;
        }
        int i = CountMaiuscula(palavra, 0);
        printf("%i\n", i);
        fprintf(arqout, "%i\n", i);
    }

    fclose(arqout);

    return 0;
}
