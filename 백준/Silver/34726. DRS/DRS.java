import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Driver {
        int dist;
        String name;
        public Driver(int dist, String name) {
            this.dist = dist;
            this.name = name;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        List<Driver> drivers = new ArrayList<>();
        List<String> names = new ArrayList<>();

        int sum = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int dist = Integer.parseInt(st.nextToken());

            sum = (sum + dist) % T;
            drivers.add(new Driver(sum % T, name));
        }

        drivers.get(0).dist = T;
        drivers.sort(Comparator.comparing(driver -> driver.dist));

        if (drivers.get(0).dist <= 1000) {
            names.add(drivers.get(0).name);
        }

        for (int i = 1; i < drivers.size(); i++) {
            int front =  drivers.get(i - 1).dist;
            int back = drivers.get(i).dist;
            int diff = back - front;

            if (1<= diff && diff <= 1000) {
                names.add(drivers.get(i).name);
            }
        }
        names.sort(Comparator.naturalOrder());

        if (names.isEmpty()) System.out.println("-1");
        else names.forEach(name -> System.out.print(name + " "));
    }
}
