import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, X, Y;
    static int[][] res;
    static int[][] mv = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int bfs() {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(X, Y));
        res[X][Y] = 0;

        int cnt = 1;

        while(!q.isEmpty()) {
            int size = q.size();

            while(size-- > 0) {
                Pair pair = q.poll();
                int x = pair.x, y = pair.y;

                for(int i = 0; i < 8; i++) {
                    int nx = x + mv[i][0];
                    int ny = y + mv[i][1];

                    if(nx < 1 || ny < 1 || nx > N || ny > N || res[nx][ny] > -1) continue;

                    res[nx][ny] = cnt;
                    q.add(new Pair(nx, ny));
                }
            }

            cnt++;
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] ans = new int[M];

        st = new StringTokenizer(br.readLine());

        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        res = new int[N + 1][N + 1];
        for(int j = 0; j < N + 1; j++) {
            Arrays.fill(res[j], -1);
        }

        bfs();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            System.out.print(res[A][B] + " ");
        }
    }
}
