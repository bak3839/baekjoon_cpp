import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void init(String input, int N, int[] arr) {
        StringTokenizer st = new StringTokenizer(input);
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] A = new int[N];
        int[] B = new int[M];

        init(br.readLine(), N, A);
        init(br.readLine(), M, B);

        int ansA = 0, ansB = 0;
        int nextTimeA = 0, nextTimeB = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] < nextTimeA) continue;

            ansA++;
            nextTimeA = A[i] + 100;
        }

        for (int i = 0; i < M; i++) {
            if (B[i] < nextTimeB) continue;

            ansB++;
            nextTimeB = B[i] + 360;
        }
        System.out.println(ansA + " " + ansB);
    }
}
