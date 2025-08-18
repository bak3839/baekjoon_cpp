import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String word = br.readLine();
        StringBuilder answer = new StringBuilder();

        for (char ch : word.toCharArray()) {
            int n = ch - 'A' - 3;

            if (n < 0) {
                answer.append((char) ('A' + 26 + n));
            } else {
                answer.append((char) ('A' + n));
            }
        }

        System.out.println(answer.toString());
    }
}
