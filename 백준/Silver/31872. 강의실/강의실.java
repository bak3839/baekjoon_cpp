import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, K;
    static long sum;
    static int[] A;
    static List<Integer> time = new ArrayList<>();

    public static void move() {
        sum = A[0];
        time.add(A[0]);
        for(int i = 1; i < N; i++) {
            sum += A[i] - A[i - 1];
            time.add(A[i] - A[i - 1]);
        }
        time.sort(Comparator.reverseOrder());

        for(int i = 0; i < K; i++) {
            sum -= time.get(i);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        A = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(A);

        move();

        System.out.println(sum);
    }
}
