#include <stdio.h>
#include <math.h>

int main(){
    float soma = 0.0;
    int x,n;
    int fat = 0;

    printf("Digite o numero de termos N: ");
    scanf("%d", &n);
    printf("Digite o valor X a ser calculado: ");
    scanf("%d", &x);

    for (int i = 0; i <= n-1; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            fat = fat * j;
        }
        soma = ((-1) * (pow(x,i))) / fat;
    }
    
        printf("O valor da serie exponecial eh de : %.2f\n", soma);

        return 0;
}