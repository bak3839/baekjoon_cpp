import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static int calculate(String name, int[] counts) {
        int sum = 1;
        int length = name.length();
        int[] base = {'L' - 'A', 'O' - 'A', 'V' - 'A', 'E' - 'A'};

        for (char ch : name.toCharArray()) {
            counts[ch - 'A']++;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                int res = counts[base[i]] + counts[base[j]];
                sum = sum * res;
            }
        }

        return sum % 100;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        int N = Integer.parseInt(br.readLine());

        int count = -1;
        String ans = "";
        int[] counts = new int[26];
        String[] names = new String[N];

        for (int i = 0; i < N; i++) {
            names[i] = br.readLine();
        }
        Arrays.sort(names);

        for (String name : names) {
            for (char ch : name.toCharArray()) {
                counts[ch - 'A']++;
            }

            int res = calculate(input, counts);

            if (count < res) {
                count = res;
                ans = name;
            }
            Arrays.fill(counts, 0);
        }
        System.out.println(ans);
    }
}
