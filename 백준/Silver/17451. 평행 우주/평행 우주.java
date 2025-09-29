import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long[] v = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            v[i] = Long.parseLong(st.nextToken());
        }

        long speed = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (speed < v[i]) {
                speed = v[i];
            } else if (speed > v[i]) {
                speed = ((speed + v[i] - 1) / v[i]) * v[i];
            }
        }

        System.out.println(speed);
    }
}
