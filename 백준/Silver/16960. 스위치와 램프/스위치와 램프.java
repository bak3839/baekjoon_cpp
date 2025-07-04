import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static boolean[] on;
    static List<List<Integer>> lamps = new ArrayList<>();

    public static boolean turnOn(int skip) {
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (i == skip) continue;

            for (int lamp : lamps.get(i)) {
                if (on[lamp]) continue;

                count++;
                on[lamp] = true;
            }
        }

        return (count == M);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        on = new boolean[M + 1];

        for (int i = 0; i < N; i++) {
            lamps.add(new ArrayList<>());
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());

            for (int j = 0; j < n; j++) {
                lamps.get(i).add(Integer.parseInt(st.nextToken()));
            }
        }

        boolean pass = false;

        for (int i = 0; i < N; i++) {
            if (turnOn(i)) {
                pass = true;
                break;
            }

            Arrays.fill(on, false);
        }

        if (pass) System.out.println("1");
        else System.out.println("0");
    }
}
