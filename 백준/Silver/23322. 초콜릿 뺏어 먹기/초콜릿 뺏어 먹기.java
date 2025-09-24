import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int ans = 0, day = 0;
        int[] A = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int index = 0;
        while (index < N - K) {
            if (A[index] == A[index + K]) {
                index++;
                continue;
            }

            day++;
            ans += A[index + K] - A[index];
            A[index + K] = A[index];
            Arrays.sort(A);
        }

        System.out.println(ans + " " + day);
    }
}
