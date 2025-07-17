import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] counts = new int[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = N; i <= M; i++) {
            for(char ch : String.valueOf(i).toCharArray()) {
                counts[ch - '0']++;
            }
        }

        Arrays.stream(counts).forEach(count -> System.out.print(count + " "));
    }
}
