import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int x, y, ans = 0;
        int n = Integer.parseInt(st.nextToken());
        HashMap<Integer, Integer> xCount = new HashMap<>();
        HashMap<Integer, Integer> yCount = new HashMap<>();

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            if(xCount.containsKey(x)) {
                xCount.compute(x, (key, value) -> value + 1);
            } else {
                xCount.put(x, 1);
            }

            if(yCount.containsKey(y)) {
                yCount.compute(y, (key, value) -> value + 1);
            } else {
                yCount.put(y, 1);
            }
        }

        for(int value : xCount.values()) {
            if(value >= 2) ans++;
        }

        for(int value : yCount.values()) {
            if(value >= 2) ans++;
        }

        System.out.println(ans);
    }
}
