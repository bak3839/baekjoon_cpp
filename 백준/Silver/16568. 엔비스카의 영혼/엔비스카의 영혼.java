import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static int N, a, b;
    static int[] visited;

    public static class Step {
        int time;
        int count;

        public Step(int time, int count) {
            this.time = time;
            this.count = count;
        }
    }

    public static int bfs() {
        Deque<Step> queue = new ArrayDeque<>();
        queue.offer(new Step(0, N));
        visited[N] = 0;

        while (!queue.isEmpty()) {
            Step current = queue.poll();

            if(current.count == 0) return current.time;

            int nextTime = current.time + 1;

            if(current.count - a - 1 >= 0 && visited[current.count - a - 1] > nextTime) {
                visited[current.count - a - 1] = nextTime;
                queue.offer(new Step(nextTime, current.count - a - 1));
            }

            if(current.count - b - 1 >= 0 && visited[current.count - b - 1] > nextTime) {
                visited[current.count - b - 1] = nextTime;
                queue.offer(new Step(nextTime, current.count - b - 1));
            }

            if(current.count - 1 >= 0 && visited[current.count - 1] > nextTime) {
                visited[current.count - 1] = nextTime;
                queue.offer(new Step(nextTime, current.count - 1));
            }
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        visited = new int[N + 1];
        Arrays.fill(visited, Integer.MAX_VALUE);

        System.out.println(bfs());
    }
}
