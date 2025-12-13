import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int seq = 0, res = 0;
            int n  = Integer.parseInt(br.readLine());

            while (n > 0) {
                res = n % 2;
                n /= 2;

                if (res == 1) {
                    System.out.print(seq + " ");
                }
                seq++;
            }
            System.out.println();
        }
    }
}
