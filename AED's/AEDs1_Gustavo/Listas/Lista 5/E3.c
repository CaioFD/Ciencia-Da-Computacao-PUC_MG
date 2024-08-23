#include <stdio.h> 

double somatorio(double n){
    double somatorio = 0;

    for (int i = 1; i <= n; i++)
    {
        somatorio+= (pow(-1, (i-1) ) ) * 4.0 / ((2.0*i)-1.0);
    }
    return somatorio;
}

int main() {


    double n;
    double resultado;

    printf("digite o numero da aprocimacao: ");
    scanf("%lf", &n);

    resultado = somatorio(n);
    printf("o resultado aproximado de PI e %.4lf\n", resultado);

    return 0;
}