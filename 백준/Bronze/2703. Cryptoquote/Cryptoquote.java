import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        char[] alphabet = new char[26];

        for (int t = 0; t < T; t++) {
            String input = br.readLine();
            String rule = br.readLine();

            for (int i = 0; i < rule.length(); i++) {
                alphabet[i] = rule.charAt(i);
            }

            for (int i = 0; i < input.length(); i++) {
                if('A' <= input.charAt(i) && input.charAt(i) <= 'Z') {
                    System.out.print(alphabet[input.charAt(i) - 'A']);
                } else {
                    System.out.print(input.charAt(i));
                }
            }
            System.out.println();
        }
    }
}
