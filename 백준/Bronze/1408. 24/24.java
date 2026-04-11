import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st1 = new StringTokenizer(br.readLine(), ":");
        StringTokenizer st2 = new StringTokenizer(br.readLine(), ":");
        int[] base = {3600, 60, 1};

        int start = 0, end = 0;
        for (int i = 0; i < 3; i++) {
            start += Integer.parseInt(st1.nextToken()) * base[i];
            end += Integer.parseInt(st2.nextToken()) * base[i];
        }

        if (start > end) {
            end += 24 * 3600;
        }

        int total = end - start;
        StringBuilder[] sb = new StringBuilder[3];
        for (int i = 0; i < 3; i++) {
            int res = total / base[i];
            sb[i] = new StringBuilder();

            if (res < 10) {
                sb[i].append(0);
            }
            sb[i].append(res);

            total = total % base[i];
        }

        System.out.println(sb[0] + ":" + sb[1] + ":" + sb[2]);
    }
}
