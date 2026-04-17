import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int ans = 0;
        while (N > 9) {
            int tmp = 1;
            String num = String.valueOf(N);

            for (int i = 0; i < num.length(); i++) {
                int n = num.charAt(i) - '0';
                tmp *= n;
            }

            N = tmp;
            ans++;
        }

        System.out.println(ans);
    }
}
