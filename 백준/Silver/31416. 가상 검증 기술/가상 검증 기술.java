import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int Q = Integer.parseInt(br.readLine());

        for (int i = 0; i < Q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int Ta = Integer.parseInt(st.nextToken());
            int Tb = Integer.parseInt(st.nextToken());
            int Va = Integer.parseInt(st.nextToken());
            int Vb = Integer.parseInt(st.nextToken());
            boolean flag = false;
            int time = 0, a = Ta, b = Tb;

            while (Va > 0 || Vb > 0) {
                if (b == time) {
                    if(flag) Va--;
                    else Vb--;

                    if(Vb > 0) {
                        b += Tb;
                    } else {
                        flag = true;
                        b += Ta;
                    }
                }

                if (a == time) {
                    Va--;
                    a += Ta;
                }

                time++;
            }

            System.out.println(time - 1);
        }
    }
}
