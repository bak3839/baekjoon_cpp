import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<List<Node>> graph = new ArrayList<>();
    static boolean[] visited;
    static long ans;

    static class Node {
        int n;
        long dist;
        public Node(int n, long dist) {
            this.n = n;
            this.dist = dist;
        }
    }

    static void dfs(int num, long sum) {
        visited[num] = true;
        ans = Math.max(ans, sum);

        for (Node node : graph.get(num)) {
            int next = node.n;
            long dist = node.dist;
            if (visited[next]) continue;
            dfs(next, dist + sum);
        }

        visited[num] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            long C = Long.parseLong(st.nextToken());
            graph.get(A).add(new Node(B, C));
            graph.get(B).add(new Node(A, C));
        }

        dfs(1, 0);
        System.out.println(ans);
    }
}
