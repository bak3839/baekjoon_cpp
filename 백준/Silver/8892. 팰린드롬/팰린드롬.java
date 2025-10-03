import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static boolean checkPalindrome(String word) {
        for (int i = 0; i < word.length() / 2; i++) {
            if (word.charAt(i) != word.charAt(word.length() - 1 - i)) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            String[] words = new String[N];

            for (int i = 0; i < N; i++) {
                words[i] = br.readLine();
            }

            String answer = "0";
            boolean isPalindrome = false;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    String word1 = words[i] + words[j];
                    String word2 = words[j] + words[i];
                    boolean check1 = checkPalindrome(word1);
                    boolean check2 = checkPalindrome(word2);

                    if (check1 || check2) {
                        isPalindrome = true;
                        answer = check1 ? word1 : word2;
                        break;
                    }
                }
                if (isPalindrome) break;
            }
            System.out.println(answer);
        }
    }
}
