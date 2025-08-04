import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] counts = new int[N + 2];
        counts[1] = 1;

        for (int i = 2; i <= N + 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int a = 0;
            int res = counts[y] - counts[x - 1];

            if (type == 1 && res == y - x + 1) {
                a = 1;
                System.out.println("Yes");
            } else if (type == 2 && res * -1 == y - x + 1) {
                a = 1;
                System.out.println("Yes");
            } else {
                a = -1;
                System.out.println("No");
            }

            counts[i] += counts[i - 1] + a;
        }
    }
}
