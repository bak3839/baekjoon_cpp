import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int hp = 0, mp = 0, a = 0, d = 0;

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 2; i++) {
                hp +=  Integer.parseInt(st.nextToken());
                mp +=  Integer.parseInt(st.nextToken());
                a += Integer.parseInt(st.nextToken());
                d += Integer.parseInt(st.nextToken());
            }

            hp = Math.max(hp, 1);
            mp = Math.max(mp, 1);
            a = Math.max(a, 0);

            System.out.println(hp + (5 * mp) + (2 * a) + (2 * d));
        }
    }
}
