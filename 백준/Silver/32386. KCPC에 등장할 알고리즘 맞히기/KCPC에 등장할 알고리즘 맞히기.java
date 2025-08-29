import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int maxValue = 0;
        String maxTag = "";
        boolean duplicate = false;
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int T = Integer.parseInt(st.nextToken());

            for (int t = 0; t < T; t++) {
                String tag = st.nextToken();
                int count = map.compute(tag, (k, v) -> v == null ? 1 : v + 1);

                if (count > maxValue) {
                    duplicate = false;
                    maxValue = count;
                    maxTag = tag;
                } else if (count == maxValue) {
                    duplicate = true;
                }
            }
        }

        if (duplicate) System.out.println(-1);
        else System.out.println(maxTag);
    }
}
