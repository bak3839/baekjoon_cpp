import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static class Student {
        int num;
        int v, p, s;

        public Student(int num, int v, int p, int s) {
            this.num = num;
            this.v = v;
            this.p = p;
            this.s = s;
        }

        public int sum() {
            return v + p + s;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Student leader = null;
        List<Integer> ans = new ArrayList<>();
        List<Student> students = new ArrayList<>();
        ans.add(0);

        for (int i = 0; i < N + 1; i++) {
            st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int S = Integer.parseInt(st.nextToken());

            if (i == 0) {
                leader = new Student(i, V, P, S);
            } else {
                students.add(new Student(i, V, P, S));
            }
        }

        students.sort((o1, o2) -> o2.sum() - o1.sum());
        for (Student student : students) {
            if (ans.size() >= M) break;
            if (leader.sum() < student.sum()) continue;

            ans.add(student.num);
        }

        ans.forEach(n -> System.out.print(n + " "));
    }
}
