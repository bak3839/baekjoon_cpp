import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, F;
    static boolean finished = false;
    static boolean[] used;
    static List<Integer> nums = new ArrayList<>();

    public static void calculate() {
        int[] arr = new int[N];
        for(int i = 0; i < N; i++) {
            arr[i] = nums.get(i);
        }

        for(int n = 0; n < N - 1; n++) {
            for(int i = 1; i < N - n; i++) {
                arr[i - 1] = arr[i] + arr[i - 1];
            }
        }

        if(arr[0] == F) {
            finished = true;
            nums.forEach(n -> System.out.print(n + " "));
        }
    }

    public static void combination() {
        if (nums.size() == N) {
            calculate();
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (used[i]) continue;

            used[i] = true;
            nums.add(i);

            combination();

            used[i] = false;
            nums.remove(nums.size() - 1);

            if (finished) return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());

        used = new boolean[N + 1];

        combination();
    }
}
