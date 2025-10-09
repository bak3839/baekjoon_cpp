import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[][] sudoku = new int[9][9];
    static boolean[][] visitedArea = new boolean[9][10];
    static boolean[][] visitedRow = new boolean[9][10];
    static boolean[][] visitedCol = new boolean[9][10];

    public static boolean search(int startRow, int startCol, int area) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int row = startRow + i, col = startCol + j;
                int num = sudoku[row][col];
                if (visitedArea[area][num] || visitedRow[row][num] || visitedCol[col][num]) return false;
                visitedArea[area][num] = true;
                visitedRow[row][num] = true;
                visitedCol[col][num] = true;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            for (int i = 0; i < 9; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 9; j++) {
                    sudoku[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int area = 0;
            boolean correct = true;
            for (int R = 0; R < 9; R += 3) {
                for (int C = 0; C < 9; C += 3) {
                    if (!search(R, C, area)) {
                        correct = false;
                        break;
                    }
                    area++;
                }
                if (!correct) break;
            }

            if (correct) System.out.println("Case " + t + ": CORRECT");
            else System.out.println("Case " + t + ": INCORRECT");
            if (t != T) {
                String space = br.readLine();
                for (int i = 0; i < 9; i++) {
                    Arrays.fill(visitedArea[i], false);
                    Arrays.fill(visitedRow[i], false);
                    Arrays.fill(visitedCol[i], false);
                }
            }
        }
    }
}
