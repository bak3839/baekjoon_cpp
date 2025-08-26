import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long B = Long.parseLong(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        HashMap<String, Long> price = new HashMap<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            long p = Long.parseLong(st.nextToken());
            price.put(name, p);
        }

        long total = 0;
        for (int i = 0; i < M; i++) {
            String name = br.readLine();
            total += price.get(name);
        }

        if (total <= B) System.out.println("acceptable");
        else System.out.println("unacceptable");
    }
}
