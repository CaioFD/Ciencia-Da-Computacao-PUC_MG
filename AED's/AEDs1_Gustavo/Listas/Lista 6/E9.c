#include <stdio.h>
#include "E9.h"

int main() {

    Tempo tempo;

    printf("digite quantas horas\n");
    scanf("%d", &tempo.hora.hora);
    getchar();
    printf("digite quantos minutos\n");
    scanf("%d", &tempo.hora.minuto);
    getchar();
    printf("digite quantos segundos\n");
    scanf("%d", &tempo.hora.segundo);
    getchar();

    printf("digite que dia e hoje\n");
    scanf("%d", &tempo.data.dia);
    getchar();
    printf("digite que mes estamos\n");
    scanf("%d", &tempo.data.mes);
    getchar();
    printf("digite em que ano nos estamos\n");
    scanf("%d", &tempo.data.ano);
    getchar();
    
    printf("horario:\n");
    printf("%d:%d:%d\n", tempo.hora.hora, tempo.hora.minuto, tempo.hora.segundo);
    printf("data:\n");
    printf("%d/%d/%d\n", tempo.data.dia, tempo.data.mes, tempo.data.ano);

    return 0;
}