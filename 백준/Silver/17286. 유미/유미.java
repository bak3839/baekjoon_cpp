import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int startX, startY, ans = Integer.MAX_VALUE;
    static Pair[] pairs = new Pair[3];
    static Pair[] seq = new Pair[3];
    static boolean[] visited = new boolean[3];

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void calculate() {
        double sum = 0.0;
        int nowX = startX, nowY = startY;
        for (int i = 0; i < 3; i++) {
            int distX = nowX - seq[i].x;
            int distY = nowY - seq[i].y;
            sum += Math.sqrt(distX * distX + distY * distY);
            nowX = seq[i].x;
            nowY = seq[i].y;
        }
        ans = Math.min(ans, (int) sum);
    }

    public static void search(int cnt) {
        if (cnt == 3) {
            calculate();
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            seq[cnt] = pairs[i];
            search(cnt + 1);
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        startX = Integer.parseInt(st.nextToken());
        startY = Integer.parseInt(st.nextToken());

        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pairs[i] = new Pair(x, y);
        }

        search(0);
        System.out.println(ans);
    }
}
