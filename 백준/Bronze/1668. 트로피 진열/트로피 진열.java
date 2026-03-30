import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];

        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        int res = 0, prevMax = -1;
        for (int i = 0; i < N; i++) {
            if (prevMax >= nums[i]) continue;
            res++;
            prevMax = nums[i];
        }
        System.out.println(res);

        res = 0; prevMax = -1;
        for (int i = N - 1; i >= 0; i--) {
            if (prevMax >= nums[i]) continue;
            res++;
            prevMax = nums[i];
        }
        System.out.println(res);
    }
}
