import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            int M = Integer.parseInt(br.readLine());

            int res = (M + 1) / 50;
            int mod = (M + 1) % 50;

            int total = (res - 1) * 12 + (mod > 0 ? 12 : 0);
            int time = 6 * 60 + 6 + total; // 뷴단위 변환
            int lastTime = 24 * 60 + 6;

            if (lastTime < time) {
                System.out.println("-1");
                continue;
            }

            String HH = String.valueOf(time / 60);
            String MM = String.valueOf(time % 60);
            if (HH.length() == 1) {
                HH = "0" + HH;
            } else if (HH.equals("24")) {
                HH = "00";
            }

            if (MM.length() == 1) {
                MM = "0" + MM;
            }

            System.out.println(HH + ":" + MM);
        }
    }
}
