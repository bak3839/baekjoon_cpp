import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] A;
    static HashSet<Integer> set = new HashSet<>();

    public static void search(int x, int sum) {
        if(x == N) {
            set.add(sum);
            return;
        }

        search(x + 1, sum);
        search(x + 1, sum + A[x]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            M += A[i];
        }

        search(0, 0);
        set.remove(0);
        System.out.println(M - set.size());
    }
}
