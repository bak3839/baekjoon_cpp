import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<Long, Long> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            Long X = Long.parseLong(st.nextToken());
            Long T = Long.parseLong(st.nextToken());
            Long C = Long.parseLong(st.nextToken());
            map.compute(T - X, (k, v) -> v == null ? C : v + C);
        }

        map.values().stream()
            .max(Long::compareTo)
            .ifPresent(System.out::println);
    }
}
