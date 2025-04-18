import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
    static class Pair {
        int x;
        int y;
        int cnt;

        Pair(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }

    static int N, M;
    static int[][] mv = {{1, 0}, {0, 1}};

    public static int BFS(int a, int b, int[][] map) {
        int ans = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(a, b, map[a][b]));
        map[a][b] = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            while(size-- > 0) {
                int x = q.peek().x;
                int y = q.peek().y;
                int cnt = q.peek().cnt;
                q.remove();

                if(x == N - 1 && y == M - 1) return ans;

                for (int i = 0; i < 2; i++) {
                    for(int j = 1; j <= cnt; j++) {
                        int nx = x + mv[i][0] * j;
                        int ny = y + mv[i][1] * j;

                        if(nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 0) continue;

                        q.add(new Pair(nx, ny, map[nx][ny]));
                        map[nx][ny] = 0;
                    }
                }
            }

            ans++;
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(BFS(0, 0, map));
    }
}
