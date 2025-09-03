import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {
    public static class Coor {
        int x, y;

        public Coor(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (o == null || getClass() != o.getClass()) return false;
            Coor coor = (Coor) o;
            return x == coor.x && y == coor.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int ans = 0;
        int[][] mv = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
        Coor[] coors = new Coor[K];
        HashSet<Coor> set = new HashSet<>();

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            set.add(new Coor(x, y));
            coors[i] = new Coor(x, y);
        }

        for (Coor coor : coors) {
            for (int[] m : mv) {
                int nx = coor.x + m[0];
                int ny = coor.y + m[1];

                if (nx <= 0 || ny <= 0 || nx > N || ny > N || set.contains(new Coor(nx, ny))) continue;

                set.add(new Coor(nx, ny));
                ans++;
            }
        }

        System.out.println(ans);
    }
}
