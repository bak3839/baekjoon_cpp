import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] H = new int[N];
        int ans = Integer.MAX_VALUE;
        int startH = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            H[i] = Integer.parseInt(br.readLine());
            startH = Math.min(startH, H[i]);
        }

        for (int minH = startH; minH <= 100; minH++) {
            int sum = 0;
            int maxH = minH + 17;

            for (int height : H) {
                if (height > maxH) sum += (height - maxH) * (height - maxH);
                else if (height < minH) sum += (minH - height) * (minH - height);
            }
            ans = Math.min(ans, sum);
        }
        System.out.println(ans);
    }
}
