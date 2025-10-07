import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int sum = 0;
        int[] A = new int[N];
        int[] count = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(br.readLine());
            sum += A[i];
        }

        int total = sum / 2;
        for (int i = 0; i < total; i++) {
            int res = i, prev = i;
            count[0] = i;
            for (int j = 0; j < N - 1; j++) {
                count[j + 1] = A[j] - prev;
                prev = count[j + 1];
                res += count[j + 1];
            }
            if (res == total) break;
        }
        Arrays.stream(count).forEach(System.out::println);
    }
}
