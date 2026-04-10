import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int L = 0, R = 0, ans = 0;
        for (int i = 1; i < N; i++) {
            if (nums[i - 1] < nums[i]) {
                ans = Math.max(ans, nums[i] - nums[L]);
            } else {
                L = i;
            }
        }

        System.out.println(ans);
    }
}
