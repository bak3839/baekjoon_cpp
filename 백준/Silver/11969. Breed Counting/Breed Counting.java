import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[][] sum = new int[4][N + 1];

        for (int i = 1; i <= N; i++) {
            int num = Integer.parseInt(br.readLine());
            sum[1][i] += sum[1][i - 1];
            sum[2][i] += sum[2][i - 1];
            sum[3][i] += sum[3][i - 1];
            sum[num][i]++;
        }

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int ans1 = sum[1][b] - sum[1][a - 1];
            int ans2 = sum[2][b] - sum[2][a - 1];
            int ans3 = sum[3][b] - sum[3][a - 1];
            System.out.println(ans1 + " " + ans2 + " " + ans3);
        }
    }
}
