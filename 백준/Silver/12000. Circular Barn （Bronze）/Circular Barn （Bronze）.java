import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N, ans = Integer.MAX_VALUE;
    static int[] r;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        r = new int[N];

        for (int i = 0; i < N; i++) {
            r[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < N; i++) {
            int index = i, count = 0, res = 0;

            while (count < N) {
                res += (r[index] * count++);
                index = (index + 1) % N;
            }

            ans = Math.min(ans, res);
        }

        System.out.println(ans);
    }
}
