import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int A, T, C;
    static int[] counts = new int[2];

    public static boolean search(int type) {
        counts[type]++;
        return counts[C] == T;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        A = Integer.parseInt(br.readLine());
        T = Integer.parseInt(br.readLine());
        C = Integer.parseInt(br.readLine());

        int now = 0, step = 2;

        while (true) {
            boolean pass = true;

            for(int i = 0; i < 2; i++) {
                if(!search(0)) {
                    now = (now + 1) % A;
                } else {
                    pass = false;
                    break;
                }

                if(!search(1)) {
                    now = (now + 1) % A;
                } else {
                    pass = false;
                    break;
                }
            }

            if(!pass) break;

            for (int i = 0; i < step; i++) {
                if(!search(0)) {
                    now = (now + 1) % A;
                } else {
                    pass = false;
                    break;
                }
            }

            if(!pass) break;

            for (int i = 0; i < step; i++) {
                if(!search(1)) {
                    now = (now + 1) % A;
                } else {
                    pass = false;
                    break;
                }
            }

            if(!pass) break;

            step++;
        }

        System.out.println(now);
    }
}
