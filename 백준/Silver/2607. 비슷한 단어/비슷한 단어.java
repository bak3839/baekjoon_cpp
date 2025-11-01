import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] words = new String[N];
        int ans = 0;
        int[] counts = new int[26];
        int[] temp = new int[26];

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
        }

        for (int i = 0; i < words[0].length(); i++) {
            counts[words[0].charAt(i) - 'A']++;
        }

        for (int i = 1; i < N; i++) {
            String word = words[i];
            int lenDiff = Math.abs(word.length() - words[0].length());
            for (int j = 0; j < word.length(); j++) {
                temp[word.charAt(j) - 'A']++;
            }

            int diff = 0;
            boolean flag = true;
            for (int j = 0; j < 26; j++) {
                diff += Math.abs(counts[j] - temp[j]);
            }

            if (diff == 0) ans++;
            else if (diff == 2 && lenDiff == 0) ans++;
            else if (diff == 1 && lenDiff == 1) ans++;
            Arrays.fill(temp, 0);
        }
        System.out.println(ans);
    }
}
