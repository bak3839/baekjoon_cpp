import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, ans;
    //static int[][] board;

    public static void copyOfArray(int[][] arr, int[][] temp) {
        for(int i = 0; i < N; i++) {
            System.arraycopy(arr[i], 0, temp[i], 0, N);
        }
    }

    public static void moveUp(int[][] temp) {
        // 상
        for(int j = 0; j < N; j++) {
            int end = 0;
            for(int i = 1; i < N; i++) {
                int index = i, n = temp[i][j];

                while(index > end) {
                    if(temp[index - 1][j] == 0) {
                        temp[index - 1][j] += n;
                        temp[index][j] = 0;
                    }

                    else if(temp[index - 1][j] != n) break;

                    else if(temp[index][j] == n) {
                        temp[index - 1][j] += n;
                        temp[index][j] = 0;
                        end = index;
                        break;
                    }

                    index--;
                }
            }
        }
    }

    public static void moveDown(int[][] temp) {
        // 하
        for(int j = 0; j < N; j++) {
            int end = N - 1;

            for(int i = N - 2; i >= 0; i--) {
                int index = i, n = temp[i][j];

                while(index < end) {
                    if(temp[index + 1][j] == 0) {
                        temp[index + 1][j] += n;
                        temp[index][j] = 0;
                    }

                    else if(temp[index + 1][j] != n) break;

                    else if(temp[index + 1][j] == n) {
                        temp[index + 1][j] += n;
                        temp[index][j] = 0;
                        end = index;
                        break;
                    }

                    index++;
                }
            }
        }
    }

    public static void moveRight(int[][] temp) {
        // 우
        for(int i = 0; i < N; i++) {
            int end = N - 1;

            for(int j = N - 2; j >= 0; j--) {
                int index = j, n = temp[i][j];

                while(index < end) {
                    if(temp[i][index + 1] == 0) {
                        temp[i][index + 1] += n;
                        temp[i][index] = 0;
                    }

                    else if(temp[i][index + 1] != n) break;

                    else if(temp[i][index + 1] == n) {
                        temp[i][index + 1] += n;
                        temp[i][index] = 0;
                        end = index;
                        break;
                    }

                    index++;
                }
            }
        }
    }

    public static void moveLeft(int[][] temp) {
        // 좌
        for(int i = 0; i < N; i++) {
            int end = 0;

            for(int j = 1; j < N; j++) {
                int index = j, n = temp[i][j];

                while(index > end) {
                    if(temp[i][index - 1] == 0) {
                        temp[i][index - 1] += n;
                        temp[i][index] = 0;
                    }

                    else if(temp[i][index - 1] != n) break;

                    else if(temp[i][index - 1] == n) {
                        temp[i][index - 1] += n;
                        temp[i][index] = 0;
                        end = index;
                        break;
                    }

                    index--;
                }
            }
        }
    }

    public static void findMaxBlock(int[][] temp) {
        for(int i = 0; i < N; i++) {
            int res = Arrays.stream(temp[i]).max().getAsInt();
            ans = Math.max(ans, res);
        }
    }

    public static void search(int[][] arr, int cnt) {
        if(cnt == 5) {
            findMaxBlock(arr);
            return;
        }

        int[][] temp = new int[N][N];

        for(int i = 0; i < 4; i++) {
            copyOfArray(arr, temp);

            if(i == 0) moveUp(temp);
            else if(i == 1) moveDown(temp);
            else if(i == 2) moveLeft(temp);
            else moveRight(temp);

            search(temp, cnt + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int[][] board = new int[N][N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        search(board, 0);
        System.out.println(ans);
    }
}
