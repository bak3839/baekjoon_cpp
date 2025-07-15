import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, ans;
    static double[] size;

    public static void search(int x, int count, int target, double sum) {
        if (sum > 1.01) return;

        if(count == target) {
            if (0.99 <= sum && sum <= 1.01) {
                ans++;
                return;
            }
        }

        for (int i = x; i < N; i++) {
            search(i + 1, count + 1, target, sum + size[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        size = new double[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int c = Integer.parseInt(st.nextToken());
            size[i] = (double) 1 / c;
        }

        for(int i = 2; i <= N; i++) {
            search(0, 0, i, 0.0);
        }

        System.out.println(ans);
    }
}
