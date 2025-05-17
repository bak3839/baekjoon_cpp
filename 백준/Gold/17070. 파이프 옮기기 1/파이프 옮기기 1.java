import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static boolean[][] home = new boolean[20][20];
    static int[][][] dp;

    public static boolean check(int x, int y, int dir) {
        if(dir == 0 || dir == 1) {
            return home[x][y];
        } else {
            return home[x][y] && home[x - 1][y] && home[x][y - 1];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        dp = new int[3][N][N];
        dp[0][0][1] = 1;

        StringTokenizer st;
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++) {
                home[i][j] = Integer.parseInt(st.nextToken()) != 1;
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(check(i, j + 1, 0)) dp[0][i][j + 1] += dp[0][i][j];
                if(check(i + 1, j + 1, 2)) dp[2][i + 1][j + 1] += dp[0][i][j];

                if(check(i + 1, j, 1)) dp[1][i + 1][j] += dp[1][i][j];
                if(check(i + 1, j + 1, 2)) dp[2][i + 1][j + 1] += dp[1][i][j];

                if(check(i, j + 1, 0)) dp[0][i][j + 1] += dp[2][i][j];
                if(check(i + 1, j, 1)) dp[1][i + 1][j] += dp[2][i][j];
                if(check(i + 1, j + 1, 2)) dp[2][i + 1][j + 1] += dp[2][i][j];
            }
        }

        int ans = dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];
        System.out.println(ans);
    }
}
