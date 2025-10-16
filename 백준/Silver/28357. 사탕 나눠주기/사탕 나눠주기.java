import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long max = 0;
        long[] A = new long[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
            max = Math.max(max, A[i]);
        }

        long ans = max;
        long L = 0, R = max;
        while (L <= R) {
            long sum = 0;
            long mid = (L + R) / 2;

            for (int i = 0; i < N; i++) {
                if (A[i] <= mid) continue;

                sum += A[i] - mid;
            }

            if (sum > K) {
                L = mid + 1;
            } else {
                R = mid - 1;
                ans = mid;
            }
        }

        System.out.println(ans);
    }
}
