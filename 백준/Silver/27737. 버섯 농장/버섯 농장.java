import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, K;
    static boolean[][] visited;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bfs(int a, int b) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(a, b));
        visited[a][b] = true;

        int cnt = 1;

        while(!q.isEmpty()) {
            Pair p = q.poll();
            if(cnt == K) return;

            for(int i = 0; i < 4; i++) {
                int nx = p.x + mv[i][0];
                int ny = p.y + mv[i][1];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;

                q.add(new Pair(nx, ny));
                visited[nx][ny] = true;
                cnt++;

                if(cnt == K) return;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        visited = new boolean[N][N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++) {
                int n = Integer.parseInt(st.nextToken());
                if(n == 1) visited[i][j] = true;
            }
        }

        int tmp = M;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j]) continue;

                tmp--;
                bfs(i, j);
            }
        }

        if(tmp < 0 || tmp == M) System.out.println("IMPOSSIBLE");
        else System.out.println("POSSIBLE\n" + tmp);
    }
}
