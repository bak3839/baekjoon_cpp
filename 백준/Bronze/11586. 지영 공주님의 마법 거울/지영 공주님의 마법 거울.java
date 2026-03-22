import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] words = new String[N];

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
        }

        int mode = Integer.parseInt(br.readLine());
        if (mode == 1) {
            for (int i = 0; i < N; i++) {
                System.out.println(words[i]);
            }
        }
        else if (mode == 2) {
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j >= 0; j--) {
                    System.out.print(words[i].charAt(j));
                }
                System.out.println();
            }
        }
        else if (mode == 3) {
            for (int i = N - 1; i >= 0; i--) {
                System.out.println(words[i]);
            }
        }

    }
}
