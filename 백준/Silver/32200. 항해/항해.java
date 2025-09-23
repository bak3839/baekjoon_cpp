import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());
        int discard = 0, ans = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(st.nextToken());

            int res = a / X;
            int remain = a % X;

            for (int j = 0; j < res; j++) {
                if (remain <= 0) break;
                remain -= Y - X;
            }

            ans += res;
            discard += Math.max(0, remain);
        }

        System.out.println(ans);
        System.out.println(discard);
    }
}
