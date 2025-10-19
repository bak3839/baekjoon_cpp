import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Missile {
        int number;
        double cost;

        Missile(int number, double cost) {
            this.number = number;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<Missile> missiles = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());

            double cost = Math.sqrt(X * X + Y * Y) / (double) V;
            missiles.add(new Missile(i + 1, cost));
        }
        
        missiles.sort(
          Comparator.comparing((Missile m) -> m.cost)
            .thenComparing(m -> m.number)
        );

        missiles.forEach(m -> System.out.println(m.number));
    }
}
