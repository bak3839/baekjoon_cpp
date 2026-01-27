import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] num = new int[21];

        for (int i = 1; i <= 20; i++) {
            num[i] = i;
        }

        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < 10; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            for (int j = start; j <= end; j++) {
                stack.push(num[j]);
            }
            for (int j = start; j <= end; j++) {
                num[j] = stack.pop();
            }
        }

        for (int i = 1; i <= 20; i++) {
            System.out.print(num[i] + " ");
        }
    }
}
