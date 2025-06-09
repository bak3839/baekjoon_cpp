import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static long ans;
    static int N, K;
    static int[] T;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        T = new int[N];

        for (int i = 0; i < N; i++) {
            T[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(T);

        K--;
        ans = T[N - 1];

        int cnt = 0, L = 0, R = N - 2;
        while(cnt < K) {
            if(cnt % 2 == 0) {
                L++;
            } else {
                ans += (T[R] - T[L - 1]);
                R--;
            }

            cnt++;
        }

        System.out.println(ans);
    }
}
