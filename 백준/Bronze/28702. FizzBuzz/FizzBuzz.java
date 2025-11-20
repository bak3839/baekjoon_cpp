import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static boolean isNumber(String input) {
        return !input.equals("Fizz") && !input.equals("Buzz") && !input.equals("FizzBuzz");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int index = 0;
        String num = "";
        for (int i = 0; i < 3; i++) {
            String input = br.readLine();
            if (isNumber(input)) {
                index = i;
                num = input;
            }
        }

        int ans = Integer.parseInt(num) + (3 - index);

        if (ans % 3 == 0 &&  ans % 5 == 0) {
            System.out.println("FizzBuzz");
        } else if (ans % 3 == 0) {
            System.out.println("Fizz");
        }  else if (ans % 5 == 0) {
            System.out.println("Buzz");
        }  else {
            System.out.println(ans);
        }
    }
}
