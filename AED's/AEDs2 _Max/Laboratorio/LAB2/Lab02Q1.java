import java.util.Scanner;

public class Lab02Q1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            String a = sc.nextLine();
            String b = sc.nextLine();

            System.out.println(Lab02Q1.combine(a,b));
        }
        sc.close();
    }

    public static char[] combine(String a, String b){
        char[] res = new char[a.length() + b.length()];
        int i = 0;

        while (i<a.length() || i <b.length()) {
            if (i<a.length()) {
                System.out.print(a.charAt(i));
            }
            if (i<b.length()) {
                System.out.print(b.charAt(i));
            }
            i++;
        }
        return res;
    }
}