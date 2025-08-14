import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int minX = 101, minY = 101, maxX = 0, maxY = 0;
    static String[] arr;

    public static String check() {
        for (int y = minY; y <= maxY; y++) {
            if (arr[minX].charAt(y) == '.') return "UP";
        }

        for (int y = minY; y <= maxY; y++) {
            if (arr[maxX].charAt(y) == '.') return "DOWN";
        }

        for (int x = minX; x <= maxX; x++) {
            if (arr[x].charAt(minY) == '.') return "LEFT";
        }

        return "RIGHT";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new String[N];

        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
            for (int j = 0; j < M; j++) {
                if (arr[i].charAt(j) == '#') {
                    minX = Math.min(minX, i);
                    minY = Math.min(minY, j);
                    maxX = Math.max(maxX, i);
                    maxY = Math.max(maxY, j);
                }
            }
        }

        System.out.println(check());
    }
}
