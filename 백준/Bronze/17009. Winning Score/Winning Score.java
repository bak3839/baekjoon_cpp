import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int A = 0, B = 0;
        for (int i = 3; i > 0; i--) {
            int n = Integer.parseInt(br.readLine());
            A += (n * i);
        }

        for (int i = 3; i > 0; i--) {
            int n = Integer.parseInt(br.readLine());
            B += (n * i);
        }

        if (A == B) System.out.println("T");
        else if (A > B) System.out.println("A");
        else System.out.println("B");
    }
}
