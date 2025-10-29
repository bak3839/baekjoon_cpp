import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int total = 0, ans = -1, num = 0;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            total += Integer.parseInt(st.nextToken());

            if (total > K && ans == -1) {
                ans = i + 1;
            }
        }

        if (ans == -1) System.out.println(-1);
        else System.out.println(ans + " " + 1);
    }
}
