import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans = Integer.MAX_VALUE;
    static int[][] counts;

    public static void change(int w, int b) {
        int res = 0;

        for(int i = 0; i < w; i++) {
            res += counts[i][1] + counts[i][2];
        }

        for(int i = w; i < w + b; i++) {
            res += counts[i][0] + counts[i][2];
        }

        for(int i = w + b; i < N; i++) {
            res += counts[i][0] + counts[i][1];
        }

        ans = Math.min(ans, res);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        counts = new int[N][3];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (char ch : line.toCharArray()) {
                if (ch == 'W') counts[i][0]++;
                else if (ch == 'B') counts[i][1]++;
                else counts[i][2]++;
            }
        }

        for (int W = 1; W <= N - 2; W++) {
            for (int B = 1; B <= N - W - 1; B++) {
                change(W, B);
            }
        }

        System.out.println(ans);
    }
}
