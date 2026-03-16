import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String num = "9780921418";
        int total = 0;

        for (int i = 0; i < num.length(); i++) {
            char ch = num.charAt(i);
            total += (i % 2 == 0 ? 1 : 3) * (ch - '0');
        }

        for (int i = 10; i < 13; i++) {
            int n = Integer.parseInt(br.readLine());
            total += (i % 2 == 0 ? 1 : 3) * n;
        }

        System.out.println("The 1-3-sum is " + total);
    }
}
