import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans;
    static char[][] map;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    public static class Coordinate {
        int x, y;
        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bfs(int x, int y) {
        int count = 1;
        Queue<Coordinate> queue = new LinkedList<>();
        queue.add(new Coordinate(x, y));
        map[x][y] = '*';

        while (!queue.isEmpty()) {
            Coordinate current = queue.poll();

            for(int[] m : mv) {
                int nx = current.x + m[0];
                int ny = current.y + m[1];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == '*') continue;

                count++;
                map[nx][ny] = '*';
                queue.add(new Coordinate(nx, ny));
            }
        }

        ans = Math.max(ans, count);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        map = new char[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == '*') continue;

                bfs(i, j);
            }
        }

        System.out.println(ans);
    }
}
