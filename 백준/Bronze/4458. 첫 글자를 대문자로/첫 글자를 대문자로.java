import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            char ch = input.charAt(0);

            if ('a' <= ch && ch <= 'z') {
                ch = (char) (ch - 32);
            }

            System.out.print(ch);
            System.out.println(input.substring(1));
        }
    }
}
