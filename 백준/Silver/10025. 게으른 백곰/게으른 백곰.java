import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long ans = 0;
        int maxIdx = 0;
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long[] sum = new long[1_000_001];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            sum[x] = g;
            maxIdx = Math.max(maxIdx, x);
        }

        for (int i = 1; i <= 1_000_000; i++) {
            sum[i] += sum[i - 1];
        }

        for (int i = 0; i <= 1_000_000; i++) {
            int left = Math.max(0, i - K);
            int right = Math.min(1_000_000, i + K);
            long res = sum[right] - (left > 0 ? sum[left - 1] : 0);
            ans = Math.max(ans, res);
        }

        System.out.println(ans);
    }
}
