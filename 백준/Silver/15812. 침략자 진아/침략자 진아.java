import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, total, ans = Integer.MAX_VALUE;
    static char[][] map;
    static List<Pair> pairs = new ArrayList<>();
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    static class Pair {
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bfs() {
        Queue<Pair> queue = new LinkedList<>();
        char[][] temp = new char[N][M];
        int count = 0, result = 0;

        for(int i = 0; i < N; i++) {
            System.arraycopy(map[i], 0, temp[i], 0, M);
        }

        pairs.forEach(pair -> {
            queue.offer(pair);
            temp[pair.x][pair.y] = 'x';
        });

        while (!queue.isEmpty()) {
            int size = queue.size();
            result++;

            while(size-- > 0) {
                Pair pair = queue.poll();
                int x = pair.x;
                int y = pair.y;

                if(count == total) {
                    ans = Math.min(ans, result);
                    return;
                }

                for(int i = 0; i < 4; i++) {
                    int nx = x + mv[i][0];
                    int ny = y + mv[i][1];

                    if(nx < 0 || ny < 0 || nx >= N || ny >= M || temp[nx][ny] == 'x') continue;
                    if(temp[nx][ny] == '1') count++;

                    temp[nx][ny] = 'x';
                    queue.add(new Pair(nx, ny));
                }
            }
        }
    }

    public static void search(int x, int y) {
        if(pairs.size() == 2) {
            bfs();
            return;
        }

        int tmp = y;

        for(int i = x; i < N; i++) {
            for(int j = tmp; j < M; j++) {
                if(map[i][j] == '1') continue;

                pairs.add(new Pair(i, j));
                search(i, j + 1);
                pairs.remove(pairs.size() - 1);
            }

            tmp = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new char[N][M];

        for(int i = 0; i < N; i++) {
            String line = br.readLine();
            for(int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j);
                if(map[i][j] == '1') { total++; }
            }
        }

        search(0, 0);
        System.out.println(ans);
    }
}
