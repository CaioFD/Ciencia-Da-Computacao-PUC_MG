#include <stdio.h>
 
 int main(){
    int n1,n2, mdc, temp;

    printf("Digite o primeiro numero inteiro : \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero  inteiro : \n");
    scanf("%d", &n2);

     while (n2 != 0) {
            temp = n2;
            n2 = n1 % n2;
            n1 = temp;
        }
        mdc = n1;

        printf("O MDC entre %d e %d eh:  %d\n", n1, n2, mdc);

    return 0;
 }