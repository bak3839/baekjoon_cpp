import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, K;
    static int[][] dist;
    static List<List<Integer>> graph = new ArrayList<>();

    public static void initialize() {
        dist = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            graph.add(new ArrayList<>());
        }
    }

    public static void bfs(int start) {
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(start);
        dist[start][start] = 0;

        int count = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                int current = queue.poll();

                for (Integer next : graph.get(current)) {
                    if (dist[start][next] != Integer.MAX_VALUE) continue;

                    queue.offer(next);
                    dist[start][next] = count;
                }
            }

            count++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        initialize();

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            graph.get(v1).add(v2);
            graph.get(v2).add(v1);
        }

        for (int i = 1; i <= N; i++) {
            bfs(i);
        }

        boolean result = true;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] != Integer.MAX_VALUE && dist[i][j] <= 6) continue;

                result = false;
                break;
            }
        }

        if (result) System.out.println("Small World!");
        else System.out.println("Big World!");
    }
}
