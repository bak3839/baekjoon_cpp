import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;



public class Main {
    static class Cloud {
        int x;
        int y;
        int water;
        public Cloud(int x, int y, int water) {
            this.x = x;
            this.y = y;
            this.water = water;
        }
    }

    static int N, M;
    static boolean[][] visited = new boolean[51][51];
    static int[][] map = new int[51][51];
    static int[][] mv = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

    // 구름 이동
    public static List<Cloud> move(int d, int s, List<Cloud> clouds) {
        List<Cloud> moved = new ArrayList<>();
        
        for(Cloud cloud : clouds) {
            int nx = cloud.x + (mv[d][0] * (s % N));
            int ny = cloud.y + (mv[d][1] * (s % N));

            if(nx < 0) nx = nx + N;
            else if(nx >= N) nx = nx - N;
            if(ny < 0) ny = ny + N;
            else if(ny >= N) ny = ny - N;
            
            moved.add(new Cloud(nx, ny, 0));
            map[nx][ny] += 1;
            visited[nx][ny] = true;
        }
        
        return moved;
    }

    //물복사버그 마법
    public static void magic(List<Cloud> moved) {
        int[] dirs = {2, 4, 6, 8};
        List<Cloud> clouds = new ArrayList<>();

        for(Cloud cloud : moved) {
            int count = 0;

            for(int d : dirs) {
                int nx = cloud.x + mv[d][0];
                int ny = cloud.y + mv[d][1];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                if(map[nx][ny] > 0) count++;
            }

            clouds.add(new Cloud(cloud.x, cloud.y, count));
        }

        for(Cloud cloud : clouds) {
            map[cloud.x][cloud.y] += cloud.water;
        }
    }

    // 새로운 구름 생성
    public static List<Cloud> create() {
        List<Cloud> created = new ArrayList<>();

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j]) {
                    visited[i][j] = false;
                    continue;
                }

                if(map[i][j] >= 2) {
                    map[i][j] -= 2;
                    created.add(new Cloud(i, j, 1));
                }
            }
        }

        return created;
    }

    public static int calculate() {
        int ans = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans += map[i][j];
            }
        }

        return ans;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        List<Cloud> created = new ArrayList<>();
        List<Cloud> moved = new ArrayList<>();

        for(int i = N - 2; i < N; i++) {
            for(int j = 0; j < 2; j++) {
                created.add(new Cloud(i, j, 1));
            }
        }

        while(M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            moved = move(d, s, created);
            magic(moved);

            moved.clear();
            created.clear();

            created = create();
        }

        System.out.println(calculate());
    }
}
