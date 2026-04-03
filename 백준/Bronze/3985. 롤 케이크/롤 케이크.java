import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int L = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        int maxWantedNum = 0, maxNum = 0, maxWantedCount = 0, maxCount = 0;
        int[] nums = new int[L + 1];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int wantedCount = end - start + 1;

            if (wantedCount > maxWantedCount) {
                maxWantedNum = i + 1;
                maxWantedCount = wantedCount;
            }

            int count = 0;
            for (int index = start; index <= end; index++) {
                if (nums[index] != 0) continue;

                nums[index] = i + 1;
                count++;
            }

            if (count > maxCount) {
                maxNum = i + 1;
                maxCount = count;
            }
        }

        System.out.println(maxWantedNum);
        System.out.println(maxNum);
    }
}
