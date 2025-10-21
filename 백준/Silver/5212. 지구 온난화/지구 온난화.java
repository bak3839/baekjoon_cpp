import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        char[][] map = new char[R + 2][C + 2];
        boolean[][] isSea = new boolean[R + 2][C + 2];
        int[][] mv = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        List<Integer> row = new ArrayList<>();
        List<Integer> col = new ArrayList<>();

        for (int i = 0; i <= R + 1; i++) {
            Arrays.fill(map[i], '.');
            Arrays.fill(isSea[i], true);
        }

        for (int i = 1; i <= R; i++) {
            String input = br.readLine();
            for (int j = 1; j <= C; j++) {
                map[i][j] = input.charAt(j - 1);
                if (map[i][j] == 'X') {
                    isSea[i][j] = false;
                }
            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (isSea[i][j]) continue;

                int count = 0;
                for (int[] m : mv) {
                    int nx = i + m[0];
                    int ny = j + m[1];
                    if (map[nx][ny] == '.') { count++; }
                }

                if (count >= 3) isSea[i][j] = true;
            }
        }

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (isSea[i][j]) continue;

                row.add(i);
                break;
            }
        }

        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= R; j++) {
                if (isSea[j][i]) continue;

                col.add(i);
                break;
            }
        }
        row.sort(Integer::compareTo);
        col.sort(Integer::compareTo);

        for (int i = row.get(0); i <= row.get(row.size() - 1); i++) {
            for (int j = col.get(0); j <= col.get(col.size() - 1); j++) {
                if (isSea[i][j]) System.out.print(".");
                else System.out.print("X");
            }
            System.out.println();
        }
    }
}
