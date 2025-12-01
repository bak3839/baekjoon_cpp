import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Member {
        String name;
        int point;

        public Member(String name, int point) {
            this.name = name;
            this.point = point;
        }

        public int compareTo(Member o) {
            if (this.point == o.point) return this.name.compareTo(o.name);
            return o.point - this.point;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<Member> members = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            int point = Integer.parseInt(st.nextToken());
            members.add(new Member(name, point));
        }

        members.sort(Member::compareTo);
        System.out.println(members.get(0).name);
    }
}
