import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String num = br.readLine();
            if (num.equals("0")) break;

            int sum = 0;

            for (char ch : num.toCharArray()) {
                if (ch == '1') sum += 2;
                else if (ch == '0') sum += 4;
                else sum += 3;
            }
            System.out.println(sum + num.length() + 1);
        }
    }
}
