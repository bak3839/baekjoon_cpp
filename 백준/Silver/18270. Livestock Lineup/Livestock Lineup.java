import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static HashMap<String, List<String>> map = new HashMap<>();
    static String[] cows = { "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
    static int[] index = new int[8];
    static boolean[] checked = new boolean[8];

    public static boolean confirm() {
        Map<String, Integer> pos = new HashMap<>();

        for (int i = 0; i < 8; i++) {
            pos.put(cows[index[i]], i);
        }

        for (String cow : cows) {
            for (String neighbor : map.get(cow)) {
                int diff = Math.abs(pos.get(neighbor) - pos.get(cow));
                if (diff != 1) return false;
            }
        }

        for (int i : index) {
            System.out.println(cows[i]);
        }

        return true;
    }

    public static boolean search(int count) {
        if (count == 8) {
            return confirm();
        }

        for (int i = 0; i < 8; i++) {
            if (checked[i]) continue;

            checked[i] = true;
            index[count] = i;
            if (search(count + 1)) return true;
            checked[i] = false;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (String cow : cows) {
            map.put(cow, new ArrayList<>());
        }

        for (int i = 0; i < N; i++) {
            String[] tokens = br.readLine().split(" ");
            String cow1 = tokens[0];
            String cow2 = tokens[tokens.length - 1];
            map.get(cow1).add(cow2);
            map.get(cow2).add(cow1);
        }

        search(0);
    }
}
