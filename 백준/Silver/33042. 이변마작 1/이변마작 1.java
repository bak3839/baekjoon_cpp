import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String[] S = new String[N];
        HashMap<String, Integer> map = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            S[i] = st.nextToken();
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int res = map.getOrDefault(S[i], 0) + 1;

            if (res >= 5) {
                ans = i + 1;
                break;
            }

            map.put(S[i], res);
        }

        System.out.println(ans);
    }
}
