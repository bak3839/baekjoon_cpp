import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            double n =  Double.parseDouble(st.nextToken());

            while(st.hasMoreTokens()){
                String oper = st.nextToken();
                if (oper.equals("@")) {
                    n *= 3.0;
                } else if (oper.equals("#")) {
                    n -= 7.0;
                } else if (oper.equals("%")) {
                    n += 5.0;
                }
            }
            System.out.printf("%.2f\n", n);
        }
    }
}
