import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        String num1 = input.substring(0, input.length() / 2);
        String num2 = input.substring(input.length() / 2);

        int L = 0, R = 0;
        for (char ch : num1.toCharArray()) {
            L += ch - '0';
        }
        for (char ch : num2.toCharArray()) {
            R += ch - '0';
        }

        if (L == R) System.out.println("LUCKY");
        else System.out.println("READY");
    }
}
