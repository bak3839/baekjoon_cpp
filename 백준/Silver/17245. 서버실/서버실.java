import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long sum = 0;
        int L = 0, R = 10000000, ans = 10000000;
        int[][] server = new int[1000][1000];
        int N = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++) {
                int n = Integer.parseInt(st.nextToken());
                server[i][j] = n;
                sum += n;
            }
        }

        long target = sum / 2 + (sum % 2 > 0 ? 1 : 0);

        while(L <= R) {
            long res = 0;
            int mid = (L + R) / 2;

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    res += Math.min(server[i][j], mid);
                }
            }

            if(target <= res) {
                R = mid - 1;
                ans = mid;
            } else {
                L = mid + 1;
            }
        }

        System.out.println(ans);
    }
}
