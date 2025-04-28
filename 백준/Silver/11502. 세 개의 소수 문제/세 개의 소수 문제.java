import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<Integer> primes = new ArrayList<>();

    public static void getPrimes() {
        boolean[] primeCheck = new boolean[1001];
        Arrays.fill(primeCheck, true);
        primeCheck[0] = false;
        primeCheck[1] = false;

        for(int i = 2; i <= Math.sqrt(1000); i++) {
            if(primeCheck[i]) {
                for(int j = i * i; j <= 1000; j += i) {
                    primeCheck[j] = false;
                }
            }
        }

        for(int i = 2; i <= 1000; i++) {
            if(!primeCheck[i]) continue;

            primes.add(i);
        }
    }

    public static boolean combination(int idx, int cnt, int sum, int target, List<Integer> ans) {
        if(cnt == 3) {
            if(sum == target) {
                return true;
            }

            return false;
        }

        if(primes.get(idx) > target) return false;

        for(int i = idx; i < primes.size(); i++) {
            ans.add(primes.get(i));
            if(combination(i, cnt + 1, sum + primes.get(i), target, ans)) return true;
            ans.remove(ans.size() - 1);
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        getPrimes();

        for(int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            List<Integer> ans = new ArrayList<>();

            if(combination(0, 0, 0, n, ans)) {
                for(int a : ans) {
                    System.out.print(a + " ");
                }
                System.out.print("\n");
            } else {
                System.out.println("0");
            }
        }
    }
}
