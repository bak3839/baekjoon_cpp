import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int N, K, ans;
    static Integer[][] combination;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        combination = new Integer[3][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            combination[0][i] = a + b;
            combination[1][i] = a + c;
            combination[2][i] = b + c;
        }

        for(int i = 0; i < 3; i++) {
            Arrays.sort(combination[i], Collections.reverseOrder());

            int sum = 0;
            for(int j = 0; j < K; j++) {
                sum += combination[i][j];
            }

            ans = Math.max(sum, ans);
        }

        System.out.println(ans);
    }
}
