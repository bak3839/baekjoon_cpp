import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[] sum = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int n = Integer.parseInt(br.readLine());
            sum[i] = sum[i - 1] + n;
        }

        for (int i = 1; i <= Q; i++) {
            int n = Integer.parseInt(br.readLine());

            int L = 1, R = N, res = 0;

            while (L <= R) {
                int mid = (L + R) / 2;

                if (sum[mid] > n) {
                    R = mid - 1;
                    res = mid;
                } else {
                    L = mid + 1;
                }
            }

            System.out.println(res);
        }
    }
}
