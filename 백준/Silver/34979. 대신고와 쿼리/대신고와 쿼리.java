import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, Q;
    static int[][] counts;

    static void spread(int x, int y) {
        int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int[] m : mv) {
            int nx = x + m[0];
            int ny = y + m[1];

            if (nx <= 0 || ny <= 0 || nx > 4 || ny > N) continue;

            counts[nx][ny]++;
        }
        counts[x][y]++;
    }

    static int maxAngry(int a) {
        int max = counts[a][1], num = 1;
        for (int i = 2; i <= N; i++) {
            if (max >= counts[a][i]) continue;

            max = counts[a][i];
            num = i;
        }

        return num;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        counts = new int[5][N + 1];

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            if (n == 1) {
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                spread(a, b);
            } else {
                int a = Integer.parseInt(st.nextToken());
                System.out.println(maxAngry(a));
            }
        }

        int max = 0, num = 1, floor = 1;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= N; j++) {
                if (max >= counts[i][j]) continue;

                max = counts[i][j];
                floor = i;
                num = j;
            }
        }
        System.out.println(floor + " " + num);
    }
}
