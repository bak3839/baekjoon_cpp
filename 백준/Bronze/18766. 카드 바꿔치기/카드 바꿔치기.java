import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            String[] cards1 = br.readLine().split(" ");
            String[] cards2 = br.readLine().split(" ");
            Arrays.sort(cards1);
            Arrays.sort(cards2);

            boolean pass = true;
            for (int i = 0; i < N; i++) {
                if (cards1[i].equals(cards2[i])) continue;

                pass = false;
                break;
            }

            System.out.println(pass ? "NOT CHEATER" : "CHEATER");
        }
    }
}
