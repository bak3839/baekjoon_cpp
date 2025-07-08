import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int K, N, M, ans;
    static int[] counts, cows;
    static boolean[] visited;
    static List<List<Integer>> graph = new ArrayList<>();

    public static void initialize() {
        cows = new int[K];
        counts = new int[N + 1];
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
    }

    public static void dfs(int now) {
        counts[now]++;
        visited[now] = true;

        for(int next : graph.get(now)) {
            if(visited[next]) continue;

            dfs(next);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        initialize();

        for (int i = 0; i < K; i++) {
            cows[i] = Integer.parseInt(br.readLine());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            graph.get(start).add(end);
        }

        for(int cow : cows) {
            dfs(cow);
            Arrays.fill(visited, false);
        }

        for(int count : counts) {
            if(count == K) ans++;
        }

        System.out.println(ans);
    }
}
