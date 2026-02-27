import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean asc = true;
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        long prev = Long.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            long cur = Long.parseLong(st.nextToken());
            if (cur <= prev) {
                asc = false;
            }
            prev = cur;
        }

        System.out.println(asc ? "1" : "0");
    }
}
