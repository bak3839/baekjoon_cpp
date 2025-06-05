import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N, count;
    static HashMap<Integer, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            int A = Integer.parseInt(st.nextToken());
            map.merge(A, 1, Integer::sum);
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            int B = Integer.parseInt(st.nextToken());

            if(map.getOrDefault(B, 0) > 0) {
                count++;
                map.merge(B, -1, Integer::sum);
            }
        }

        System.out.println(N - count);
    }
}
