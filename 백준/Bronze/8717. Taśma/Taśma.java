import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] sum = new int[N + 1];
        int ans = Integer.MAX_VALUE;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            sum[i] += Integer.parseInt(st.nextToken()) + sum[i - 1];
        }

        for (int i = 1; i < N; i++) {
            int len1 = sum[i];
            int len2 = sum[N] - sum[i];
            ans = Math.min(ans, Math.abs(len2 - len1));
        }
        System.out.println(ans);
    }
}
