import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        Map<String, String> map = Map.of(
            "R", "S",
            "S", "P",
            "P", "R"
        );

        for (int t = 0; t < T; t++) {
            int p1 = 0, p2 = 0;
            int N = Integer.parseInt(br.readLine());

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String s1 = st.nextToken();
                String s2 = st.nextToken();

                if (map.get(s1).equals(s2)) {
                    p1++;
                } else if (map.get(s2).equals(s1)) {
                    p2++;
                }
            }

            if (p1 > p2) System.out.println("Player 1");
            else if (p2 > p1) System.out.println("Player 2");
            else System.out.println("TIE");
        }
    }
}
