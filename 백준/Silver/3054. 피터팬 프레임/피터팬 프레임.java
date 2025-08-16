import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String s1 = "..#..";
        String s2 = ".#.#.";
        String s3 = "#.?.#";
        String[] s = {s1, s2, s3, s2};

        String word = br.readLine();
        char[][] frame = new char[5][word.length() * 4 + 1];

        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);

            for (int y = (i * 4); y <= (i * 4) + 4; y++) {
                for (int x = 0; x < 5; x++) {
                    char now = s[y % 4].charAt(x);

                    if (now == '?') frame[x][y] = ch;
                    else if ((i + 1) % 3 == 0 && now == '#') frame[x][y] = '*';
                    else if (frame[x][y] != '*') frame[x][y] = now;
                }
            }
        }

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < word.length() * 4 + 1; y++) {
                System.out.print(frame[x][y]);
            }
            System.out.println();
        }
    }
}
