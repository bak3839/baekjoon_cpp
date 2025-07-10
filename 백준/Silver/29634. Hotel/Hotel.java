import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static char[][] floor;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public static class Coordinate {
        int x, y;
        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int bfs(int x, int y) {
        Queue<Coordinate> queue = new LinkedList<>();
        queue.add(new Coordinate(x, y));
        floor[x][y] = '*';
        int count = 1;

        while (!queue.isEmpty()) {
            Coordinate current = queue.poll();

            for(int i = 0; i < 4; i++) {
                int nx = current.x + mv[i][0];
                int ny = current.y + mv[i][1];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M || floor[nx][ny] == '*') continue;

                count++;
                floor[nx][ny] = '*';
                queue.add(new Coordinate(nx, ny));
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int ans = 0;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        floor = new char[N][M];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                floor[i][j] = line.charAt(j);
            }
        }

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if(floor[i][j] == '*') continue;

                ans = Math.max(ans, bfs(i, j));
            }
        }

        if(ans == 0) System.out.println(-1);
        else System.out.println(ans);
    }
}
