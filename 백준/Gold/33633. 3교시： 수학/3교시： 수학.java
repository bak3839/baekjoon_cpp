import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;

    public static void bfs() {
        int expand = N;

        Queue<Long> queue = new LinkedList<>();
        queue.offer(1L);

        for (int step = 1; step < expand; step++) {
            int size = queue.size();
            Set<Long> nextLevel = new HashSet<>();

            for (int i = 0; i < size; i++) {
                long cur = queue.poll();

                nextLevel.add(cur * 2L);

                if ((cur - 1) % 3 == 0) {
                    long oddPrev = (cur - 1) / 3;
                    if (oddPrev > 1 && (oddPrev & 1L) == 1L) {
                        nextLevel.add(oddPrev);
                    }
                }
            }

            for (long v : nextLevel) queue.offer(v);
        }

        List<Long> ans = new ArrayList<>();
        while (!queue.isEmpty()) ans.add(queue.poll());
        Collections.sort(ans);

        System.out.println(ans.size());
        for (long v : ans) System.out.println(v);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        bfs();
    }
}
