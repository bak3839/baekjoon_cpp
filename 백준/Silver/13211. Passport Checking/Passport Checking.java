import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashSet<String> passports = new HashSet<>();

        for (int i = 0; i < N; i++) {
            passports.add(br.readLine());
        }

        int ans = 0;
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            if (passports.contains(br.readLine())) ans++;
        }

        System.out.println(ans);
    }
}
