import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int maxValue = 0;
        String maxKey = "";
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            int value = map.compute(name, (k, v) -> v == null ? 1 : v + 1);

            if (value > maxValue) {
                maxValue = value;
                maxKey = name;
            }
        }

        if (N - maxValue < maxValue) System.out.println(maxKey);
        else System.out.println("NONE");
    }
}
