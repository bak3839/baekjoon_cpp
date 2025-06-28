import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int X, Y, M, ans;

    public static void search(int a, int b) {
        int n = M / a;

        while (n > 0) {
            int rest = M - (n * a);
            int res = rest % b;
            ans = Math.max(M - res, ans);
            n--;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        search(X, Y);
        search(Y, X);

        System.out.println(ans);
    }
}
