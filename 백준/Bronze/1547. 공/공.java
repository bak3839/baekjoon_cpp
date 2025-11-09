import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int ball = 1;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n1 =  Integer.parseInt(st.nextToken());
            int n2 =  Integer.parseInt(st.nextToken());

            if (n1 == ball) {
                ball = n2;
            } else if (n2 == ball) {
                ball = n1;
            }
        }
        System.out.println(ball);
    }
}
