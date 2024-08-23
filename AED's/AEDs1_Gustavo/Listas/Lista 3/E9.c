#include <stdio.h>
int main(){
    int n, primo = 1;
    printf("Digite um numero natural:\n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf(" Nao pode ser escrito um numero negatio ou ZERO");
    }else{

        for (int i = 0; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                primo = 0;
                break;
            }
            
        }
        if (primo == 1) {
            printf("O numero %d eh primo.\n", n);
        } else {
            printf("O numero %d não eh primo.\n", n);
        }
    }
        
    
    

    return 0;
}