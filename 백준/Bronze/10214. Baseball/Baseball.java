import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            long y = 0, k = 0;
            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                y += Integer.parseInt(st.nextToken());
                k += Integer.parseInt(st.nextToken());
            }

            if (y == k) {
                System.out.println("Draw");
            } else if (y > k) {
                System.out.println("Yonsei");
            } else {
                System.out.println("Korea");
            }
        }
    }
}
