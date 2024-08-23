import java.util.Scanner;

public class Lab02Q2 {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite o primeiro numero: ");
        int num1 = scanner.nextInt();
        System.out.print("Digite o segundo numero: ");
        int num2 = scanner.nextInt();
        System.out.println("A sequencia de espelho entre " + num1 + " e " + num2 + " e:");
        imprimirEspelho(num1, num2);
        
        scanner.close();
    }
    
    public static void imprimirEspelho(int inicio, int fim) {
        if (inicio <= fim) {
            for (int i = inicio; i <= fim; i++) {
                System.out.print(i + " ");
            }
            for (int i = fim  ; i >= inicio; i--) {
                System.out.print(i + " ");
            }
        } else {
            for (int i = inicio; i >= fim; i--) {
                System.out.print(i + " ");
            }
            for (int i = fim + 1; i <= inicio; i++) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
