import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int[] arr = new int[input.length() + 1];

        for(int i = 1; i <= input.length(); i++) {
            int n = input.charAt(i - 1) - '0';
            arr[i] = n + arr[i - 1];
        }

        int ans = 0;
        int len = input.length() / 2;

        while(len > 0) {
            int end = input.length() - (len * 2) + 1;

            for(int i = 1; i <= end; i++) {
                int L = arr[len + i - 1] - arr[i - 1];
                int R = arr[len * 2 + i - 1] - arr[len + i - 1];

                if(L == R){
                    ans = len * 2;
                    break;
                }
            }
            if(ans != 0) break;
            len--;
        }
        System.out.println(ans);
    }
}
