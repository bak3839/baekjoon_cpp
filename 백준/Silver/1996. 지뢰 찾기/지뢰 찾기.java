import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static String[] map;
    static int[][] counts;
    static int[][] mv = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    public static void search(int x, int y) {
        for (int[] m : mv) {
            int nx = x + m[0];
            int ny = y + m[1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (map[nx].charAt(ny) == '.') continue;
            counts[x][y] += map[nx].charAt(ny) - '0';
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new String[N];
        counts = new int[N][N];

        for (int i = 0; i < N; i++) {
            map[i] = br.readLine();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char now = map[i].charAt(j);
                if (now != '.') {
                    counts[i][j] = -1;
                    continue;
                }

                search(i, j);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (counts[i][j] != -1) {
                    System.out.print(counts[i][j] >= 10 ? "M" : counts[i][j]);
                } else {
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }
}