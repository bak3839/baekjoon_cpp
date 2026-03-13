import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int result = 0;
            boolean[] visited = new boolean[26];
            String input = br.readLine();

            for (char ch : input.toCharArray()) {
                visited[ch - 'A'] = true;
            }

            for (int i = 0; i < 26; i++) {
                if (visited[i]) continue;

                result += (65 + i);
            }
            System.out.println(result);
        }
    }
}
