import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long N = Long.parseLong(br.readLine());
        long base = N / 5, ans = -1;

        for (long i = base; i >= 0; i--) {
            long mod = N - (5 * i);
            if (mod % 3 == 0) {
                ans = i + (mod / 3);
                break;
            }
        }

        System.out.println(ans);
    }
}
