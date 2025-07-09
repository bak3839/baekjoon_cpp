import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, ans = Integer.MAX_VALUE;
    static boolean[] visited;
    static Set<Integer> result = new HashSet<>();
    static List<List<Node>> graph = new ArrayList<>();

    public static class Node {
        int number;
        int[] time = new int[2];
        public Node(int number, int C, int D) {
            this.number = number;
            this.time[0] = C;
            this.time[1] = D;
        }
    }

    public static void initialize() {
        visited = new boolean[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
    }

    public static void dfs(int type, int now, int sum) {
        if(now == N) {
            if(type == 0) {
                result.add(sum);
            } else {
                if(result.contains(sum)) {
                    ans = Math.min(ans, sum);
                }
            }
            return;
        }

        visited[now] = true;

        for(Node next : graph.get(now)) {
            if(visited[next.number]) continue;
            dfs(type, next.number, sum + next.time[type]);
        }

        visited[now] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        initialize();

        int A, B, C, D;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());

            graph.get(A).add(new Node(B, C, D));
        }

        dfs(0, 1, 0);
        dfs(1, 1, 0);

        if(ans == Integer.MAX_VALUE) System.out.println("IMPOSSIBLE");
        else System.out.println(ans);
    }
}
