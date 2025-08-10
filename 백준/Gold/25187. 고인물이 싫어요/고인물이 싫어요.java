import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, Q;
    static int[] water, parent;

    public static int getRoot(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = getRoot(parent[x]);
    }

    public static void union(int x, int y) {
        int a = getRoot(x);
        int b = getRoot(y);

        if (a < b) {
            parent[b] = a;
            water[a] += water[b];
        } else if (a > b){
            parent[a] = b;
            water[b] += water[a];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        water = new int[N + 1];
        parent = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int n = Integer.parseInt(st.nextToken());
            water[i] = (n == 0 ? -1 : 1);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            union(u, v);
        }

        for (int i = 0; i < Q; i++) {
            int x = Integer.parseInt(br.readLine());
            int root = getRoot(x);

            if (water[root] > 0) System.out.println(1);
            else System.out.println(0);
        }
    }
}
