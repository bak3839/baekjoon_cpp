import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M;
    static int[] A, temp;
    static HashMap<Integer, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = new int[N];
        temp = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            map.put(A[i], i);
        }

        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());

            List<Integer> indexes = new ArrayList<>();
            List<Integer> keys = new ArrayList<>();

            for(int j = L; j <= R; j++) {
                keys.add(j);
                indexes.add(map.get(j));
            }
            indexes.sort(Integer::compareTo);

            System.arraycopy(A, 0, temp, 0, N);
            for(int k = 0; k < indexes.size(); k++) {
                int index = indexes.get(k);
                temp[index] = keys.get(k);
            }

            Arrays.stream(temp).forEach(a -> System.out.print(a + " "));
            System.out.println();
        }
    }
}
