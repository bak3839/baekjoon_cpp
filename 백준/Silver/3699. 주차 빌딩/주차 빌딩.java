import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int T, H, L;
    static int[] belt;
    static HashMap<Integer, Pair> map;

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static int customerVisit() {
        int sum = 0;

        for(Pair p : map.values()) {
            int h = p.x, end = p.y;
            int start = belt[h];
            int spin = Math.min((L - start + end) % L, (L - end + start) % L);

            sum += (spin * 5) + (h * 10 * 2);
            belt[h] = end;
        }

        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());

            map = new HashMap<>();
            belt = new int[H];

            for(int i = 0; i < H; i++) {
                st = new StringTokenizer(br.readLine());

                for(int j = 0; j < L; j++) {
                    int n = Integer.parseInt(st.nextToken());
                    if(n == -1) continue;
                    map.put(n, new Pair(i, j));
                }
            }

            System.out.println(customerVisit());
        }
    }
}
