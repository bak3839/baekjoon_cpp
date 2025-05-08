import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int T, N;

    public static boolean change(int form) {
        int tmp = N;
        List<Integer> list = new ArrayList<>();

        while(tmp > 0) {
            list.add(tmp % form);
            tmp /= form;
        }

        int L = 0, R = list.size() - 1;
        while(L < R) {
            if(!list.get(L++).equals(list.get(R--))) return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());

        while(T-- > 0) {
            boolean ans = false;
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());


            for(int i = 2; i <= 64; i++) {
                if(change(i)) {
                    ans = true;
                    break;
                }
            }

            if(ans) System.out.println(1);
            else System.out.println(0);
        }
    }
}
