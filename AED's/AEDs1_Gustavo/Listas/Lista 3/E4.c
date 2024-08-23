#include <stdio.h>

int main(){

int i, nTERMOS;
int a = 0, b = 1, c;

printf("Digite o numero de termos para a sequencia de FIBONACCI:\n");
scanf("%d", &nTERMOS);

  if (nTERMOS >= 1) {
        printf("%d", a);
    }

for (i = 1; i < nTERMOS; i++) {
        printf(", %d", a + b);
        c = a + b;
        a = b;
        b = c;
    }
return 0;
}