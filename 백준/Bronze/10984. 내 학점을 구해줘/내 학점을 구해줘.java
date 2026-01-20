import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());

            double count = 0, sum = 0.0;
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                double n = Double.parseDouble(st.nextToken());
                double point = Double.parseDouble(st.nextToken());
                count += n;
                sum += point * n;
            }
            System.out.print((int) count + " ");
            System.out.printf("%.1f\n", sum / count);
        }
    }
}
