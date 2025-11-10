import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N  = Integer.parseInt(st.nextToken());
        int M  = Integer.parseInt(st.nextToken());
        Map<String, String> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            String song = st.nextToken();
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < 7; j++) {
                String s = st.nextToken();
                if (j >= 3) continue;
                sb.append(s);
            }

            map.compute(sb.toString(), (key, value) -> value == null ? song : "?" );
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < 3; j++) {
                sb.append(st.nextToken());
            }
            String key = sb.toString();

            System.out.println(map.getOrDefault(key, "!"));
        }
    }
}
