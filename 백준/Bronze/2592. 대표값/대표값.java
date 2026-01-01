import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] counts = new int[1001];

        int sum = 0, count = 0, num = 0;
        for (int i = 0; i < 10; i++) {
            int n = Integer.parseInt(br.readLine());
            sum += n;
            counts[n]++;
            if (count < counts[n]) {
                count = counts[n];
                num = n;
            }
        }

        System.out.println(sum / 10);
        System.out.println(num);
    }
}
