import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            HashMap<Integer, Integer> map = new HashMap<>();
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            if(N == 0 || M == 0) break;

            for(int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());

                for(int j = 0; j < M; j++) {
                    int n = Integer.parseInt(st.nextToken());
                    int value = map.getOrDefault(n, 0);
                    map.put(n, value + 1);
                }
            }

            List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(map.entrySet());

            entryList.sort(Comparator
                    .comparing(Map.Entry<Integer, Integer>::getValue, Comparator.reverseOrder())
                    .thenComparing(Map.Entry::getKey)
            );

            int count = entryList.get(1).getValue();

            for (Map.Entry<Integer, Integer> entry : entryList) {
                if(entry.getValue() < count) break;

                if(entry.getValue() == count) System.out.print(entry.getKey() + " ");
            }
            System.out.println();
        }
    }
}
