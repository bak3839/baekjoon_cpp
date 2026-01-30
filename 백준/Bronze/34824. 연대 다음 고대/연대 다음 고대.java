import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        boolean end = false;
        String ans = "";
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            if (!end && "yonsei".equals(input)) {
                end = true;
                ans = "Yonsei Won!";
            } else if (!end && "korea".equals(input)) {
                end = true;
                ans = "Yonsei Lost...";
            }
        }

        System.out.println(ans);
    }
}
