import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0;
        int N = Integer.parseInt(br.readLine());
        int[][] counts = new int[3][N + 1];

        for (int i = 1; i <= N; i++) {
            char ch = br.readLine().charAt(0);

            if (ch == 'P') {
                counts[0][i]++;
            } else if (ch == 'H') {
                counts[1][i]++;
            } else {
                counts[2][i]++;
            }

            counts[0][i] += counts[0][i - 1];
            counts[1][i] += counts[1][i - 1];
            counts[2][i] += counts[2][i - 1];
        }

        for (int i = 1; i <= N; i++) {
            int maxL = Math.max(counts[0][i], Math.max(counts[1][i], counts[2][i]));
            int maxR = Math.max(counts[0][N] - counts[0][i], Math.max(counts[1][N] - counts[1][i], counts[2][N] - counts[2][i]));
            ans = Math.max(ans, maxL + maxR);
        }

        System.out.println(ans);
    }
}
