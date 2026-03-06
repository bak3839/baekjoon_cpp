import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;

        for (int i = 1; i <= N; i++) {
            sum1 = sum1 + i;
        }
        System.out.println(sum1);

        for (int i = 1; i <= N; i++) {
            sum2 = sum2 + i;
        }
        System.out.println(sum2 * sum2);

        for (int i = 1; i <= N; i++) {
            sum3 = (sum3 + (i * i * i));
        }
        System.out.println(sum3);
    }
}