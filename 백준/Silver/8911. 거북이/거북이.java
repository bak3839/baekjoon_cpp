import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int move(String cmd) {
        int x = 0, y = 0, dir = 0, xMinLen = 0, yMinLen = 0, xMaxLen = 0, yMaxLen = 0;
        int[][] mv = {{0, 1}, {1 ,0}, {0, -1}, {-1, 0}};

        for(char ch : cmd.toCharArray()) {
            if(ch == 'L') {
                dir = (dir - 1 < 0 ? 3 : dir - 1);
            } else if(ch == 'R') {
                dir = (dir + 1 > 3 ? 0 : dir + 1);
            } else if(ch == 'F') {
                x = x + mv[dir][0];
                y = y + mv[dir][1];

                if(x < 0) xMinLen = Math.min(xMinLen, x);
                else xMaxLen = Math.max(xMaxLen, x);

                if(y < 0) yMinLen = Math.min(yMinLen, y);
                else yMaxLen = Math.max(yMaxLen, y);
            } else if(ch == 'B') {
                x = x + mv[dir][0] * -1;
                y = y + mv[dir][1] * -1;

                if(x < 0) xMinLen = Math.min(xMinLen, x);
                else xMaxLen = Math.max(xMaxLen, x);

                if(y < 0) yMinLen = Math.min(yMinLen, y);
                else yMaxLen = Math.max(yMaxLen, y);
            }
        }

        return (xMaxLen - xMinLen) * (yMaxLen - yMinLen);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        for(int i = 0; i < T; i++) {
            st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();

            System.out.println(move(cmd));
        }
    }
}
