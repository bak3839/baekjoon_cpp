import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static int N, A, D, ans;
    static int[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        a = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N ; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }

        int target = A;

        for(int i = 0; i < N ; i++){
            if(a[i] != target) continue;

            target += D;
            ans++;
        }

        System.out.println(ans);
    }
}
