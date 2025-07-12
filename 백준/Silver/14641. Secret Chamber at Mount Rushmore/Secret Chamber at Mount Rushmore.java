import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static boolean[] visited = new boolean[26];
    static List<List<Integer>> graph = new ArrayList<>();

    public static void initialize() {
        for (int i = 0; i < 26; i++) {
            graph.add(new ArrayList<>());
        }
    }

    public static boolean dfs(int now, int target) {
        visited[now] = true;

        for (int next : graph.get(now)) {
            if (visited[next]) continue;

            if (next == target) return true;
            if (dfs(next, target)) return true;
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        initialize();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            char a = st.nextToken().charAt(0);
            char b = st.nextToken().charAt(0);
            graph.get(a - 'a').add(b - 'a');
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            boolean pass = true;
            String plain = st.nextToken();
            String cipher = st.nextToken();

            if (plain.length() == cipher.length()) {
                for (int idx = 0; idx < plain.length(); idx++) {
                    Arrays.fill(visited, false);
                    int from = plain.charAt(idx) - 'a';
                    int to = cipher.charAt(idx) - 'a';

                    if (from == to) continue;

                    if(!dfs(from, to)) {
                        pass = false;
                        break;
                    };
                }
            } else pass = false;

            if (pass) System.out.println("yes");
            else System.out.println("no");
        }
    }
}
