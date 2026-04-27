import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int hp = 0, ans = 0;
        for (int i = 0; i < 24; i++) {
            if (hp + A <= M) {
                ans += B;
                hp += A;
            } else {
                hp = Math.max(hp - C, 0);
            }
        }
        System.out.println(ans);
    }
}
