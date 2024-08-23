

#include <stdio.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


int main() {
    int n;
    
    printf("Digite o numero de termos da sequencia de Fibonacci: ");
    scanf("%d", &n);
    
   for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}






/* int fibonacci_rec(int n, int fib1, int fib2, int i){
    if (i >= n) {
        return fib1;
    }

    int soma = fib1 + fib2;
    fib1 = fib2;
    fib2 = soma;

    return fibonacci_rec(n, fib1, fib2, ++i);
}

int fibonacci(int n){
    int i=0;
    return n==0 ? 0 : fibonacci_rec(n, 0, 1, i);

}

int main() {

    int  n=0;
    printf("digite a quantidade de numeros que vc quer na sequencia\n");
    scanf("%d", &n);

    int fib = fibonacci(n);

    printf("o valor de fibonacci e: %d\n", fib);

    return 0;
}
*/