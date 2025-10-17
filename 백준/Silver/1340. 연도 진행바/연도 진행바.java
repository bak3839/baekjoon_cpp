import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Map<String, Integer> months = new HashMap<>();
        months.put("January", 1); months.put("February", 2);
        months.put("March", 3); months.put("April", 4);
        months.put("May", 5); months.put("June", 6);
        months.put("July", 7); months.put("August", 8);
        months.put("September", 9); months.put("October", 10);
        months.put("November", 11); months.put("December", 12);

        int totalDay = 365;
        int month = months.get(st.nextToken());
        int day = Integer.parseInt(st.nextToken().substring(0, 2));
        int year = Integer.parseInt(st.nextToken());
        String time = st.nextToken();

        int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year)) {
            days[2] = 29;
            totalDay = 366;
        }

        for (int m = 1; m < month; m++) {
            day += days[m];
        }

        int hour = Integer.parseInt(time.split(":")[0]);
        int minute = Integer.parseInt(time.split(":")[1]);

        double result = (double) (day - 1) * 24 * 60 + hour * 60 + minute;
        double total = (double) totalDay * 24 * 60;

        System.out.printf("%.9f\n", (result / total) * 100);
    }

    private static boolean isLeapYear(int year) {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }
}
