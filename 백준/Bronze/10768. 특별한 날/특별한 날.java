import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int M = Integer.parseInt(br.readLine());
        int D = Integer.parseInt(br.readLine());

        int A = M - 2, B = D - 18;

        if (A == 0 && B == 0) {
            System.out.println("Special");
        } else if ((A == 0 && B > 0) || A > 0) {
            System.out.println("After");
        } else {
            System.out.println("Before");
        }
    }
}
