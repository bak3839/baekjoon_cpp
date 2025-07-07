import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans = Integer.MAX_VALUE;
    static boolean[] visited;
    static Coordinate[] coordinates;
    static List<Integer> group = new ArrayList<>();
    static List<List<Integer>> graph = new ArrayList<>();

    public static class Coordinate {
        int x, y;

        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void initialize() {
        visited = new boolean[N + 1];
        coordinates = new Coordinate[N + 1];
        for(int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
    }

    public static int calculate(int minX, int maxX, int minY, int maxY) {
        return ((maxX - minX) * 2) + ((maxY - minY) * 2);
    }

    public static void dfs(int now) {
        visited[now] = true;
        group.add(now);

        for(int next : graph.get(now)) {
            if(visited[next]) continue;

            dfs(next);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        initialize();

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            coordinates[i] = new Coordinate(x, y);
        }

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            graph.get(v1).add(v2);
            graph.get(v2).add(v1);
        }

        for(int i = 1; i <= N; i++) {
            if(visited[i]) continue;

            dfs(i);

            int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE;
            int minY = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE;

            for (int cow : group) {
                Coordinate coor = coordinates[cow];
                minX = Math.min(minX, coor.x);
                maxX = Math.max(maxX, coor.x);
                minY = Math.min(minY, coor.y);
                maxY = Math.max(maxY, coor.y);
            }

            ans = Math.min(ans, calculate(minX, maxX, minY, maxY));
            group.clear();
        }

        System.out.println(ans);
    }
}
