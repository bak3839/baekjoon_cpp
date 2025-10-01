import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<Integer> w = new ArrayList<>();
        int count = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            w.add(Integer.parseInt(st.nextToken()));
        }

        w.sort(Comparator.reverseOrder());
        
        for (int i = 0; i < N; i++) {
            if (count > w.get(i)) break;
            count++;
        }
        System.out.println(count);
    }
}
