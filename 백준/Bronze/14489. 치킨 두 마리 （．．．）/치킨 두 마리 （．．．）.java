import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int sum = A + B;

        int C = Integer.parseInt(br.readLine());

        int res = sum - (C * 2);
        if (res >= 0) {
            System.out.println(res);
        } else {
            System.out.println(sum);
        }
    }
}
