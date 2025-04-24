import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        while(T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            int ans = 0;
            int[] X = new int[N];
            HashSet<Integer> set = new HashSet<>();

            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++) {
                X[i] = Integer.parseInt(st.nextToken());
                set.add(X[i]);
            }
            Arrays.sort(X);

            for(int i = 1; i < N - 1; i++) {
                int mid = X[i];

                for(int j = i + 1; j < N; j++) {
                    int diff = X[j] - mid;

                    if(set.contains(mid - diff)) {
                        ans++;
                    }
                }
            }

            System.out.println(ans);
        }
    }
}
