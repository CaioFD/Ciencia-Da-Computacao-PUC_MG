#include <stdio.h>
#include "E1-4.h"



int main()
{
    Data data;
    int n;
    printf("digite um numero de dias, para acrescentar\n");
    scanf("%d", &n);
    getchar();

    data = MaisDias(data, n);

    return 0;
}