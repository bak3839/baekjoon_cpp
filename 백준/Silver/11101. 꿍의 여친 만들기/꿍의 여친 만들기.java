import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), ",");
            HashMap<String, Integer> map = new HashMap<>();
            int ans = Integer.MAX_VALUE;

            while (st.hasMoreTokens()) {
                String[] split = st.nextToken().split(":");
                map.put(split[0], Integer.parseInt(split[1]));
            }

            st = new StringTokenizer(br.readLine(), "|");

            while (st.hasMoreTokens()) {
                int res = 0;
                for (String s : st.nextToken().split("&")) {
                    res = Math.max(res, map.get(s));
                }
                ans = Math.min(ans, res);
            }
            System.out.println(ans);
        }
    }
}
