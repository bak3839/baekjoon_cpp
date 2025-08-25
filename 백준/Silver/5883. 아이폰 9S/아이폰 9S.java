import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ans = 0;
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(br.readLine());
            set.add(A[i]);
        }

        for (int num : set) {
            int prev = -1;
            int count = 0;

            for (int i = 0; i < N; i++) {
                if (A[i] == num) continue;

                if (A[i] == prev) {
                    count++;
                }
                else {
                    prev = A[i];
                    count = 1;
                }

                ans = Math.max(ans, count);
            }
        }

        System.out.println(ans);
    }
}
