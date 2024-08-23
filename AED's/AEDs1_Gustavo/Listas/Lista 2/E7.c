#include <stdio.h>
#include <math.h>

int main(){

    int a = 0,b = 0,c = 0, cos;

    printf("Digite o primeiro valor: \n");
    scanf("%d", &a);
    printf("Digite o segundo valor: \n");
    scanf("%d", &b);
    printf("Digite o terceiro valor: \n");
    scanf("%d", &c);

    if(a > fabs(b-c)){
        if(a>b && a>c){
            cos = ((b*b)+(c*c)-(a*a))/2*b*c;
            if (cos > 0){
                printf("Triangulo Acutangulo.\n");
            } else if(cos<0){
                printf("Triangulo Obtusangulo.\n");
            } else {
                printf("Triangulo Reto.\n");
            }
        } else if(b>a && b>c){
            cos = ((a*a)+(c*c)-(b*b))/2*a*c;
            if (cos > 0){
                printf("Triangulo Acutangulo.\n");
            } else if(cos<0){
                printf("Triangulo Obtusangulo.\n");
            } else {
                printf("Triangulo Reto.\n");
            }
        } else if(c>a && c>b){
            cos = ((a*a)+(b*b)-(c*c))/2*a*b;
            if (cos > 0){
                printf("Triangulo Acutangulo.\n");
            } else if(cos<0){
                printf("Triangulo Obtusangulo.\n");
            } else {
                printf("Triangulo Reto.\n");
            }
        }
        if(a == b && a==c){
            printf("Triangulo Equilatero.");
        } else if(a == b || a ==c || c == b){
            printf("Triangulo Isosceles.");
        } else {
            printf("Triangulo Escaleno.");
        }
    }
}