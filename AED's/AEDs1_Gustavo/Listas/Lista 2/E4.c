#include <stdio.h>
#include <math.h>

int main(){
    float peso, altura, imc;

    printf("Digite sua altura: \n");
    scanf("%f", &altura);
    printf(" Digite sua peso: \n");
    scanf("%f", &peso);

    imc = peso / altura;

    if (imc<16)
    {
       printf("SITUACAO: Hecticidade morbida");

    }else if ((imc >= 16) || (imc <= 17))
    {
        printf("SITUACAO: Hecticidade grave");

    }else if ((imc >= 17) || (imc <= 18.5))
    {
        printf("SITUACAO: Abaixo do peso");

    }else if ((imc >= 18.5) || (imc <= 25))
    {
        printf("SITUACAO: Peso normal");

    }else if ((imc >= 25) || (imc <= 30))
    {
        printf("SITUACAO: Sobrepeso");

    }else if ((imc >= 30) || (imc <= 35))
    {
        printf("SITUACAO: Obesidade");

    }else if ((imc >= 35) || (imc <= 40))
    {
        printf("SITUACAO: Obesidade grave");

    }else{
        printf("SITUACAO: Obesidade mórbida");
    }
    
    return 0;
}