/* 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    char *inputs[] = {"radar", "sei", "Ana", "Roma", "Roma e amor"};
    int num_inputs = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < num_inputs; i++) {
        if (isPalindrome(inputs[i])) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromo(char palavra[], int inicio, int fim){
        if(fim+1 <= 1){
            return true;
        }
        if(palavra[inicio] != palavra[fim]){
            return false;
        }

        return isPalindromo(palavra, inicio+1, fim-1);

}
int main() {
    char palavra[1000];
    while (1) {
        scanf(" %[^\n]", palavra);

        if (strcmp(palavra, "FIM") == 0) {
            break;
        }
        int tam = strlen(palavra);
        bool resp = isPalindromo(palavra, 0, tam-1);

        if (resp == false) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }
    }

    return 0;
}