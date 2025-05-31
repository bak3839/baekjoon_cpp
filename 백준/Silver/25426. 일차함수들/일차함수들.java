import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pair {
        int a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static int N;
    static List<Pair> pairs = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        int a, b;
        long ans = 0;

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            pairs.add(new Pair(a, b));
        }

        pairs.sort((p1, p2) -> (p1.a == p2.a) ? (p2.b - p1.b) : p2.a - p1.a);

        for (Pair pair : pairs) {
            ans += ((long) pair.a * N) + pair.b;
            N--;
        }

        System.out.println(ans);
    }
}
