import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] total = new int[N + 1];
        int ans = 0;

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());

            for(int j = 0; j < n; j++) {
                total[i] += Integer.parseInt(st.nextToken());
            }
        }

        Arrays.sort(total);

        for(int i = 1; i <= N; i++) {
            total[i] += total[i - 1];
            ans += total[i];
        }

        System.out.println(ans);
    }
}
