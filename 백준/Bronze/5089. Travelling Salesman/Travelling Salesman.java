import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int week = 1;

        while (true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0) break;

            Set<String> set = new HashSet<>();
            for (int i = 0; i < N; i++) {
                String city = br.readLine();
                set.add(city);
            }

            System.out.println("Week " + week++ + " " + set.size());
        }
    }
}
