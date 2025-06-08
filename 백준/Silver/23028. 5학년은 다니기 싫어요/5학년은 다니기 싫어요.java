import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, A, B;
    static int[][] lecture = new int[10][2];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        for(int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            lecture[i][0] = Integer.parseInt(st.nextToken());
            lecture[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < 8 - N; i++) {
            int limit = 6;
            int a = lecture[i][0] * 3;
            int b = Math.min(lecture[i][1], limit - lecture[i][0]) * 3;

            A += a;
            B += a;
            B += b;
        }

        if(A >= 66 && B >= 130) {
            System.out.println("Nice");
        } else {
            System.out.println("Nae ga wae");
        }
    }
}
