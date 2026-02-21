import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        boolean[] row = new boolean[N];
        boolean[] col = new boolean[M];

        for (int i = 0; i < N; i++) {
            String input = br.readLine();

            for (int j = 0; j < M; j++) {
                char ch = input.charAt(j);
                if (ch == 'X') {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        int count1 = 0, count2 = 0;
        for (boolean r : row) {
            if (!r) count1++;
        }
        for (boolean c : col) {
            if (!c) count2++;
        }

        System.out.println(Math.max(count1, count2));
    }
}
