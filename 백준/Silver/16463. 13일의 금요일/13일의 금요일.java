import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int year = 2019, last = 2, ans = 0;
        int[] month = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int N = Integer.parseInt(br.readLine());

        while(year <= N) {
            int dayOfWeek = last;

            if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
                month[2] = 29;
            } else {
                month[2] = 28;
            }

            for(int m = 1; m <= 12; m++) {
                for(int d = 1; d <= month[m]; d++) {
                    if(d == 13 && dayOfWeek == 5) ans++;

                    dayOfWeek = dayOfWeek % 7 + 1;
                }
            }

            last = dayOfWeek;
            year++;
        }

        System.out.println(ans);
    }
}
