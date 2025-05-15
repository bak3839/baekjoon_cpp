import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, ans;
    static Ride[] rides;

    static class Ride {
        int start, end;

        Ride(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public String toString() {
            return "Ride [start=" + start + ", end=" + end + "]";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        rides = new Ride[N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            start = (start / 100 * 60) + (start % 100) - 10;
            end = (end / 100 * 60) + (end % 100) + 10;
            rides[i] = new Ride(start, end);
        }

        Arrays.sort(rides, (r1, r2) ->
                (r1.start == r2.start) ? Integer.compare(r1.end, r2.end) : Integer.compare(r1.start, r2.start)
        );
        
        int prev = 10 * 60, deadline = 22 * 60;

        for(int i = 0; i < N; i++) {
            int res = rides[i].start - prev;
            ans = Math.max(ans, res);
            prev = Math.max(prev, rides[i].end);
        }
        ans = Math.max(ans, deadline - prev);

        System.out.println(ans);
    }
}
