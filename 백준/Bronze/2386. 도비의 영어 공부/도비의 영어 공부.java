import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char ch = st.nextToken().charAt(0);

            if (ch == '#') break;

            int count = 0;
            while (st.hasMoreTokens()) {
                String word = st.nextToken().toLowerCase();
                for (char c : word.toCharArray()) {
                    if (c == ch) count++;
                }
            }
            System.out.println(ch + " " + count);
        }
    }
}
