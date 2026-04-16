import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        boolean success = true;
        for (int i = 0; i < 8; i++) {
            int n = Integer.parseInt(st.nextToken());
            if (n == 9) success = false;
        }

        if (success) System.out.println("S");
        else System.out.println("F");
    }
}
