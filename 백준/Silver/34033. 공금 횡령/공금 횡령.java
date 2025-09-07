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
        int M = Integer.parseInt(st.nextToken());
        int ans = 0;
        HashMap<String, Double> prices = new HashMap<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            Double price = Double.parseDouble(st.nextToken());
            prices.put(name, price * 1.05);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            Double price = Double.parseDouble(st.nextToken());

            if (price > prices.get(name)) ans++;
        }

        System.out.println(ans);
    }
}
