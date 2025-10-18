import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int number = 1;
        while(true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0) break;

            String[] songs = new String[N];
            for (int i = 0; i < N; i++) {
                songs[i] = br.readLine();
            }
            Arrays.sort(songs);
            System.out.println(number++);
            Arrays.stream(songs).forEach(System.out::println);
        }
    }
}
