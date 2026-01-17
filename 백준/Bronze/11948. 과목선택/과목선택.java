import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int min = Integer.MAX_VALUE, sum = 0;
        for (int i = 0; i < 4; i++) {
            int point = Integer.parseInt(br.readLine());
            min = Math.min(min, point);
            sum += point;
        }

        int p1 = Integer.parseInt(br.readLine());
        int p2 = Integer.parseInt(br.readLine());

        System.out.println(sum - min + Math.max(p1, p2));
    }
}
