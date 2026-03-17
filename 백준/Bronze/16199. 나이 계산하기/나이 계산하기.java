import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] nums = new int[2][3];

        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            nums[i][0] = Integer.parseInt(st.nextToken());
            nums[i][1] = Integer.parseInt(st.nextToken());
            nums[i][2] = Integer.parseInt(st.nextToken());
        }

        int a = nums[1][0] - nums[0][0];
        int b = 0;
        if (nums[1][1] > nums[0][1] || (nums[1][1] == nums[0][1] && nums[1][2] >= nums[0][2])) {
            b++;
        }

        System.out.println(a + b - 1);
        System.out.println(a + 1);
        System.out.println(a);
    }
}
