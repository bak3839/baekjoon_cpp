import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        int[] points = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            points[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(points);

        double sum = 0.0;
        for (int i = L; i < N - H; i++) {
            sum += points[i];
        }

        System.out.println(sum / (N - L - H));
    }
}
