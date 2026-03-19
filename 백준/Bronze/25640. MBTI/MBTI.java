import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String mbti = br.readLine();
        int N = Integer.parseInt(br.readLine());
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            String input = br.readLine();
            if (input.equals(mbti)) {
                ans++;
            }
        }
        
        System.out.println(ans);
    }
}
