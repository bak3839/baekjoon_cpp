import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        int count = 0, now = m, ans = 0;
        while (count < N) {
            if (m + T > M) {
                ans = -1;
                break;
            }

            if (now + T <= M) {
                count++;
                now += T;
            } else {
                now = Math.max(now - R, m);
            }
            ans++;
        }

        System.out.println(ans);
    }
}
