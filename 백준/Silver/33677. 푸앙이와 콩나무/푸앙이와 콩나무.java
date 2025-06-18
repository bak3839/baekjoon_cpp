import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Main {
    static int N, day = Integer.MAX_VALUE, water = Integer.MAX_VALUE;
    static Beanstalk[] visited;

    public static class Beanstalk {
        int len;
        int day;
        int water;

        public Beanstalk(int len, int day, int water) {
            this.len = len;
            this.water = water;
            this.day = day;
        }
    }

    public static void bfs() {
        Deque<Beanstalk> queue = new ArrayDeque<>();
        queue.offer(new Beanstalk(0, 0, 0));
        visited[0] = new Beanstalk(0, 0, 0);

        while (!queue.isEmpty()) {
            Beanstalk now = queue.poll();

            if(now.len == N && now.day <= day && now.water <= water) {
                day = now.day;
                water = now.water;
            }

            Beanstalk next;

            if(now.len + 1 <= N && visited[now.len + 1].day >= now.day && visited[now.len + 1].water > now.water) {
                next = new Beanstalk(now.len + 1, now.day + 1, now.water + 1);
                visited[now.len + 1] = next;
                queue.offer(next);
            }

            if(now.len * 3 <= N && visited[now.len * 3].day >= now.day && visited[now.len * 3].water > now.water) {
                next = new Beanstalk(now.len * 3, now.day + 1, now.water + 3);
                visited[now.len * 3] = next;
                queue.offer(next);
            }

            long len = (long) now.len * now.len;

            if(len <= (long) N && visited[now.len * now.len].day >= now.day && visited[now.len * now.len].water > now.water) {
                next = new Beanstalk(now.len * now.len, now.day + 1, now.water + 5);
                visited[now.len * now.len] = next;
                queue.offer(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        visited = new Beanstalk[N + 1];
        Arrays.fill(visited, new Beanstalk(Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE));

        bfs();
        System.out.println(day + " " + water);
    }
}