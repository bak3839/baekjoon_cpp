import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static int total, ans;
    static int[][] mv = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    static boolean[][] stone = new boolean[6][6];
    static boolean[][] visited = new boolean[6][6];

    public static void search(int type, int x, int y, int targetX, int targetY, int count) {
        if(count > total) return;

        if(count == total && x == targetX && y == targetY) {
            if(type == 0) search(1, 5, 5, targetX, targetY, 0);
            else ans++;
            return;
        }

        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if(nx <= 0 || ny <= 0 || nx > 5 || ny > 5) continue;
            if(stone[nx][ny] || visited[nx][ny]) continue;


            search(type, nx, ny, targetX, targetY, count + 1);
        }

        visited[x][y] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        for(int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            stone[x][y] = true;
        }
        total = (24 - K) / 2;

        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <= 5; j++) {
                if((i == 1 && j == 1) || (i == 5 && j == 5)) continue;
                if(stone[i][j]) continue;

                search(0, 1, 1, i, j, 0);
            }
        }

        System.out.println(ans);
    }
}
