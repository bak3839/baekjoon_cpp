import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stA = new StringTokenizer(br.readLine());
        StringTokenizer stB = new StringTokenizer(br.readLine());

        int A = 0, B = 0;

        for (int i = 0; i < 10; i++) {
            int a = Integer.parseInt(stA.nextToken());
            int b = Integer.parseInt(stB.nextToken());

            if (a > b) A++;
            if (b > a) B++;
        }

        if (A > B) System.out.println("A");
        else if (B > A) System.out.println("B");
        else System.out.println("D");
    }
}
