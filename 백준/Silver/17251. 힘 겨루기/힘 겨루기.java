import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int minIdx = 0, maxIdx = 0, maxStr = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int s = Integer.parseInt(st.nextToken());

            if (s > maxStr) {
                maxStr = s;
                minIdx = i;
                maxIdx = i;
            } else if (s == maxStr) {
                maxIdx = i;
            }
        }

        int B = minIdx;
        int R = (N - 1) - maxIdx;

        if (B > R) System.out.println("B");
        else if (R > B) System.out.println("R");
        else System.out.println("X");
    }
}
