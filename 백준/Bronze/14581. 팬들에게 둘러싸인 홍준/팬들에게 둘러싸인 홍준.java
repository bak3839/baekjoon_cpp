import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        String s1 = ":fan::fan::fan:";
        String s2 = ":fan::" +  input + "::fan:";
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s1);
    }
}
