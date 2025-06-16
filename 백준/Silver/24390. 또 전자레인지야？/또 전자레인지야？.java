import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int M, S, target, ans = Integer.MAX_VALUE;
    static int[] times = { 10, 60, 600 };
    static boolean[] visited = new boolean[3601];

    public static class Oven {
        int time;
        int count;

        public Oven(int time, int count) {
            this.time = time;
            this.count = count;
        }

        public int getTime() {
            return time;
        }

        public int getCount() {
            return count;
        }
    }

    public static void bfs(Oven startOven) {
        Deque<Oven> deque = new ArrayDeque<>();
        int startTime = startOven.getTime();
        visited[startOven.getTime()] = true;
        deque.push(startOven);

        while (!deque.isEmpty()) {
            Oven current = deque.pop();
            int time = current.getTime();
            int count = current.getCount();

            if(time == target) {
                ans = Math.min(ans, count);
                break;
            }

            for(int i = 0; i < 3; i++) {
                int nextTime = time + times[i];

                if(nextTime > target || visited[nextTime]) continue;

                visited[nextTime] = true;
                deque.push(new Oven(nextTime, count + 1));
            }
        }

        Arrays.fill(visited, false);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), ":");

        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        target = M * 60 + S;

        bfs(new Oven(30, 1));
        bfs(new Oven(0, 1));

        System.out.println(ans);
    }
}
