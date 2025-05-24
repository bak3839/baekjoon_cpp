import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K, ans;
    static int[] satisfactions;

    public static void search(int idx, int sum, int energy, boolean eat) {
        if(idx == N) {
            if(sum >= K) energy += (sum - K);
            ans = Math.max(ans, energy);
            return;
        }

        if(sum >= K) {
            search(idx + 1, 0, energy + (sum - K), false);
            search(idx + 1, satisfactions[idx], energy + (sum - K), true);
            return;
        }

        if(!eat) {
            search(idx + 1, 0, energy, false);
        }

        search(idx + 1, sum + satisfactions[idx], energy, true);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        satisfactions = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            satisfactions[i] = Integer.parseInt(st.nextToken());
        }

        search(0, 0, 0, false);
        System.out.println(ans);
    }
}
