import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            int G = Integer.parseInt(br.readLine());
            HashSet<Integer> set = new HashSet<>();

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < G; i++) {
                int C = Integer.parseInt(st.nextToken());
                if (set.contains(C)) set.remove(C);
                else set.add(C);
            }

            for (int c : set) System.out.println("Case #" + (t + 1) + ": " + c);
        }
    }
}
