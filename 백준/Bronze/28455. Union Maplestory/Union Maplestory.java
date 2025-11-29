import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] levels = new int[N];

        for (int i = 0; i < N; i++) {
            levels[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(levels);

        int count = 0, sum = 0, point = 0;
        int len = levels.length, end = N > 42 ? N - 42 : 0;

        for (int i = len - 1; i >= end; i--) {

            if (levels[i] >= 250) {
                point += 5;
            } else if (levels[i] >= 200) {
                point += 4;
            } else if (levels[i] >= 140) {
                point += 3;
            } else if (levels[i] >= 100) {
                point += 2;
            } else if (levels[i] >= 60) {
                point += 1;
            }
            sum += levels[i];
        }

        System.out.println(sum + " " + point);
    }
}
