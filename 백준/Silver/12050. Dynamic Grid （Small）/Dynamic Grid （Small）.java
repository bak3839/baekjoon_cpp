import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int T, R, C, N;
    static char[][] grid;
    static boolean[][] visited;
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public static void dfs(int x, int y) {
        visited[x][y] = true;

        for (int[] m : mv) {
            int nx = x + m[0];
            int ny = y + m[1];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny] || grid[nx][ny] == '0') continue;

            dfs(nx, ny);
        }
    }

    public static void initialize(StringTokenizer st, BufferedReader br) throws IOException {
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        grid = new char[R][C];
        visited = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            String line = br.readLine();
            for (int j = 0; j < C; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
    }

    public static int countConnecting() {
        int ans = 0;
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                if (visited[x][y] || grid[x][y] == '0') continue;

                ans++;
                dfs(x, y);
            }
        }

        for (int x = 0; x < R; x++) {
            Arrays.fill(visited[x], false);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int count = 1;
        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            initialize(st, br);

            System.out.println("Case #" + count + ":");
            N = Integer.parseInt(br.readLine());

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                char type = st.nextToken().charAt(0);

                if (type == 'M') {
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    char z = st.nextToken().charAt(0);
                    grid[x][y] = z;
                } else {
                    System.out.println(countConnecting());
                }
            }

            count++;
        }
    }
}
