import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            List<Long> result = new ArrayList<>();
            HashMap<Long, Integer> map = new HashMap<>();
            long[] P = new long[N * 2];

            for (int i = 0; i < N * 2; i++) {
                P[i] = Long.parseLong(st.nextToken());
                map.put(P[i], map.getOrDefault(P[i], 0) + 1);
            }

            for (int i = 0; i < N * 2; i++) {
                if (map.get(P[i]) == null || map.get(P[i]) <= 0) continue;
                long target = P[i] * 4 / 3;

                if (map.get(target) != null && map.get(target) > 0) {
                    result.add(P[i]);
                    map.put(P[i], map.get(P[i]) - 1);
                    map.put(target, map.get(target) - 1);
                }
            }

            result.sort(Comparator.naturalOrder());
            System.out.print("Case #" + t + ": ");
            result.forEach(n -> System.out.print(n + " "));
            System.out.println();
        }
    }
}
