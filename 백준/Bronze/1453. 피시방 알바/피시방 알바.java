import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0;
        int N = Integer.parseInt(br.readLine());
        boolean[] visited = new boolean[101];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            if (visited[num]) {
                ans++;
                continue;
            }
            visited[num] = true;
        }
        System.out.println(ans);
    }
}
