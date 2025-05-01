import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class Main {
    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        Pair[] pairs = new Pair[N];
        int[] distances = new int[N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pairs[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        int sum = 0, ans = Integer.MAX_VALUE;

        for(int i = 0; i < N - 1; i++) {
            int x1 = pairs[i].x, x2 = pairs[i + 1].x;
            int y1 = pairs[i].y, y2 = pairs[i + 1].y;

            distances[i] = Math.abs(x1 - x2) + Math.abs(y1 - y2);
            sum += distances[i];
        }

        for(int i = 1; i < N - 1; i++) {
            int x1 = pairs[i - 1].x, x2 = pairs[i + 1].x;
            int y1 = pairs[i - 1].y, y2 = pairs[i + 1].y;

            int distance = Math.abs(x1 - x2) + Math.abs(y1 - y2);
            int res = sum - distances[i - 1] - distances[i] + distance;

            ans = Math.min(ans, res);
        }

        System.out.println(ans);
    }
}
