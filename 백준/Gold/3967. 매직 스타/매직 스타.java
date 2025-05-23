import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    /**
     * 1행 가로 -> 0
     * 3행 가로 -> 1
     * 1~4행 \ 대각선 -> 2
     * 0~3행 \ 대각선 -> 3
     * 1~4행 / 대각선 -> 4
     * 0~3행 / 대각선 -> 5
     */
    static int[] sum = new int[6];
    static boolean[] used = new boolean[12];
    static char[][] star = new char[5][9];
    static List<Pair> pairs = new ArrayList<>();
    static HashMap<String, Pair> map = new HashMap<>();

    static class Pair {
        int n1, n2;
        Pair(int n1, int n2) {
            this.n1 = n1;
            this.n2 = n2;
        }
    }

    public static void initialize() {
        map.put("0 4", new Pair(3, 5)); map.put("1 1", new Pair(0, 2)); map.put("1 3", new Pair(0, 5));
        map.put("1 5", new Pair(0, 3)); map.put("1 7", new Pair(0, 4)); map.put("2 2", new Pair(2, 5));
        map.put("2 6", new Pair(3, 4)); map.put("3 1", new Pair(1, 5)); map.put("3 3", new Pair(1, 2));
        map.put("3 5", new Pair(1, 4)); map.put("3 7", new Pair(1, 3)); map.put("4 4", new Pair(2, 4));
    }

    public static boolean search(int idx) {
        if(idx == pairs.size()) {
            return Arrays.stream(sum).allMatch(sum -> sum == 26);
        }

        Pair pair = pairs.get(idx);
        int x = pair.n1, y = pair.n2;
        String key = x + " " + y;

        Pair pair2 = map.get(key);
        int n1 = pair2.n1, n2 = pair2.n2;

        for(int i = 0; i < 12; i++) {
            if(used[i]) continue;
            if(sum[n1] + i + 1 > 26 || sum[n2] + i + 1 > 26) continue;

            char c = (char) ('A' + i);
            star[x][y] = c;

            used[i] = true;
            sum[n1] += i + 1; sum[n2] += i + 1;
            if(search(idx + 1)) return true;
            used[i] = false;
            sum[n1] -= (i + 1); sum[n2] -= (i + 1);
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        initialize();
        for(int i = 0; i < 5; i++) {
            String s = br.readLine();
            for(int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                star[i][j] = c;

                if(c == '.') continue;

                if(c == 'x') {
                    pairs.add(new Pair(i, j));
                    continue;
                }

                String key = i + " " + j;
                Pair p = map.get(key);

                used[c - 'A'] = true;
                sum[p.n1] += c - 'A' + 1;
                sum[p.n2] += c - 'A' + 1;
            }
        }

        search(0);

        Arrays.stream(star).forEach(System.out::println);
    }
}
