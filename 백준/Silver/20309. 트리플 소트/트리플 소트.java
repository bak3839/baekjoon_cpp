import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        boolean pass = true;
        int N = Integer.parseInt(st.nextToken());
        int[] nums = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i <= N; i++) {
            if(!(i % 2 == 0 && nums[i] % 2 == 0) && !(i % 2 == 1 && nums[i] % 2 == 1)) {
                pass = false;
                break;
            }
        }

        if(pass) System.out.println("YES");
        else System.out.println("NO");
    }
}
