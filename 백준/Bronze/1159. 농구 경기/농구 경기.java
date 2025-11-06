import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] counts = new int[26];

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            int index = name.charAt(0) - 'a';
            counts[index]++;
        }

        boolean pass = false;
        for (int i = 0; i < 26; i++) {
            if (counts[i] >= 5) {
                pass = true;
                char c = (char) (i + 'a');
                System.out.print(c);
            }
        }

        if (!pass) System.out.println("PREDAJA");
    }
}
