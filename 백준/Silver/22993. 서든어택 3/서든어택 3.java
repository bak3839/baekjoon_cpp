import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        long attack = Long.parseLong(st.nextToken());
        long[] A = new long[N - 1];
        boolean die = false;

        for (int i = 0; i < N - 1; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(A);

        for (int i = 0; i < N - 1; i++) {
            if (attack <= A[i]) {
                die = true;
                break;
            }

            attack += A[i];
        }

        if (die) System.out.println("No");
        else System.out.println("Yes");
    }
}
