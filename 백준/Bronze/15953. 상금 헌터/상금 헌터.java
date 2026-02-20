import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int getPrice1(int n) {
        if (n == 1) return 5000000;
        else if (2 <= n && n <= 3) return 3000000;
        else if (4 <= n && n <= 6) return 2000000;
        else if (7 <= n && n <= 10) return 500000;
        else if (11 <= n && n <= 15) return 300000;
        else if (16 <= n && n <= 21) return 100000;
        return 0;
    }

    static int getPrice2(int n) {
        if (n == 1) return 5120000;
        else if (2 <= n && n <= 3) return 2560000;
        else if (4 <= n && n <= 7) return 1280000;
        else if (8 <= n && n <= 15) return 640000;
        else if (16 <= n && n <= 31) return 320000;
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            System.out.println(getPrice1(a) + getPrice2(b));
        }
    }
}
