import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans;
    static int[][] map;
    static int[][] mv = {{0, 0}, {1, -1}, {1, 0}, {1, 1}};

    public static void search(int x, int y, int dir, int sum) {
        if(x == N - 1) {
            ans = Math.min(ans, sum);
            return;
        }

        for(int i = 1; i <= 3; i++) {
            if(dir == i) continue;

            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            search(nx, ny, i, map[nx][ny] + sum);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ans = Integer.MAX_VALUE;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int j = 0; j < M; j++) {
            search(0, j, 0, map[0][j]);
        }

        System.out.println(ans);
    }
}
