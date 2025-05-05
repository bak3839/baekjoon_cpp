import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, B, ans;
    static int[] H;

    public static void search(int x, int sum) {
        if(sum >= B) {
            ans = Math.min(ans, sum);
            return;
        }

        for(int i = x; i < N; i++) {
            search(i + 1, sum + H[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ans = Integer.MAX_VALUE;
        N = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        H = new int[N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            H[i] = h;
        }

        search(0, 0);
        System.out.println(ans - B);
    }
}
