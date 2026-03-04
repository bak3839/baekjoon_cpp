import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        if ("M".equals(input)) {
            System.out.println("MatKor");
        } else if ("W".equals(input)) {
            System.out.println("WiCys");
        } else if ("C".equals(input)) {
            System.out.println("CyKor");
        } else if("A".equals(input)) {
            System.out.println("AlKor");
        } else if ("$".equals(input)) {
            System.out.println("$clear");
        }
    }
}
