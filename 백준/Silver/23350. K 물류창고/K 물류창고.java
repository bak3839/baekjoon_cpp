import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans;
    static int[] count;
    static Queue<Container> rail = new ArrayDeque<>();
    static Deque<Container> load = new ArrayDeque<>();
    static Deque<Container> temp = new ArrayDeque<>();

    public static class Container {
        int priority;
        int weight;

        Container(int priority, int weight) {
            this.priority = priority;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        count = new int[M + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int P = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            rail.add(new Container(P, W));
            count[P]++;
        }

        int priority = M;

        while (!rail.isEmpty()) {
            Container now = rail.poll();

            if (now.priority < priority) {
                rail.add(now);
                ans += now.weight;
            }

            else if (load.isEmpty()) {
                load.push(now);
                ans += now.weight;
                priority = decrementCount(priority);
            }

            else if (now.priority == priority && now.weight <= load.peek().weight) {
                load.push(now);
                ans += now.weight;
                priority = decrementCount(priority);
            }
            
            else if (now.priority == priority && now.weight > load.peek().weight) {
                while(cannotLoad(priority, now)) {
                    ans += load.peek().weight * 2;
                    temp.push(load.pop());
                }
                load.push(now);
                ans += now.weight;

                while(!temp.isEmpty()) {
                    load.push(temp.pop());
                }
                priority = decrementCount(priority);
            }
        }

        System.out.println(ans);
    }

    private static int decrementCount(int priority) {
        count[priority]--;
        if (count[priority] == 0) { priority--; }
        return priority;
    }

    private static boolean cannotLoad(int priority, Container now) {
        return !load.isEmpty() && load.peek().priority == priority && now.weight > load.peek().weight;
    }

}
