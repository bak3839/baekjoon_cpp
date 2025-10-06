import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int N, K, ans = Integer.MAX_VALUE;
    static Pair[] pairs;
    static Set<Integer> shelters = new HashSet<>();

    static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void calculate() {
        int maxDist = 0;
        for (int i = 0; i < N; i++) {
            if (shelters.contains(i)) continue;

            int res = Integer.MAX_VALUE;
            Pair pair = pairs[i];
            for (int n : shelters) {
                Pair shelter = pairs[n];
                int dist = Math.abs(shelter.x - pair.x) + Math.abs(shelter.y - pair.y);
                res = Math.min(res, dist);
            }
            maxDist = Math.max(maxDist, res);
        }
        ans = Math.min(ans, maxDist);
    }

    public static void combination(int n, int cnt) {
        if (cnt == K) {
            calculate();
            return;
        }

        for (int i = n; i < N; i++) {
            shelters.add(i);
            combination(i + 1, cnt + 1);
            shelters.remove(i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        pairs = new Pair[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pairs[i] = new Pair(x, y);
        }

        combination(0, 0);
        System.out.println(ans);
    }
}
