import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long ans = Long.MAX_VALUE;
        long sumA = 0, sumB = 0;
        long[] A = new long[N + 1];
        long[] B = new long[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            sumA += A[i];
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            B[i] = Integer.parseInt(st.nextToken());
            sumB += B[i];
        }

        int i = N, j = N;
        while (K-- > 0 && (i > 0 || j > 0)) {
            long remainA = sumA;
            long remainB = sumB;

            if (i == 0) {
                sumB -= B[j--];
            } else if (j == 0) {
                sumA -= A[i--];
            } else {
                if (remainA > remainB) {
                    sumA -= A[i--];
                } else {
                    sumB -= B[j--];
                }
            }
        }

        long result = Math.min(sumA, sumB);
        long answer = Math.max(sumA, sumB);

        System.out.println(answer);
    }
}
