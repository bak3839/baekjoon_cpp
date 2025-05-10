import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int T, N, ans;
    static List<Integer> num;
    static List<String> mbti;

    public static void calculate() {
        int sum = 0;

        for(int i = 0; i < 2; i++) {
            String m1 = mbti.get(num.get(i));

            for(int j = i + 1; j < 3; j++) {
                String m2 = mbti.get(num.get(j));

                for(int k = 0; k < m1.length(); k++) {
                    if(m1.charAt(k) != m2.charAt(k)) sum++;
                }
            }
        }

        ans = Math.min(ans, sum);
    }

    public static void combination(int x, int cnt) {
        if(cnt == 3) {
            calculate();
            return;
        }

        for(int i = x; i < mbti.size(); i++) {
            num.add(i);
            combination(i + 1, cnt + 1);
            num.remove(num.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        while(T-- > 0) {
            ans = Integer.MAX_VALUE;
            num = new ArrayList<>();
            mbti = new ArrayList<>();
            HashMap<String, Integer> map = new HashMap<>();
            N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            for(int i = 0; i < N; i++) {
                String s = st.nextToken();
                Integer value = map.get(s);
                if(value == null) {
                    map.put(s, 1);
                    mbti.add(s);
                } else if(value < 3) {
                    map.put(s, value + 1);
                    mbti.add(s);
                }
            }

            combination(0, 0);
            System.out.println(ans);
        }
    }
}
