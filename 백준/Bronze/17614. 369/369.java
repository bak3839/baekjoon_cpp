import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int count = 0;

        for (int i = 0; i < N + 1; i++) {
            int temp = i;
            while (temp != 0) {
                if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) {
                    count = count + 1;
                }
                temp = temp / 10;
            }
        }
        
        System.out.println(count);
    }
}