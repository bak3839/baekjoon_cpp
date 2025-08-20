import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static class Pair {
        int x; int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] keyboard1 = {
                {'q', 'w', 'e', 'r', 't'},
                {'a', 's', 'd', 'f', 'g'},
                {'z', 'x', 'c', 'v'}
        };
        char[][] keyboard2 = {
                {'y', 'u', 'i', 'o', 'p'},
                {'h', 'j', 'k', 'l'},
                {'b', 'n', 'm'}
        };
        HashMap<Character, Pair> left = new HashMap<>();
        HashMap<Character, Pair> right = new HashMap<>();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < keyboard1[i].length; j++) {
                left.put(keyboard1[i][j], new Pair(i, j));
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < keyboard2[i].length; j++) {
                right.put(keyboard2[i][j], new Pair(i, j + keyboard1[i].length));
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        char ch1 = st.nextToken().charAt(0);
        char ch2 = st.nextToken().charAt(0);
        Pair L = left.get(ch1) != null ? left.get(ch1) : right.get(ch1);
        Pair R = right.get(ch2) != null ? right.get(ch2) : left.get(ch2);

        String word = br.readLine();
        int total = 0;

        for (char ch : word.toCharArray()) {
            int x = 0, y = 0;
            Pair next = null;

            if (left.containsKey(ch)) {
                next = left.get(ch);
                x = L.x; y = L.y;
                L = next;
            } else {
                next = right.get(ch);
                x = R.x; y = R.y;
                R = next;
            }

            total += Math.abs(x - next.x) + Math.abs(y - next.y) + 1;
        }

        System.out.println(total);
    }
}
