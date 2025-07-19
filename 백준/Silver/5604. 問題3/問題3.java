import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int N;
    static List<Integer> list = new ArrayList<>();

    public static void search(int n) {
        if(n == 0) {
            list.forEach(num -> System.out.print(num + " "));
            System.out.println();
            return;
        }

        for(int i = n; i >= 1; i--) {
            if(!list.isEmpty() && list.get(list.size() - 1) < i) continue;

            list.add(i);
            search(n - i);
            list.remove(list.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        search(N);
    }
}
