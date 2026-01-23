import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String word = br.readLine();
        Set<Character> set = Set.of('C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E');

        for (char c : word.toCharArray()) {
            if (set.contains(c)) continue;
            System.out.print(c);
        }
    }
}
