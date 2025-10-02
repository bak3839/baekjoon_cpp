import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] A;

    public static int changeNumber(String input) {
        StringTokenizer st = new StringTokenizer(input);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < M; i++) {
            sb.append(st.nextToken());
        }
        return Integer.parseInt(sb.toString());
    }

    public static int spin(int start) {
        int count = 0;
        StringBuilder sb = new StringBuilder();
        while (count < M) {
            sb.append(A[start]);
            start = start + 1 >= N ? 0 : start + 1;
            count++;
        }
        return Integer.parseInt(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            int X = changeNumber(br.readLine());
            int Y = changeNumber(br.readLine());
            int ans = 0;
            A = new int[N];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                A[i] = Integer.parseInt(st.nextToken());
            }

            for (int i = 0; i < N; i++) {
                int Z = spin(i);
                if (X <= Z && Z <= Y) ans++;
            }
            System.out.println(ans);
        }
    }
}
