import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[] nums, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        nums = new int[N + 1];
        ans = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        ans[N] = -1;

        for(int i = N - 1; i >= 1; i--) {
            if(nums[i] == nums[i + 1]) ans[i] = ans[i + 1];
            else ans[i] = i + 1;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            sb.append(ans[i]).append(" ");
        }
        System.out.println(sb);
    }
}
