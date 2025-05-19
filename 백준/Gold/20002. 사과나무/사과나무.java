import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, ans = Integer.MIN_VALUE;
    static int[][] map;

    public static void search(int d) {
        for(int i = 1 + d; i <= N; i++) {
            for(int j = 1 + d; j <= N; j++) {
                int res = map[i][j] - map[i][j - d - 1] - map[i - d - 1][j] + map[i - d - 1][j - d - 1];
                ans = Math.max(ans, res);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        map = new int[N + 1][N + 1];

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                ans = Math.max(ans, map[i][j]);
                map[i][j] += map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1];
            }
        }

        for(int i = 1; i <= N; i++) {
            search(i);
        }

        System.out.println(ans);
    }
}
