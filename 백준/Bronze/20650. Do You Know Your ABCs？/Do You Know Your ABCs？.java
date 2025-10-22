import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] A = new int[7];
    static int[] num = new int[3];
    static List<Integer> list = new ArrayList<>();

    public static boolean calculate() {
        for (int i = 0; i < 3; i++) {
            list.add(num[i]);
            list.add(num[i] + num[(i + 1) % 3]);
        }
        list.add(num[0] +  num[1] + num[2]);
        list.sort(Integer::compareTo);

        for (int i = 0; i < 7; i++) {
            if (A[i] != list.get(i)) {
                list.clear();
                return false;
            }
        }
        return true;
    }

    public static boolean search(int x, int index) {
        if (index == 3) {
            return calculate();
        }

        for (int i = x; i < 7; i++) {
            num[index] = A[i];
            if (search(i + 1, index + 1)) return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 7; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(A);

        search(0, 0);
        Arrays.stream(num).forEach(n -> System.out.print(n + " "));
    }
}
