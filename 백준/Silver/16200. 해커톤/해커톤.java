import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, ans = 0;
    static int[] X;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        X = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(X);

        int count = 1, prev = X[0];

        for(int i = 1; i < N; i++) {
            if(count < prev) {
                count++;
            } else {
                ans++;
                count = 1;
                prev = X[i];
            }
        }

        System.out.println(ans + 1);
    }
}
