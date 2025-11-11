import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String input = br.readLine();
        Set<String> set = new HashSet<>();

        int x = 0, y = 0;
        set.add("0 0");
        for (int i = 0; i < N; i++) {
            char ch = input.charAt(i);

            if (ch == 'N') {
                y += 1;
            } else if (ch == 'S') {
                y -= 1;
            } else if (ch == 'W') {
                x -= 1;
            } else if (ch == 'E') {
                x += 1;
            }

            String res = x + " " + y;
            set.add(res);
        }

        System.out.println(set.size());
    }
}
