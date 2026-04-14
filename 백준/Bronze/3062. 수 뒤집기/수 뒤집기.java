import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            String num = br.readLine();
            StringBuilder reverse = new StringBuilder();
            for (int i = num.length() - 1; i >= 0; i--) {
                reverse.append(num.charAt(i));
            }

            int sum = Integer.parseInt(reverse.toString()) + Integer.parseInt(num);
            if (isPalindrome(String.valueOf(sum))) {
                System.out.println("YES");
            }  else {
                System.out.println("NO");
            }
        }
    }

    private static boolean isPalindrome(String num) {
        for (int i = 0; i < num.length() / 2; i++) {
            if (num.charAt(i) != num.charAt(num.length() - 1 - i)) return false;
        }
        return true;
    }
}
