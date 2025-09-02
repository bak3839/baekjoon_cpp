import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, ans;
    static int[] num = new int[2];
    static List<Set<String>> animals = new ArrayList<>();

    public static void calculate() {
        int res = 0;
        int n1 = num[0], n2 = num[1];

        for (String s : animals.get(n1)) {
            if (animals.get(n2).contains(s)) res++;
        }

        ans = Math.max(res, ans);
    }

    public static void search(int x, int count) {
        if (count == 2) {
            calculate();
            return;
        }

        for (int i = x; i < N; i++) {
            num[count] = i;
            search(i + 1, count + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int K = Integer.parseInt(st.nextToken());

            animals.add(new HashSet<>());

            for (int k = 0; k < K; k++) {
                String s = st.nextToken();
                animals.get(i).add(s);
            }
        }

        search(0, 0);
        System.out.println(ans + 1);
    }
}
