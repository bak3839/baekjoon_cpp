import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringBuilder num1 = new StringBuilder(st.nextToken());
            StringBuilder num2 = new StringBuilder(st.nextToken());
            int len1 = num1.toString().length();
            int len2 = num2.toString().length();
            long result = Long.parseLong(num1.toString()) * Long.parseLong(num2.toString());

            if (len1 < len2) {
                num1.reverse();
                for (int i = 0; i < len2 - len1; i++) {
                    num1.append('1');
                }
                num1.reverse();
            } else if (len2 < len1) {
                num2.reverse();
                for (int i = 0; i < len1 - len2; i++) {
                    num2.append('1');
                }
                num2.reverse();
            }

            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < num1.toString().length(); i++) {
                int n1 = num1.charAt(i) - '0';
                int n2 = num2.charAt(i) - '0';
                ans.append(n1 * n2);
            }

            if (result == Long.parseLong(ans.toString())) {
                System.out.println("1");
            }  else {
                System.out.println("0");
            }
        }
    }
}
