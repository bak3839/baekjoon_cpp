import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, A, B;
    static int[] magic = new int[2];
    static boolean[] visited;

    public static int bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        visited[0] = true;

        int cnt = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            while (size-- > 0) {
                int now = q.poll();

                for(int i = 0; i < 2; i++) {
                    int next = now + magic[i];

                    if(next > N || visited[next]) continue;
                    if(next == N) return cnt;

                    q.add(next);
                    visited[next] = true;
                }
            }

            cnt++;
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        magic[0] = A; magic[1] = B;
        visited = new boolean[N + 1];

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            for(int j = start; j <= end; j++) {
                visited[j] = true;
            }
        }

        System.out.println(bfs());
    }
}
