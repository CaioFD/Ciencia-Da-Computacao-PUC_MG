#include <stdio.h>
#include <math.h>

void VetorBI(float x, float y){

    printf("As duas coordenadas desse vetor sao: %.2f e %.2f \n", x,y);
    
    float norma = 0;
    norma = sqrt( (pow(x,2)) + (pow(y,2)) );
    printf("A norma deste valor eh de: %.2f", norma);
}

int main(){
float x,y;
    printf("Digite o valor das duas coordenadas do vetor: \n");
    scanf("%f %f",&x,&y);

    VetorBI(x,y);

    return 0;
}