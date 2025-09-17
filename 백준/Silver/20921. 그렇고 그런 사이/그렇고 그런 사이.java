import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] A;
    static int N, K;

    public static void swap(int index) {
        int temp = A[index];
        A[index] = A[index - 1];
        A[index - 1] = temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = i + 1;
        }

        int index = N - 1, end = 0;
        for (int i = 0; i < K; i++) {
            swap(index--);
            
            if (index == end) {
                index = N - 1;
                end++;
            }
        }

        Arrays.stream(A).forEach(n -> System.out.print(n + " "));
    }
}
