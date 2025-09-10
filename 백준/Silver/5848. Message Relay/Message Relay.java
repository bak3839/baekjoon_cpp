import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] graph;
    static boolean[] visited;

    public static int dfs(int now, int depth) {
        visited[now] = true;
        
        int next = graph[now];

        if (next == 0) {
            visited[now] = false;
            return 0;
        }
        if (visited[next]) return depth;

        int res = dfs(next, depth + 1);
        if (res == 0) visited[now] = false;

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int ans = 0;
        graph = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i < N; i++) {
            int n = Integer.parseInt(br.readLine());
            graph[i + 1] = n;
        }

        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;

            ans += dfs(i, 1);
        }

        System.out.println(N - ans);
    }
}
