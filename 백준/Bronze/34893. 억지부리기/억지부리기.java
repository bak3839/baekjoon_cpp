import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long U = Long.parseLong(st.nextToken());
        long O = Long.parseLong(st.nextToken());
        long S = Long.parseLong(st.nextToken());

        System.out.println(Math.min(Math.min(U, O), (U + 2 * S) / 3));
    }
}
