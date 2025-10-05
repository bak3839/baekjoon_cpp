import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            String space = br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            int ans = 0;
            char[][] mat = new char[N + 2][M + 2];
            List<Pair> pairs = new ArrayList<>();

            for (int i = 1; i <= N; i++) {
                String line = br.readLine();
                for (int j = 1; j <= M; j++) {
                    mat[i][j] = line.charAt(j - 1);
                    if (mat[i][j] == 'o')  {
                        pairs.add(new Pair(i, j));
                    }
                }
            }

            for (Pair p : pairs) {
                int x = p.x;
                int y = p.y;
                if (mat[x - 1][y] == 'v' && mat[x + 1][y] == '^') ans++;
                else if (mat[x][y - 1] == '>' && mat[x][y + 1] == '<') ans++;
            }
            System.out.println(ans);
        }
    }
}
