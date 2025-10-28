import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int ans = 0;
        int[] A = new int[N + 1];
        int[] B = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken()) + A[i - 1];
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            B[i] = Integer.parseInt(st.nextToken()) + B[i - 1];
        }

        for (int i = 1; i <= N; i++) {
            if (A[i] == B[i]) ans = i;
        }
        System.out.println(ans);
    }
}
