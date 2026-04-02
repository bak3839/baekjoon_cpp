import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String word =  br.readLine();
        int JOI = 0, IOI = 0;

        for (int i = 0; i < word.length() - 2; i++) {
            String sub = word.substring(i, i + 3);
            if ("JOI".equals(sub)) {
                JOI++;
            } else  if ("IOI".equals(sub)) {
                IOI++;
            }
        }
        System.out.println(JOI);
        System.out.println(IOI);
    }
}
