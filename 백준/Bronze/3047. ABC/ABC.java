import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] nums = new int[3];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 3; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(nums);

        String input = br.readLine();
        for (char ch : input.toCharArray()) {
            if (ch == 'A') {
                System.out.print(nums[0] + " ");
            } else if (ch == 'B') {
                System.out.print(nums[1] + " ");
            } else {
                System.out.print(nums[2] + " ");
            }
        }
    }
}
