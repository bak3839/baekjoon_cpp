import java.io.*;
import java.util.*;

public class Main {

    static long encode(int x, int y) {
        return ((long)x << 32) ^ (y & 0xffffffffL);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        long[] arr = new long[N];
        int[] xs = new int[N];
        int[] ys = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            xs[i] = x;
            ys[i] = y;
            arr[i] = encode(x, y);
        }

        Arrays.sort(arr);

        long ans = 0;

        int[][] dirs = {
          {A, B},
          {-A, B},
          {A, -B},
          {-A, -B}
        };

        for (int i = 0; i < N; i++) {
            int x = xs[i];
            int y = ys[i];

            for (int[] d : dirs) {
                int dx = d[0];
                int dy = d[1];

                long p2 = encode(x + dx, y);
                long p3 = encode(x, y + dy);
                long p4 = encode(x + dx, y + dy);

                if (Arrays.binarySearch(arr, p2) >= 0 &&
                  Arrays.binarySearch(arr, p3) >= 0 &&
                  Arrays.binarySearch(arr, p4) >= 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans / 4);
    }
}
