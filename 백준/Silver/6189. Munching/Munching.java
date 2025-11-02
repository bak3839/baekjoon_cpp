import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int R, C;
    static String[] map;
    static boolean[][] visited;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    static class Pair {
        int x;
        int y;
        int count;
        Pair(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }

    public static int bfs(int r, int c) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(r, c, 0));
        visited[r][c] = true;

        while (!q.isEmpty()) {
            Pair p = q.poll();
            int x = p.x;
            int y = p.y;
            int count = p.count;

            if (map[x].charAt(y) == 'B') {
                return count;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny] || map[nx].charAt(ny) == '*') continue;

                q.add(new Pair(nx, ny, count + 1));
                visited[nx][ny] = true;
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new String[R];
        visited = new boolean[R][C];

        int r = 0, c = 0;
        for (int i = 0; i < R; i++) {
            map[i] = br.readLine();
            for (int j = 0; j < C; j++) {
                if (map[i].charAt(j) == 'C') {
                    r = i;
                    c = j;
                }
            }
        }

        System.out.println(bfs(r, c));
    }
}
