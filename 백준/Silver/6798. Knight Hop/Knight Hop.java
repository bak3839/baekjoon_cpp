import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int sx, sy, ex, ey;
    static boolean[][] visited = new boolean[9][9];
    static int[][] mv = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    static class Night {
        int x, y, count;

        Night(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }

    static void bfs() {
        Queue<Night> q = new LinkedList<>();
        q.offer(new Night(sx, sy, 0));
        visited[sx][sy] = true;

        while (!q.isEmpty()) {
            Night now = q.poll();
            if (now.x == ex && now.y == ey) {
                System.out.println(now.count);
                break;
            }

            for (int[] m : mv) {
                int nx = now.x + m[0];
                int ny = now.y + m[1];

                if (nx <= 0 || ny <= 0 || nx >= 9 || ny >= 9 || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.offer(new Night(nx, ny, now.count + 1));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input1 = br.readLine();
        String input2 = br.readLine();

        sx = Integer.parseInt(input1.split(" ")[0]);
        sy = Integer.parseInt(input1.split(" ")[1]);
        ex = Integer.parseInt(input2.split(" ")[0]);
        ey = Integer.parseInt(input2.split(" ")[1]);

        bfs();
    }
}
