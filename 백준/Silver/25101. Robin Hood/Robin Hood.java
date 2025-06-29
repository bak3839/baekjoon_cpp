import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int[] ans;

    public static class Amount implements Comparable<Amount> {
        int money;
        int number;

        public Amount(int money, int number) {
            this.money = money;
            this.number = number;
        }

        public void decreaseMoney() {
            money -= 100;
        }

        @Override
        public int compareTo(Amount other) {
            if (this.money == other.money) {
                return Integer.compare(this.number, other.number);
            }
            return Integer.compare(other.money, this.money);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Amount> pq = new PriorityQueue<>();

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        ans = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int P = Integer.parseInt(st.nextToken());
            pq.add(new Amount(P, i));
        }

        boolean pass = true;
        while (!pq.isEmpty() && K-- > 0) {
            if (pq.peek().money <= 100) {
                pass = false;
                break;
            }

            Amount amount = pq.poll();
            amount.decreaseMoney();
            pq.add(amount);
        }

        if (pass) {
            while (!pq.isEmpty()) {
                Amount amount = pq.poll();
                ans[amount.number] = amount.money;
            }
            Arrays.stream(ans).forEach(m -> System.out.print(m + " "));
        } else {
            System.out.println("impossible");
        }
    }
}
