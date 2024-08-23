#include <stdio.h>
int main(){
    int fatorial = 1, N;

    printf("Digite um numero para fazer o fatorial: \n");
    scanf("%d", &N);


if (N<0)
{
     printf("Nao existe fatorial de um numero menor do que zero\n");

}else{
    for (int i = 1; i < N; i++)
        {
           fatorial = fatorial * (i+1);
        }
        printf("O fatorial de %d eh:  %d\n", N, fatorial);
}

    return 0;
}