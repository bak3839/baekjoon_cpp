import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N, ans;
    static int[] nums;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        nums = new int[N];

        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(nums);

        for (int i = 0; i < N - 2; i++) {
            int X = nums[i];
            boolean pass = true;

            for (int j = i + 1; j < N - 1; j++) {
                int Y = nums[j];

                for (int k = j + 1; k < N; k++) {
                    int Z = nums[k];

                    if (Y - X <= Z - Y && Z - Y <= 2 * (Y - X)) {
                        ans++;
                    } else if (Z - Y > 2 * (Y - X)) {
                        break;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
