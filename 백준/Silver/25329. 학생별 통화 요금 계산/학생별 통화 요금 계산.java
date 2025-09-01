import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Student implements Comparable<Student> {
        String name;
        int price;

        public Student(String name, int price) {
            this.name = name;
            this.price = price;
        }

        @Override
        public int compareTo(Student o) {
            int cmp = Integer.compare(o.price, this.price);
            if (cmp == 0) {
                return this.name.compareTo(o.name);
            }
            return cmp;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String time = st.nextToken();
            String name = st.nextToken();

            int H = Integer.parseInt(time.split(":")[0]);
            int M = Integer.parseInt(time.split(":")[1]);
            int total = (H * 60) + M;
            map.compute(name, (k, v) -> v == null ? total : v + total);
        }
        List<Student> students = new ArrayList<>();

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            int price = 10;
            Integer value = entry.getValue() - 100;

            if (value > 0) {
                price += (value / 50) * 3;
                price += (value % 50) != 0 ? 3 : 0;
            }
            students.add(new Student(entry.getKey(), price));
        }

        Collections.sort(students);
        for (Student student : students) {
            System.out.println(student.name + " " + student.price);
        }
    }
}
