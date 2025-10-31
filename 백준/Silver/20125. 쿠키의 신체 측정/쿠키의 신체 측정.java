import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static String[] input;

    public static int leftArm(int x, int y) {
        int count = 0;
        for (int j = y - 1; j >= 0; j--) {
            char ch = input[x].charAt(j);
            if (ch != '*') break;
            count++;
        }
        return count;
    }

    public static int rightArm(int x, int y) {
        int count = 0;
        for (int j = y + 1; j < N; j++) {
            char ch = input[x].charAt(j);
            if (ch != '*') break;
            count++;
        }
        return count;
    }

    public static int leg(int x, int y) {
        int count = 0;
        for (int i = x; i < N; i++) {
            char ch = input[i].charAt(y);
            if (ch != '*') break;
            count++;
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        input = new String[N];
        boolean first = false;
        int heartX = 0, heartY = 0;

        for (int i = 0; i < N; i++) {
            input[i] = br.readLine();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char ch =  input[i].charAt(j);

                if (ch == '*') {
                    heartX = i + 1;
                    heartY = j;
                    break;
                }
            }
            if (heartX != 0) break;
        }

        int legX = 0, len = 0;
        for (int i = heartX; i < N; i++) {
            char ch =  input[i].charAt(heartY);
            if (ch != '*') {
                legX = i;
                break;
            }
            len++;
        }

        int leftArm = leftArm(heartX, heartY);
        int rightArm = rightArm(heartX, heartY);
        int leftLeg = leg(legX, heartY - 1);
        int rightLeg = leg(legX, heartY + 1);

        System.out.println((heartX + 1) + " " + (heartY + 1));
        System.out.println(leftArm + " " + rightArm + " " + (len - 1) + " " + leftLeg + " " + rightLeg);
    }
}
