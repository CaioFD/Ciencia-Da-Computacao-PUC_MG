import java.util.Scanner;

public class Q15 {
  public static String verificarString(Scanner scanner) {
    String str = scanner.nextLine();

    if (str.equals("FIM")) {
      return ""; // Condição de parada recursiva
    }

    str = str.toLowerCase(); // Converte a string para minúsculas

    boolean vogais = str.matches("[aeiou]+");
    boolean consoantes = str.matches("[bcdfghjklmnpqrstvwxyz]+");
    boolean inteiro = str.matches("-?\\d+");
    boolean real = str.matches("-?\\d+(\\.\\d+)?");

    String resultado = (vogais ? "SIM" : "NAO") + " " +
        (consoantes ? "SIM" : "NAO") + " " +
        (inteiro ? "SIM" : "NAO") + " " +
        (real ? "SIM" : "NAO");

    return resultado + "\n" + verificarString(scanner);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println(verificarString(scanner));

    scanner.close();
  }
}