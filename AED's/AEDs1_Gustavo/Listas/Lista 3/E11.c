#include <stdio.h>
#include <math.h>

int main(){

    float conta=0.0;
    int n=0, x=0;

    printf("Digite o valor da aproximacao N:\n");
    scanf("%d", &n);
     printf("Digite o valor da conta X:\n");
    scanf("%d", &x);
    
    
    for (int i = 1; i <= n; i++)
    {
        conta += (pow((-1), i) * pow((-1+x),i))/i;
    }
    conta = conta *(-1);

    printf("%f", conta);
    
    return 0;
}