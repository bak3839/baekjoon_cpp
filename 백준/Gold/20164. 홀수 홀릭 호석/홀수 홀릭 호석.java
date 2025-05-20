import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int minAnswer = Integer.MAX_VALUE, maxAnswer = Integer.MIN_VALUE;
    static String N;

    public static int countOdd(String s) {
        int count = 0;
        for(char c : s.toCharArray()) {
            if((c - '0') % 2 == 1) count++;
        }
        return count;
    }

    public static void search(String s, int count) {
        int res = countOdd(s);

        if(s.length() == 1) {
            minAnswer = Math.min(minAnswer, count + res);
            maxAnswer = Math.max(maxAnswer, count + res);
            return;
        }

        if(s.length() == 2) {
            int sum = (s.charAt(0) - '0') + (s.charAt(1) - '0');
            search(String.valueOf(sum), count + res);
        }

        else if(s.length() >= 3) {
            int len = s.length();
            for(int cut1 = 1; cut1 <= len - 2; cut1++) {
                for(int cut2 = cut1 + 1; cut2 <= len - 1; cut2++) {
                    int n1 = Integer.parseInt(s.substring(0, cut1));
                    int n2 = Integer.parseInt(s.substring(cut1, cut2));
                    int n3 = Integer.parseInt(s.substring(cut2));
                    search(String.valueOf(n1 + n2 + n3), count + res);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = br.readLine();

        search(N, 0);
        System.out.println(minAnswer + " " + maxAnswer);
    }
}
