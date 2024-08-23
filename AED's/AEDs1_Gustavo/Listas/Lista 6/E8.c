#include <stdio.h>
#include "E5-8.h"


int main()
{

    Horario horario = {2, 30, 45};

    int totalSegundos = calcularSegundos(horario);

    printf("Total de segundos: %d\n", totalSegundos);

    return 0;
}