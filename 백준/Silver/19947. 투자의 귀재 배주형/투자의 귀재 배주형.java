import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int H, Y, ans;
    static int[] year = {1, 3, 5};
    static double[] rate = {1.05, 1.2, 1.35};

    public static void search(int sum, int y) {
        if(y <= 0) {
            ans = Math.max(ans, sum);
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(y >= year[i]) {
                int res = (int) (sum * rate[i]);
                search(res, y - year[i]);
            } else {
                search(sum, y - year[i]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        search(H, Y);
        System.out.println(ans);
    }
}
