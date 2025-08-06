import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long ans = 0;
        int N = Integer.parseInt(br.readLine());
        long[] sum1 = new long[N + 1];
        long[] sum2 = new long[N + 1];

        for (int i = 1; i <= N; i++) {
            long n = Long.parseLong(br.readLine());
            sum1[i] = sum1[i - 1] + n;
            sum2[i] = sum2[i - 1] + n * n;
        }

        for (int i = 1; i < N; i++) {
            long L = sum2[i];
            long R = sum1[N] - sum1[i];
            ans = Math.max(L * R, ans);
        }

        System.out.println(ans);
    }
}
