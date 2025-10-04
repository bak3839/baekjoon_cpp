import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int A, B, ans;

    public static void search(String str) {
        if (str.length() > 9) return;

        int number = Integer.parseInt(str);

        if (number > B) return;
        if (A <= number) ans++;

        search(str + "4");
        search(str + "7");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        search("4");
        search("7");
        System.out.println(ans);
    }
}
