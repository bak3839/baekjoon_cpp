import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int calculate(StringBuilder sb) {
        int sum = 0;
        int[] base = {1, 2, 4};

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == '1') {
                sum += base[i];
            }
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String num = br.readLine();
        StringBuilder sb = new StringBuilder();
        StringBuilder ans = new StringBuilder();

        for (int i = num.length() - 1; i >= 0; i--) {
            sb.append(num.charAt(i));
            if (sb.length() == 3) {
                int res = calculate(sb);
                ans.append(res);
                sb = new StringBuilder();
            }
        }

        if (sb.length() > 0) {
            ans.append(calculate(sb));
        }

        System.out.println(ans.reverse().toString());
    }
}
