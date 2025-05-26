import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans;
    static int[][] points = new int[2][3];

    public static void search(int prev, int cnt, int sum) {
        if(cnt == N) {
            if(sum >= M) ans++;
            return;
        }
        for(int i = 0; i < 3; i++) {
            int point1 = points[0][i];
            int point2 = points[1][i];
            if(i == prev) {
                point1 /= 2;
                point2 /= 2;
            }

            search(i, cnt + 1, sum + point1);
            search(i, cnt + 1, sum + point2);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < 2; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 3; j++) {
                points[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        search(-1, 0, 0);
        System.out.println(ans);
    }
}