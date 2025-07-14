import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int T, N, ans;
    static char[][] map;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    public static class Coordinate {
        int x, y;
        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void initialize(BufferedReader br) throws IOException {
        map = new char[N][N];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = line.charAt(j);
            }
        }
    }

    public static void bfs(int x, int y) {
        Queue<Coordinate> queue = new LinkedList<>();
        queue.add(new Coordinate(x, y));
        map[x][y] = 'b';

        while (!queue.isEmpty()) {
            Coordinate current = queue.poll();

            for(int[] m : mv) {
                int nx = current.x + m[0];
                int ny = current.y + m[1];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 'b') continue;

                if(map[nx][ny] == '-') ans++;

                map[nx][ny] = 'b';
                queue.add(new Coordinate(nx, ny));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            ans = 0;
            N = Integer.parseInt(br.readLine());
            initialize(br);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(map[i][j] != 'w') continue;

                    bfs(i, j);
                }
            }

            System.out.println(ans);
        }
    }
}
