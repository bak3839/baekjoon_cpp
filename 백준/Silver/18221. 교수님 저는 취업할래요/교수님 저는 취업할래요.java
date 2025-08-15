import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, a, b, c, d;
    static int[][] A;

    public static boolean check() {
        int n1 = a - c;
        int n2 = b - d;
        double dist = Math.sqrt((double) (n1 * n1 + n2 * n2));

        if (dist < 5.0) return false;

        int count = 0;
        int minX = Math.min(a, c);
        int maxX = Math.max(a, c);
        int minY = Math.min(b, d);
        int maxY = Math.max(b, d);

        for (int x = minX; x <= maxX; x++) {
            for (int y = minY; y <= maxY; y++) {
                if (A[x][y] == 1) count++;
            }
        }

        return count >= 3;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        A = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());

                if (A[i][j] == 5) {
                    a = i;
                    b = j;
                } else if (A[i][j] == 2) {
                    c = i;
                    d = j;
                }
            }
        }

        if(check()) System.out.println(1);
        else System.out.println(0);
    }
}
