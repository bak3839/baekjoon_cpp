import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int F = Integer.parseInt(st.nextToken()) / 2;
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        while (K > 0 && M > 0 && F > 0) {
            if (F >= M) {
                F--;
                K -= 2;
            } else {
                M--;
                K -= 1;
            }
        }

        System.out.println(Math.min(M, F));
    }
}
