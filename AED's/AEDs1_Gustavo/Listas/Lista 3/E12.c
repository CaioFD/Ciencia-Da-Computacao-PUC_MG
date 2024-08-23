int main() {
    double valorI, entrada, jurosA, prestacao, jurosM, saldoDevedor;
    int numMeses;

    printf("Digite o valor do imovel em reais: ");
    scanf("%lf", &valorI);

    printf("Digite o valor da entrada em reais: ");
    scanf("%lf", &entrada);

    printf("Digite o numero de meses do emprestimo (entre 60 e 360 meses): ");
    scanf("%d", &numMeses);

   
    if (valorI <= 100000 || entrada < 0.20 * valorI || entrada > 0.75 * 
       valorI || numMeses < 60 || numMeses > 360) {
        printf("Os valores nao atendem aos criterios\n");
        return 1;
    }

   
    jurosA = 0.10;

    jurosM = jurosA / 12.0;

    saldoDevedor = valorI - entrada;

    prestacao = (saldoDevedor / numMeses) + (saldoDevedor * jurosM);

    double valorTotalPago = entrada + prestacao * numMeses;

    printf("O valor da primeira prestação e: R$ %.2lf\n", prestacao);
    printf("O valor total pago no final do financiamento e: R$ %.2lf\n", valorTotalPago);

    return 0;
}