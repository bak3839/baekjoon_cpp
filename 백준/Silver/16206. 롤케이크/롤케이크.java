import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long ans = 0;
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Integer> A = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(st.nextToken());
            if (a == 10) ans++;
            else A.add(a);
        }

        A.sort(
            Comparator.comparingInt((Integer a) -> a % 10)
                .thenComparing(a -> a)
        );
        for (int a : A) {
            if (M == 0) break;
            while (a > 10 && M > 0) {
                M--;
                a -= 10;
                ans++;
            }
            if (a == 10) ans++;
        }

        System.out.println(ans);
    }
}
