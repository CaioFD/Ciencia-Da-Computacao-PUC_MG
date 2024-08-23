#include <stdio.h>
#include <math.h>

int main(){
    float c1,c2, hip, area, sen1,sen2;
    printf("Digite o valor dos dois catetos: \n");
    scanf("%f %f", &c1, &c2);

    hip = sqrt((pow(c1,2))+ (pow(c2,2)));
    area = (c1*c2)/2;

    if (hip != 1)
    {
        sen1 = c1/hip;
        sen2 = c2/hip;
        printf("Os senos dos angulos opostos sao: %.2f e %.2f\n",sen1,sen2);
    }
    printf("O valor da hipotenusa eh de %.2f\n", hip);
    printf("O valor da area eh de %.2f\n", area);

    return 0;
}