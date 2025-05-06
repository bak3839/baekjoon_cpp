import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans = 0;
    static boolean[][] coin;

    public static void flip(int x, int y) {
        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {
                coin[i][j] = !coin[i][j];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        coin = new boolean[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();

            for (int j = 0; j < M; j++) {
                coin[i][j] = s.charAt(j) != '0';
            }
        }

        for(int i = N - 1; i >= 0; i--) {
            for(int j = M - 1; j >= 0; j--) {
                if(!coin[i][j]) continue;

                ans++;
                flip(i, j);
            }
        }

        System.out.println(ans);
    }
}
