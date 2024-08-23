#include <stdio.h>
#include <math.h>
#define M_PI		3.14159265358979323846

int main() {


    double cateto1=0.0, cateto2=0.0, hipotenusa=0.0, area=0.0, perimetro=0.0, angulo1=0.0, angulo2=0.0;

    printf("\nDigite o valor do primeiro cateto: ");
    scanf("%lf", &cateto2);
    printf("\nDigite o valor do segundo cateto: ");
    scanf("%lf", &cateto2);

    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));


    area = (cateto1 * cateto2) / 2;


    perimetro = cateto1 + cateto2 + hipotenusa;

    angulo1 = atan(cateto2 / cateto1) * (180 / M_PI);
    angulo2 = 90 - angulo1;

    
    printf("\nHipotenusa: %.2f\n", hipotenusa);
    printf("area: %.2lf\n", area);
    printf("Perimetro: %.2lf\n", perimetro);
    printf("angulo adjacente ao primeiro cateto: %.2lf graus\n", angulo1);
    printf("angulo adjacente ao segundo cateto: %.2lf graus\n", angulo2);
    

    return 0;
}
