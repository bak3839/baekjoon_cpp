import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int X = Integer.parseInt(br.readLine());

        int ans = -1;
        for (int y = X + 1; y < 10000; y++) {
            String year = String.valueOf(y);
            int n1 = Integer.parseInt(year.substring(0, 2));
            int n2 = Integer.parseInt(year.substring(2, 4));
            int sum = n1 + n2;

            if (sum * sum == y) {
                ans = y;
                break;
            }
        }

        System.out.println(ans);
    }
}
