import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Team {
        int teamId;
        int lastSubmit;
        int point;
        int count;

        Team(int teamId) {
            this.teamId = teamId;
            this.lastSubmit = 100001;
            this.point = 0;
            this.count = 0;
        }

        void changeLastSubmit(int lastSubmit) {
            this.lastSubmit = lastSubmit;
        }

        void plusPoint(int point) {
            this.point += point;
        }

        void increaseCount() {
            this.count++;
        }

        public int compareTo(Team other) {
            if (this.point == other.point) {
                if (this.count == other.count) {
                    return this.lastSubmit - other.lastSubmit;
                }
                return this.count - other.count;
            }
            return other.point - this.point;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int teamId = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            int[][] problems = new int[n + 1][k + 1];
            List<Team> teams = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                teams.add(new Team(i));
            }
            teams.get(0).plusPoint(-1000);

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int id = Integer.parseInt(st.nextToken());
                int num = Integer.parseInt(st.nextToken());
                int point = Integer.parseInt(st.nextToken());

                int prev = problems[id][num];
                teams.get(id).increaseCount();
                teams.get(id).changeLastSubmit(i);

                if (prev >= point) continue;

                problems[id][num] = point;
                teams.get(id).plusPoint(point - prev);
            }
            teams.sort(Team::compareTo);
            for (int i = 0; i < n; i++) {
                if (teams.get(i).teamId != teamId) continue;

                System.out.println(i + 1);
                break;
            }
        }
    }
}
