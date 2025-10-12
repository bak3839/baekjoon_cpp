import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int Y = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(br.readLine());
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            if (a == 0) rows.add(n);
            else cols.add(n);
        }
        rows.sort(Comparator.naturalOrder());
        cols.sort(Comparator.naturalOrder());

        int maxX = 0, maxY = 0, prevX = 0, prevY = 0;
        for (int x : rows) {
            maxX = Math.max(maxX, x - prevX);
            prevX = x;
        }
        maxX = Math.max(maxX, X - prevX);

        for (int y : cols) {
            maxY = Math.max(maxY, y - prevY);
            prevY = y;
        }
        maxY = Math.max(maxY, Y - prevY);

        System.out.println(maxX * maxY);
    }
}
