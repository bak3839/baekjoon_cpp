import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int total = 0;
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[] A = new int[N];
        int[] result = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            int sum = A[i];
            sum *= A[(i + 1) % N];
            sum *= A[(i + 2) % N];
            sum *= A[(i + 3) % N];
            result[i] = sum;
            total += sum;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < Q; i++) {
            int q = Integer.parseInt(st.nextToken()) - 1;

            for(int j = 0; j < 4; j++) {
                int idx = (q - j) < 0 ? N + (q - j) : q - j;
                total -= result[idx];
                total += (result[idx] * -1);
                result[idx] *= -1;
            }
            System.out.println(total);
        }
    }
}
