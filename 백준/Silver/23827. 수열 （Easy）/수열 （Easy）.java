import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long ans = 0;
        int N = Integer.parseInt(br.readLine());
        long[] A = new long[N + 1];
        long[] sum = new long[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Long.parseLong(st.nextToken());
            sum[i] = A[i] + sum[i - 1];
        }

        for (int i = 1; i <= N; i++) {
            long res = (sum[N] - sum[i]) * A[i] % 1_000_000_007;
            ans = (ans + res) % 1_000_000_007;
        }

        System.out.println(ans);
    }
}
