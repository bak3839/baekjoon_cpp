import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N];
            HashSet<Integer> mod = new HashSet<>();

            for (int i = 0; i < N; i++) {
                nums[i] = Integer.parseInt(br.readLine());
            }

            int n = 1;

            while (true) {
                mod.clear();

                for (int i = 0; i < N; i++) {
                    int m = nums[i] % n;

                    if (mod.contains(m)) break;

                    mod.add(m);
                }

                if (mod.size() == N) {
                    System.out.println(n);
                    break;
                }

                n++;
            }
        }
    }
}
