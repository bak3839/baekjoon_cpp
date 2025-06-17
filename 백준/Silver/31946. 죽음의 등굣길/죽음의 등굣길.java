import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, X;
    static int[][] map;
    static int[][] base = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    static List<Pair> mv = new ArrayList<>();

    public static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static boolean bfs() {
        Deque<Pair> queue = new ArrayDeque<>();
        queue.push(new Pair(0, 0));
        int block = map[0][0];
        map[0][0] = -1;

        while (!queue.isEmpty()) {
            Pair pair = queue.pop();
            int x = pair.x;
            int y = pair.y;

            if (x == N - 1 && y == M - 1) return true;

            for (Pair step : mv) {
                for(int i = 0; i < 4; i++) {
                    int nx = x + (step.x * base[i][0]);
                    int ny = y + (step.y * base[i][1]);

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == -1 || map[nx][ny] != block) continue;

                    map[nx][ny] = -1;
                    queue.push(new Pair(nx, ny));
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        X = Integer.parseInt(br.readLine());

        for (int i = 1; i <= X; i++) {
            int xIndex = i;
            int yIndex = 0;

            while (xIndex >= 0 && yIndex <= i) {
                mv.add(new Pair(xIndex--, yIndex++));
            }
        }

        if(bfs()) System.out.println("ALIVE");
        else System.out.println("DEAD");
        br.close();
    }
}

