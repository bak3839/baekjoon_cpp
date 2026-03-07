import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int R = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        String s = "*";

        for (int i = 0; i < R; i++) {
            System.out.println(s.repeat(C));
        }
    }
}
