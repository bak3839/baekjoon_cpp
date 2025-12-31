import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Person {
        String name;
        int price;
        public Person(String name, int price) {
            this.name = name;
            this.price = price;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int U = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int min = Integer.MAX_VALUE;
        int[] counts = new int[U + 1];
        Person[] persons = new Person[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int p =  Integer.parseInt(st.nextToken());
            persons[i] = new Person(name, p);
            counts[p]++;
        }

        for (int i = 1; i <= U; i++) {
            if (counts[i] == 0) continue;
            min = Math.min(min, counts[i]);
        }

        Person ans = null;
        for (Person person : persons) {
            if (counts[person.price] != min) continue;

            if (ans == null || ans.price > person.price) {
                ans = person;
            }
        }

        System.out.println(ans.name + " "  + ans.price);
    }
}
