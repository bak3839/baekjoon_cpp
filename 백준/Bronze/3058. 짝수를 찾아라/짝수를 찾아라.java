import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int sum = 0, min = Integer.MAX_VALUE;
            for (int i = 0; i < 7; i++) {
                int n = Integer.parseInt(st.nextToken());
                if (n % 2 == 0) {
                    sum += n;
                    min = Math.min(min, n);
                }
            }
            System.out.println(sum + " " + min);
        }
    }
}
