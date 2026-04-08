import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        String input = br.readLine();
        for (int k = 0; k < K; k++) {
            st = new  StringTokenizer(input, ",");
            int[] nums = new int[N - k];
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N - k; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
                if (i > 0) {
                    sb.append(nums[i] - nums[i - 1]);
                    if (i < N - k - 1) sb.append(',');
                }
            }

            input = sb.toString();
        }

        System.out.println(input);
    }
}
