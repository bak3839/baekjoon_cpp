import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        double[] prices = new double[N];

        for (int i = 0; i < N; i++) {
            prices[i] = Double.parseDouble(br.readLine());
        }
        Arrays.sort(prices);

        System.out.printf("%.2f", prices[1]);
    }
}
