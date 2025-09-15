import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int count = 0;
            boolean[] used = new boolean[M + 1];

            for (int i = 0; i < N; i++) {
                int n = Integer.parseInt(br.readLine());

                if (used[n]) continue;

                count++;
                used[n] = true;
            }

            System.out.println(N - count);
        }
    }
}
