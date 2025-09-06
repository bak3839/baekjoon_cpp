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
            HashMap<String, Integer> map = new HashMap<>();
            String ans = "";

            for (int i = 0; i < 16; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String team1 = st.nextToken();
                String team2 = st.nextToken();
                int score1 = Integer.parseInt(st.nextToken());
                int score2 = Integer.parseInt(st.nextToken());
                int value = 0;

                if (score1 > score2) {
                    value = map.compute(team1, (k, v) -> v == null ? 1 : v + 1);
                    if (value == 4) ans = team1;
                } else {
                    value = map.compute(team2, (k, v) -> v == null ? 1 : v + 1);
                    if (value == 4) ans = team2;
                }
            }

            System.out.println(ans);
        }
    }
}
