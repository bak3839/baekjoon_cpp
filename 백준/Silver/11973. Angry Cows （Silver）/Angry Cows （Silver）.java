import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] x = new int[N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(x);

        int L = 1, R = 1000000000, ans = 0;

        while(L <= R) {
            int idx = 0, cnt = 0;
            int mid = (L + R) / 2;

            while(idx < N) {
                int target = x[idx] + (mid * 2);
                
                while(idx < N) {
                    if(x[idx] > target) break;

                    idx++;
                }

                cnt++;
            }

            if(cnt <= K) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        System.out.println(ans);
    }
}
