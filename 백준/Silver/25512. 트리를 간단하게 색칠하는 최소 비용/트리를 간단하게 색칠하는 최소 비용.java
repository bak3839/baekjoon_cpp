import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] depth;
    static int[][] cost;
    static List<List<Integer>> graph;
    
    public static void initialize() {
        depth = new int[N];
        cost = new int[N][2];
        graph = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            depth[i] = -1;
            graph.add(new ArrayList<>());
        }
    }
    
    public static void dfs(int now, int count) {
        depth[now] = count;

        for (int next : graph.get(now)) {
            if (depth[next] != -1) continue;

            dfs(next, count + 1);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        
        N = Integer.parseInt(br.readLine());
        initialize();
        
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            graph.get(p).add(c);
            graph.get(c).add(p);
        }
        
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0);

        long sum1 = 0, sum2 = 0;
        for (int i = 0; i < N; i++) {
            sum1 += cost[i][depth[i] % 2];
            sum2 += cost[i][(depth[i] + 1) % 2];
        }

        System.out.println(Math.min(sum1, sum2));
    }
}
