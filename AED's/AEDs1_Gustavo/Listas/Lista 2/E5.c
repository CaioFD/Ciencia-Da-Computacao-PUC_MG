#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0, aux = 0;

    printf("Digite o primeiro valor: \n");
    scanf("%d", &a);
    printf("Digite o segundo valor: \n");
    scanf("%d", &b);
    printf("Digite o terceiro valor: \n");
    scanf("%d", &c);

    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }
    if (a > c) {
        aux = a;
        a = c;
        c = aux;
    }
    if (b > c) {
        aux = b;
        b = c;
        c = aux;
    }
    
    printf("%d, %d, %d\n", a, b, c);

}