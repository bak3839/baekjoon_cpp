import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        List<Pair> pairs = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pairs.add(new Pair(a, b));
        }

        pairs.sort(Comparator.comparing(pair -> pair.x));

        int time = pairs.get(0).x +  pairs.get(0).y;
        for (int i = 1; i < pairs.size(); i++) {
            if (time < pairs.get(i).x) {
                time = pairs.get(i).x;
            }
            time += pairs.get(i).y;
        }
        System.out.println(time);
    }
}
