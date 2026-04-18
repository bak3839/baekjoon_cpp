import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.ForkJoinPool;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String input = br.readLine();
        String[] nums = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

        List<Integer> result = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if (input.contains(nums[i])) {
                result.add(i);
            }
        }

        result.sort(Comparator.naturalOrder());
        result.forEach(n -> System.out.print(n + " "));
    }
}
