import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M;
    static boolean[] visited, closed;
    static List<List<Integer>> graph = new ArrayList<>();

    public static int bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;

        int count = 1;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int next : graph.get(current)) {
                if (visited[next] || closed[next]) continue;

                count++;
                queue.add(next);
                visited[next] = true;
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        closed = new boolean[N + 1];
        visited = new boolean[N + 1];

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        int total = N;

        for (int i = 0; i < N; i++) {
            int n = Integer.parseInt(br.readLine());
            int start = 0;

            for (int j = 1; j <= N; j++) {
                if(closed[j]) continue;

                start = j;
                break;
            }

            int count = bfs(start);

            if (count == total) System.out.println("YES");
            else System.out.println("NO");

            total--;
            closed[n] = true;
            Arrays.fill(visited, false);
        }
    }
}
