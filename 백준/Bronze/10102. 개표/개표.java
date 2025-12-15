import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int A = 0, B = 0;
        int N = Integer.parseInt(br.readLine());
        String s = br.readLine();

        for (int i = 0; i < N; i++) {
            char ch = s.charAt(i);
            int res = ch == 'A' ? A++ : B++;
        }

        if (A == B) {
            System.out.println("Tie");
        } else {
            System.out.println(A > B ? "A" : "B");
        }
    }
}
