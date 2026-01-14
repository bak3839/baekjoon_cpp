import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int hs = Integer.parseInt(st.nextToken());
            int ms = Integer.parseInt(st.nextToken());
            int ss = Integer.parseInt(st.nextToken());
            int he = Integer.parseInt(st.nextToken());
            int me = Integer.parseInt(st.nextToken());
            int se = Integer.parseInt(st.nextToken());

            int S = se - ss;
            int M = me - ms;
            int H = he - hs;

            if (S < 0) {
                S += 60;
                M--;
            }

            if (M < 0) {
                M += 60;
                H--;
            }

            System.out.println(H + " " + M + " " + S);
        }
    }
}
