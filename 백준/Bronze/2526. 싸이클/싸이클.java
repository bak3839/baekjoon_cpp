import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int result = N, count = 1;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(N, 0);

        while (true) {
            result = (result * N) % P;

            if (!map.containsKey(result)) {
                map.put(result, count++);
                continue;
            }

            System.out.println(count - map.get(result));
            break;
        }
    }
}
