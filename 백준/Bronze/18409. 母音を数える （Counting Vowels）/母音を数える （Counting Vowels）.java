import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String word = br.readLine();
        Set<Character> set = Set.of('a', 'e', 'i', 'o', 'u');
        
        int ans = 0;
        for (char ch :  word.toCharArray()) {
            if (set.contains(ch)) ans++;
        }

        System.out.println(ans);
    }
}
