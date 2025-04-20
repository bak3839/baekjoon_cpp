import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        boolean pass = false;
        int N, S, D, F, B, K, ans = 0;
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        boolean[] visited = new boolean[N + 1];

        if(K != 0) {
            st = new StringTokenizer(br.readLine());
        }
        for(int i = 0; i < K; i++) {
            visited[Integer.parseInt(st.nextToken())] = true;
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(S);
        visited[S] = true;

        while(!q.isEmpty()) {
            int size = q.size();

            while(size-- > 0) {
                int now = q.poll();

                if(now == D) {
                    pass = true;
                    break;
                }

                if(now + F <= N && !visited[now + F]) {
                    q.add(now + F);
                    visited[now + F] = true;
                }
                if(now - B >= 1 && !visited[now - B]) {
                    q.add(now - B);
                    visited[now - B] = true;
                }
            }

            if(pass) break;
            ans++;
        }

        if(pass) System.out.println(ans);
        else System.out.println("BUG FOUND");
    }
}
