import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String num1 = st.nextToken();
        String num2 = st.nextToken();
        StringBuilder sb1 = new StringBuilder(num1);
        StringBuilder sb2 = new StringBuilder(num2);
        sb1.reverse();
        sb2.reverse();

        int sum = Integer.parseInt(sb1.toString()) + Integer.parseInt(sb2.toString());
        StringBuilder ans = new StringBuilder(String.valueOf(sum));
        System.out.println(Integer.parseInt(ans.reverse().toString()));
    }
}
