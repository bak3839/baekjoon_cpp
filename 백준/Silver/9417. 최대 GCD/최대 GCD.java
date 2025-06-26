import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;

    public static int gcd(int a, int b) {
        int tmp;

        while (b != 0) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        while (N-- > 0) {
            int ans = 0;
            List<Integer> list = new ArrayList<>();
            st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()) {
                list.add(Integer.parseInt(st.nextToken()));
            }
            list.sort(Integer::compareTo);

            for (int i = 0; i < list.size(); i++) {
                int b = list.get(i);
                for (int j = i + 1; j < list.size(); j++) {
                    int a = list.get(j);
                    ans = Math.max(ans, gcd(b, a));
                }
            }

            System.out.println(ans);
        }
    }
}
