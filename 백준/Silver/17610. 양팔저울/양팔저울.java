import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, S;
    static int[] g;
    static boolean[] checked, visited;

    public static void search(int x, int sum) {
        if(!checked[sum]) {
            S--;
            checked[sum] = true;
        }

        for(int i = x; i < N; i++) {
            search(i + 1, sum + g[i]);
            search(i + 1, Math.abs(sum - g[i]));
            search(i + 1, sum);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        g = new int[N];


        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            g[i] = Integer.parseInt(st.nextToken());
            S += g[i];
        }
        visited = new boolean[N];
        checked = new boolean[S + 1];
        checked[0] = true;
        checked[S] = true;

        search(0, 0);

        System.out.println(S - 1);
    }
}
