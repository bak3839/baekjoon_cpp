import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int[][] A = new int[N + 1][N + 1];
            int[] row = new int[N + 1];
            int[] col = new int[N + 1];

            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 1; j <= N; j++) {
                    int num = Integer.parseInt(st.nextToken());
                    A[i][j] = num + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
                }
            }

            for (int i = 1; i <= M; i++) {
                st = new StringTokenizer(br.readLine());
                int r1 = Integer.parseInt(st.nextToken());
                int c1 = Integer.parseInt(st.nextToken());
                int r2 = Integer.parseInt(st.nextToken());
                int c2 = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                for (int j = r1; j <= r2; j++) {
                    row[j] += v * (c2 - c1 + 1);
                }

                for (int j = c1; j <= c2; j++) {
                    col[j] += v * (r2 - r1 + 1);
                }
            }

            for (int i = 1; i <= N; i++) {
                int res = A[i][N] - A[i - 1][N] - A[i][0] + A[i - 1][0];
                System.out.print(res + row[i] + " ");
            }
            System.out.println();

            for (int i = 1; i <= N; i++) {
                int res = A[N][i] - A[0][i] - A[N][i - 1] + A[0][i - 1];
                System.out.print(res + col[i] + " ");
            }
            System.out.println();
        }
    }
}
