import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int H = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int total = H * 60 + M;

        String[] startTimes = {"6:30", "9:50", "10:50", "11:50", "12:50", "14:40", "15:40", "16:40"};
        String[] endTimes = {"9:0", "10:0", "11:0", "12:0", "13:50", "14:50", "15:50", "22:50"};

        String ans = "No";
        for (int i = 0; i < startTimes.length; i++) {
            StringTokenizer startToken = new StringTokenizer(startTimes[i], ":");
            StringTokenizer endToken = new StringTokenizer(endTimes[i], ":");
            int startH = Integer.parseInt(startToken.nextToken());
            int startM = Integer.parseInt(startToken.nextToken());
            int endH = Integer.parseInt(endToken.nextToken());
            int endM = Integer.parseInt(endToken.nextToken());

            if (startH * 60 + startM <= total && total <= endH * 60 + endM) {
                ans = "Yes";
            }
        }

        System.out.println(ans);
    }
}
