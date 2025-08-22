import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashSet<String> set = new HashSet<>();
        String[] words = new String[N];

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            words[i] = input;
            set.add(input);
        }

        for (String word : words) {
            String reversed = new StringBuffer(word).reverse().toString();

            if (set.contains(reversed)) {
                System.out.println(reversed.length() + " " + reversed.charAt(reversed.length() / 2));
                break;
            }
        }
    }
}
