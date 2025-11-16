import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();

        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            String sub = word.substring(i);
            int start = 0, end = sub.length() - 1;
            while (start < end) {
                if (sub.charAt(start) != sub.charAt(end)) break;
                start++;
                end--;
            }
            if (start >= end) break;
            count++;
        }
        System.out.println(count + word.length());
    }
}
