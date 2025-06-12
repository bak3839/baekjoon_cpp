import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long ans;
    static int N, K;
    static Long[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        A = new Long[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
            if(i != 0) A[i] += A[i - 1];
        }

        Arrays.sort(A, Collections.reverseOrder());

        for(int i = 0; i < K; i++) {
            ans += A[i];
        }

        System.out.println(ans);
    }
}
