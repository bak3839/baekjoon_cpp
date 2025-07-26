import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long ansNum = 0, ansSum = Long.MAX_VALUE;
        int N = Integer.parseInt(br.readLine());
        int[] dist = new int[N + 1];
        long[] L = new long[N]; long[] R = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            dist[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N - 1; i++) {
            L[i] = L[i - 1] + Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N - 1; i++) {
            R[i] = R[i - 1] + Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i <= N; i++) {
            long left = L[i - 1];
            long right = R[N - 1] - R[i - 1];

            if(left + right + dist[i] < ansSum) {
                ansSum = left + right + dist[i];
                ansNum = i;
            }
        }

        System.out.println(ansNum + " " + ansSum);
    }
}
