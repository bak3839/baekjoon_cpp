import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int maxH = 0;
        long ans = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int h = Integer.parseInt(st.nextToken());
            maxH = Math.max(maxH, h);
            map.compute(h, (k, v) -> v == null ? 1 : v + 1);
        }

        for (int d = 0; d < D; d++) {
            if (maxH == 0) break;

            int count = map.get(maxH--);
            ans += count;
            map.put(maxH, map.getOrDefault(maxH, 0) + count);
        }

        System.out.println(ans);
    }
}
