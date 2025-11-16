import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            int[] counts = new int[26];

            for (char c : input.toCharArray()) {
                if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) continue;
                c = Character.toLowerCase(c);
                counts[c - 'a']++;
            }

            int result = Arrays.stream(counts).min().getAsInt();
            String ans = "";

            if (result == 0) {
                ans = "Not a pangram";
            } else if (result == 1) {
                ans = "Pangram!";
            } else if (result == 2) {
                ans = "Double pangram!!";
            } else {
                ans = "Triple pangram!!!";
            }
            System.out.println("Case " + (i + 1) + ": " + ans);
        }
    }
}
