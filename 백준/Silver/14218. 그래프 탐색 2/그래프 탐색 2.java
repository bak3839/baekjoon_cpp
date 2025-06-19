import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, Q;
    static int[] dist;
    static List<List<Integer>> graph = new ArrayList<>();

    public static void connectCity(int v1, int v2) {
        graph.get(v1).add(v2);
        graph.get(v2).add(v1);
    }

    public static void bfs(int start) {
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(start);

        while (!queue.isEmpty()) {
            int current = queue.poll();
            int currentDist = dist[current];

            for (int next : graph.get(current)) {
                if (dist[next] <= currentDist + 1) {
                    continue;
                }

                queue.offer(next);
                dist[next] = currentDist + 1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        int v1, v2;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            v1 = Integer.parseInt(st.nextToken());
            v2 = Integer.parseInt(st.nextToken());
            connectCity(v1, v2);
        }

        dist[1] = 0;
        bfs(1);

        Q = Integer.parseInt(br.readLine());
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            v1 = Integer.parseInt(st.nextToken());
            v2 = Integer.parseInt(st.nextToken());
            connectCity(v1, v2);

            if(dist[v1] != Integer.MAX_VALUE) { bfs(v1); }
            if(dist[v2] != Integer.MAX_VALUE) { bfs(v2); }

            for(int j = 1; j <= N; j++) {
                System.out.print(dist[j] == Integer.MAX_VALUE ? "-1 " : dist[j] + " ");
            }
            System.out.println();
        }
    }
}
