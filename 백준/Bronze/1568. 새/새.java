import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int count = 1, ans = 0;
        while (N > 0) {
            if (count <= N) {
                N -= count;
                count++;
                ans++;
            } else {
                count = 1;
            }
        }

        System.out.println(ans);
    }
}
