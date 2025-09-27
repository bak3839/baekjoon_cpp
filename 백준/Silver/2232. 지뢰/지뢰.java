import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static class Landmine {
        int num;
        int power;
        public Landmine(int num, int power) {
            this.num = num;
            this.power = power;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] P = new int[N];
        List<Integer> ans = new ArrayList<>();
        List<Landmine> landmines = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(br.readLine());
            landmines.add(new Landmine(i, P[i]));
        }
        landmines.sort((x, y) -> y.power - x.power);

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (count == N) break;

            int power = landmines.get(i).power;
            int num = landmines.get(i).num;
            if (P[num] == 0) continue;
            P[num] = 0;
            count++;
            ans.add(num + 1);

            for (int j = num - 1; j >= 0; j--) {
                if (P[j] == 0 || P[j] >= power) break;

                power = P[j];
                P[j] = 0;
                count++;
            }
            power = landmines.get(i).power;
            for (int j = num + 1; j < N; j++) {
                if (P[j] == 0 || P[j] >= power) break;

                power = P[j];
                P[j] = 0;
                count++;
            }
        }

        ans.sort((n1, n2) -> n1 - n2);
        ans.forEach(System.out::println);
    }
}
