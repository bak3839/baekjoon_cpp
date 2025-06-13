import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long ans;
    static int N, A, B;
    static List<Item> items = new ArrayList<>();

    static class Item {
        int p;
        int q;

        Item(int p, int q) {
            this.p = p;
            this.q = q;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            items.add(new Item(p, q));
        }

        items.sort((item1, item2) -> Integer.compare(Math.abs(item2.p - item2.q), Math.abs(item1.p - item1.q)));

        for (Item item : items) {
            if(item.p < item.q) {
                if(A == 0) {
                    B--;
                    ans += item.q;
                    continue;
                }

                A--;
                ans += item.p;
            } else {
                if(B == 0) {
                    A--;
                    ans += item.p;
                    continue;
                }

                B--;
                ans += item.q;
            }
        }

        System.out.println(ans);
    }
}
