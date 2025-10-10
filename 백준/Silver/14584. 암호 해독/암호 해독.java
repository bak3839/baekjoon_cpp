import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String cipher = br.readLine();
        int N = Integer.parseInt(br.readLine());
        String[] words = new String[N];
        char[] alphabet = new char[26];

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
        }

        for (int i = 0; i < 26; i++) {
            alphabet[i] = (char) ('a' + i);
        }

        String answer = "";
        for (int i = 0; i < 26; i++) {
            StringBuilder plain = new StringBuilder();

            for (char ch : cipher.toCharArray()) {
                int base = (ch - 'a' + i) % 26;
                plain.append(alphabet[base]);
            }

            for (String word : words) {
                if (!plain.toString().contains(word)) continue;
                answer = plain.toString();
                break;
            }
            if (!answer.isEmpty()) break;
        }
        System.out.println(answer);
    }
}
