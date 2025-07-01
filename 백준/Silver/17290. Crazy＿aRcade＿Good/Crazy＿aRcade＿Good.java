import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int R, C, ans = 21;
    static char[][] map = new char[11][11];
    static List<Pair> pairs = new ArrayList<>();

    public static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void bomb(Pair pair) {
        for(int i = 1; i <= 10; i++) {
            map[pair.x][i] = 'o';
        }

        for(int i = 1; i <= 10; i++) {
            map[i][pair.y] = 'o';
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= 10; i++) {
            String line = br.readLine();
            for (int j = 1; j <= 10; j++) {
                map[i][j] = line.charAt(j - 1);

                if (map[i][j] == 'o') pairs.add(new Pair(i, j));
            }
        }

        pairs.forEach(Main::bomb);

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if(map[i][j] == 'o') continue;

                ans = Math.min(ans, Math.abs(i - R) + Math.abs(j - C));
            }
        }

        System.out.println(ans);
    }
}
