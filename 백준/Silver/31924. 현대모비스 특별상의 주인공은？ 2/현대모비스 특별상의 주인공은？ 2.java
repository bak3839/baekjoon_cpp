import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, ans;
    static char[][] mat;
    static final String target = "MOBIS";
    static int[][] mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    public static void search(int x, int y) {
        for (int[] m : mv) {
            boolean found = true;
            int tmpX = x, tmpY = y;

            for (int i = 1; i < 5; i++) {
                int nx = tmpX + m[0];
                int ny = tmpY + m[1];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N || mat[nx][ny] != target.charAt(i)) {
                    found = false;
                    break;
                }

                tmpX = nx; tmpY = ny;
            }

            if (found) ans++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        mat = new char[N][N];

        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            for (int j = 0; j < N; j++) {
                mat[i][j] = input.charAt(j);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 'M') search(i, j);
            }
        }

        System.out.println(ans);
    }
}
