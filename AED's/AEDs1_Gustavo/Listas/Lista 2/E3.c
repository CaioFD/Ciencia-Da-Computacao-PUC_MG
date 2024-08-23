#include <stdio.h>
int main(){
    int num;

    printf(" Digite um numero:");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        if ((num % 2 == 0) && (num % 5 == 0) )
        {
           printf("Este numero eh divisivel por 2, 5 e 10\n");
           return 0;
        }
        
        printf("Este numero eh divisivel por 2");

    }else if (num % 5 == 0)
    {
        printf("Este numero eh divisivel por 5");

    }else if (num % 10 == 0)
    {
        printf("Este numero eh divisivel por 10");

    }else{
        printf("Este numero nao eh divisivel por 2 , 5 e 10");
    }

    
    return 0;
}