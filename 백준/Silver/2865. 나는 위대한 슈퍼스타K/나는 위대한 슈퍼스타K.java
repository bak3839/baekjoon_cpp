import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        HashMap<Integer, Double> map = new HashMap<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < N; j++) {
                int n = Integer.parseInt(st.nextToken());
                double s = Double.parseDouble(st.nextToken());
                map.compute(n, (k, v) -> v == null ? s : Math.max(s, v));
            }
        }

        map.values().stream()
            .sorted((a, b) -> Double.compare(b, a))
            .limit(K)
            .reduce(Double::sum)
            .ifPresent(sum -> System.out.println(Math.round(sum * 10.0) / 10.0));
    }
}
