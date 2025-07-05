import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static boolean check(String roomNumber) {
        boolean[] used = new boolean[10];

        for (char ch : roomNumber.toCharArray()) {
            int index = ch - '0';

            if (used[index]) return false;
            used[index] = true;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;

        while ((input = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(input);
            
            int ans = 0;
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            for (int i = start; i <= end; i++) {
                if(check(String.valueOf(i))) ans++;
            }

            System.out.println(ans);
        }
    }
}
