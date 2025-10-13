import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int step = 0;
            String number = br.readLine();
            number = String.format("%04d", Integer.parseInt(number));

            while (!number.equals("6174")) {
                char[] nums = number.toCharArray();
                Arrays.sort(nums);

                StringBuilder sb = new StringBuilder();
                for (char n : nums) {
                    sb.append(n);
                }

                int min = Integer.parseInt(sb.toString());
                int max = Integer.parseInt(sb.reverse().toString());

                int result = max - min;
                number = String.format("%04d", result);
                step++;
            }
            System.out.println(step);
        }
    }
}
