#include <stdio.h>

int main() {

  

    double areaBase=0.0, altura=0.0;

    areaBase = readdouble("qual e a area da base que vc quer: ");

    double lado = areaBase/4;

    altura = readdouble("qual e a altura da piramede: ");


    double volume=0, tercoLado=0; 

    tercoLado= lado/3; 
    volume = tercoLado * lado * altura; 

    double areaTot=0.0, areaTriangulo=0.0;

    areaTriangulo = (areaBase * altura)/2;

    areaTot = (4 * areaTriangulo) + areaBase;


    return 0;
}