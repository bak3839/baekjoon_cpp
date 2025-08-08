import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        long[] sum = new long[N + 1];

        long cnt = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int num = Integer.parseInt(st.nextToken());

            if (num == K) cnt =0;
            else cnt++;

            sum[i] = sum[i - 1] + cnt;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= Q; i++) {
            int num = Integer.parseInt(st.nextToken());
            System.out.println(sum[num]);
        }
    }
}
